@Lingfei Lu      A91046735
@Junxi Li        A91105747
.syntax unified

.text

.align 8
.global pop_min_ARM
.func pop_min_ARM, pop_min_ARM
.type pop_min_ARM, %function

pop_min_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0)
    @r4 = struct ls
    mov r4, r0

    @r5 = sortedlist
    ldr r5, [r4]

    @r6 = size
    ldr r6, [r4, #4]

    @r7 = maxSize
    ldr r7, [r4, #8]

    @i = 0
    mov r1, #0

    @pop = ls->sortedlist[0]
    ldr r10, [r5]
    
    @if statement
    @ls == NULL
    cmp r4, #0

    @branch to return
    beq return1

    @ls->size == 0
    cmp r6, #0

    @branch to return
    beq return1
    
    @r2 = size -1
    sub r2, r6, #1

    @for loop
    for:

    @i < ls->size-1
    cmp r1, r2

    @branch to next
    bge next
    
    @r0 = i+1
    add r0, r1, #1

    @r0 = 4*(i+1)
    lsl r0, r0, #2

    @r0 = sortedlist[i+1]
    ldr r0, [r5, r0]
    
    @r3 = i
    lsl r3, r1, #2

    @sortedlist[i] = sortedlist[i+1]
    str r0, [r5, r3]

    @ls->sortedlist = sortedlist
    str r5, [r4]

    @i++
    add r1, r1, #1
    b for
    
    next:
    @sortedlist[size-1] = 0
    mov r1, #0
    lsl r2, r2, #2
    str r1, [r5, r2]
    str r5, [r4]
    
    @ls->size--
    sub r6, r6, #1
    str r6, [r4, #4]
    b return
    
    @return -1
    return1:
    mov r0, #-1

    b end

    @return sortedlist[0]
    return:
    mov r0, r10
    
    end:
    
    
    

    @ put your return value in r0 here:

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

