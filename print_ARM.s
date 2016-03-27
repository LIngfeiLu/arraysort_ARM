@Lingfei Lu      A91046735
@Junxi Li        A91105747
.syntax unified
.data

string1: .asciz "%d "
string2: .asciz "\n"
.text

.align 8
.global print_ARM
.func print_ARM, print_ARM
.type print_ARM, %function




print_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    
    @ YOUR CODE GOES HERE (list *ls is in r0)
    @-----------------------
    
    @r7 = i
    mov r7, #0
    
    @r4 = ls
    mov r4, r0
    
    @r5 = sortedlist
    ldr r5, [r4]
    
    @r6 = size
    ldr r6, [r4, #4]
    
    @for loop
    for: cmp r7, r6
    
    @branch to end
    bge end
    
    @r0 = "%d "
    ldr r0, =string1
    
    @r8 = 4*i
    lsl r8, r7, #2
    
    @r1 = sortedlist[i]
    ldr r1, [r5, r8]
    
    @printf
    bl printf
    
    @i++
    add r7, r7, #1
    
    @branch back
    bl for
    
    end:ldr r0, =string2
    bl printf


    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

