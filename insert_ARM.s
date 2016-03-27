@Lingfei Lu      A91046735
@Junxi Li        A91105747
.syntax unified

.text

.align 8
.global insert_ARM
.func insert_ARM, insert_ARM
.type insert_ARM, %function

insert_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0, int val in r1)

    @r4 = list= r0
    mov r4, r0

    @r5 = val = r1
    mov r5, r1

    @index = 0
    mov r10, #0
    
    
    @null check if list == null
    cmp r4, #0

    @if equal, immediately return -1
    beq return1
    
    @r7 = ls->size
    ldr r7, [r4, #4]

    @r8 = ls->maxSize
    ldr r8, [r4, #8]

    @r6 = ls->sortedList
    ldr r6, [r4]

    @r9 = ls->size
    mov r9, r7
    
    @compare ls->size and ls->maxSize
    cmp r7, r8

    @if not equal, branch to next
    bne next

    @r0 = ls->sortedList
    mov r0, r6

    @num of bytes r1 = 2 * maxSize * sizeof(int)
    lsl r1, r8, #3

    @realloc
    bl realloc

    @null check if temp = r0 == null
    cmp r0, #0

    @if null, then immediatly return -1
    beq return1

    @move expanded sortedList back to r6, r6 = sortedList
    mov r6, r0

    @ls->sortedList = r6 = realloc
    str r6, [r4]

    @expand maxSize by 2, maxSize *= 2
    lsl r8, r8, #1 

    @ls->maxSize = maxSize = r8
    str r8, [r4, #8]



    next:
    @check if size == 0
    cmp r7, #0

    @if size == 0, jump to the next block, next2
    beq next2

    @r0 = ls->size-1
    sub r0, r7, #1

    @r0 = r0 * 4
    lsl r0, r0, #2

    @r0 = ls->sortedlist[ls->size-1]
    ldr r0, [r6, r0]

    @compare r0 and val = r5
    cmp r5, r0

    @if val < sortedList[ls->size-1], jump to next2 block
    blt next2

    @r0 = r7 * 4, r7 is the size
    lsl r0, r7, #2

    @ls->sortedList[ls->size] = r5 = val
    str r5, [r6, r0]

    @store r6 back to ls, ls->sortedList = r6
    str r6, [r4]
    
    
    
    next2:
    @check if size == 0
    cmp r7, #0

    @if size == 0, jump to next3
    beq next3
    
    while:
    @r0 = r10 * 4, r10 is the index
    lsl r0, r10, #2

    @r1 = ls->sortedList[index]
    ldr r1, [r6, r0]

    @compare r5 = val and r1 = sortedlist[index]
    cmp r5,r1

    @if val <= sortedList[index], branch to for loop
    ble for

    @index++
    add r10, r10, #1

    @branch back
    b while
        
    
    
    @for loop
    for:
    @ i > index
    cmp r9, r10

    @branch to next3 if i <= index
    ble next3
    
    @r1 = i-1
    sub r1, r9, #1

    @r1 = (i-1)*4
    lsl r1, r1, #2

    @r0 = sortedList[i-1]
    ldr r0, [r6, r1]

    @r1 = i*4
    lsl r1, r9, #2

    @ls->sortedlist->sortedlist[i-1]
    str r0, [r6, r1]

    @ls->sortedList = r6
    str r6, [r4]

    @i--
    sub r9, r9, #1

    @branch back
    b for
    
    
    
    next3:
    @r0 = index * 4
    lsl r0, r10, #2

    @sortedList[index] = val = r5
    str r5, [r6, r0]

    @size++
    add r7, r7, #1

    @ls->size = size = r7
    str r7, [r4, #4]

    @ls->sortedlist = sortedlist = r6
    str r6, [r4]
    
    @ put your return value in r0 here:
    return: mov r0, r10

    @branch back
    b end

    @return -1
    return1: mov r0, #-1
    end:
    
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

