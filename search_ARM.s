@Lingfei Lu      A91046735
@Junxi Li        A91105747
.syntax unified

.text

.align 8
.global search_ARM
.func search_ARM, search_ARM
.type search_ARM, %function

search_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0, int val is in r1)

    @ ls == null
    cmp r0, #0
    
    @branch to return -1
    beq return1
    
    @r4 = ls
    mov r4, r0
    
    @r5 = val
    mov r5, r1
    
    @r8 = i = 0
    mov r8, #0
    
    @r7 = ls->size
    ldr r7,[r4, #4]
    
    @r6 = sortedlist
    ldr r6, [r4]
    
    @ i < ls->size
    loop:cmp r8, r7
    
    @branch to return -1
    bge return1
    
    @r1 = 4*i
    lsl r1, r8, #2
    
    @r3 = sortedlist[i]
    ldr r3 ,[r6, r1]
    
    @sortedlist[i] == val
    cmp r3, r5
    
    @branch to return i
    beq return2
    
    @i++
    add r8, r8, #1
    
    @branch back to begining of the for loop
    b loop
    
    
    @ put your return value in r0 here:
    
    @return -1
    return1: mov r0, #-1
    
    b end1
    
    @return i
    return2: mov r0, r8
    
    
	end1:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

