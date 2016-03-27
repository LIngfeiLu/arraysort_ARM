@Lingfei Lu      A91046735
@Junxi Li        A91105747
.syntax unified

.text

.align 8
.global remove_val_ARM
.func remove_val_ARM, remove_val_ARM
.type remove_val_ARM, %function

remove_val_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0, int val is in r1)
    
    @r4 = struct ls
    mov r4, r0
    
    @r5 = val
    mov r5, r1
    
    @r6 = sortedlist
    ldr r6, [r4]
    
    @r7 = size
    ldr r7, [r4, #4]
    
    @r3 = i = 0
    mov r3, #0 @i = 0
    
    @ls == null
    cmp r0, #0
    
    @branch to return -1
    beq return1
    
    @ls->size == 0
    cmp r7, #0
    
    @branch to return 0
    beq return0
    
    @r0= size - 1
    sub r0, r7, #1
    
    @r0 = 4*r0
    lsl r0, r0, #2
    
    @r1 = sortedlist[ls->size-1]
    ldr r1, [r6, r0]
    
    @val > ls->sordedlist[ls->size-1]
    cmp r5, r1
   
    @branch to return 0
    bgt return0
    
    @ls->size == 1
    cmp r7, #1
    
    @branch to first while loop
    bne while1
    
    @r1 = sortedlist[0]
    ldr r1, [r6]
    
    @sotedlist[0] == val
    cmp r1, r5
    
    @branch to return 0
    bne return0
    
    @r0 = 0
    mov r0, #0
    
    @sortedslit[0] = 0
    str r0, [r6]
    
    @ls->sortedlist = sortedlist = r6
    str r6, [r4]
    
    @size = size -1
    sub r7, r7, #1
    
    @ls->size = size
    str r7, [r4, #4]
    
    @ branch to return 1
    b return2
    
    @first while loop
    while1:
    
    @r0 = 4*i
    lsl r0, r3, #2
    
    @r0 = sortedlist[i]
    ldr r0, [r6, r0]
    
    @sortedlist[i] == val
    cmp r0, r5
    
    @branch to next 
    beq next
    
    @i++
    add r3, r3, #1
    
    @i == size
    cmp r3, r7
    
    @branch to return 0
    beq return0
    
    @branch back to begining of while loop
    b while1
    
    
    next:
    @j = r1 = i
    mov r1, r3 
    
    @second while loop
    while2:
    
    @r0 = 4*j
    lsl r0, r1, #2
    
    @r0 = sortedlist[j]
    ldr r0, [r6, r0]
    
    @sortedlist[j] = val
    cmp r0, r5
    
    @branch to before the first for loop
    bne beforefor
    
    @j = j+1
    add r1, r1, #1
    
    @branch back
    b while2
    
    
    @before the first for loop
    beforefor:
    
    @ k = r8 = i
    mov r8, r3
    
    @ first for loop
    for1:
    
    @r0 = j - i
    sub r0, r1, r3
    
    @r0 = size - (j-i)
    sub r0, r7, r0
    
    @k < size-(j-i)
    cmp r8, r0
    
    @branch to before second for loop
    bge beforefor2
    
    @r0 = k+j
    add r0, r8, r1
    
    @r0 = k+j-i
    sub r0, r0, r3
    
    @k+j-i < size
    cmp r0, r7
    
    @branch to before the second for loop
    bge beforefor2
    
    @r0 = 4*(k+j-i)
    lsl r0, r0, #2
    
    @r0 = sortedlist[k+j-i]
    ldr r0, [r6, r0]
    
    @r2 = 4*k
    lsl r2, r8, #2
    
    @sortedlist[k] = sortedlist[k+j-i]
    str r0, [r6, r2]
    
    @k++
    add r8, r8, #1
    
    @ls->sortedlist = sortedlist
    str r6, [r4]
    
    @branch back to begining of for loop
    b for1    
    
    @before the second for loop
    beforefor2:
    
    @r9 = m= 1
    mov r9, #1
    
    @r11 = j-i
    sub r11, r1, r3
    
    @second for loop
    for2:
    
    @ m <= j-i
    cmp r9, r11
    
    @branch to next2
    bgt next2
    
    @r0 = size-m
    sub r0, r7, r9
    
    @r0 = 4*(size-m)
    lsl r0, r0, #2
    
    @r10 = 0
    mov r10, #0
    
    @sortedlist[size-m] = 0
    str r10, [r6, r0]
    
    @m++
    add r9, r9, #1
    
    @branch back to for2
    b for2
    
    
    
    next2:
    @r0 = j-i
    sub r0, r1, r3
    
    @size = size-(j-i)
    sub r7, r7, r0
    
    @ls->size = size
    str r7, [r4, #4]
    
    @ls->sortedlist = sortedlist
    str r6, [r4]
    
    @r0 = j-i
    sub r0, r1, r3
    
    @branch to end
    b end

    @ put your return value in r0 here:
    return0: mov r0, #0
    b end
    return1: mov r0, #-1
    b end
    return2: mov r0, #1
    b end
    
    
    end:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

