@Lingfei Lu      A91046735
@Junxi Li        A91105747
.syntax unified

.text

.align 8
.global get_max_ARM
.func get_max_ARM, get_max_ARM
.type get_max_ARM, %function

get_max_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0)
    
    @ compare value in r0 which is *ls and int zero
    cmp r0, #0;
    
    @branch to label return if r0 equals 0
    beq return;
    
    @load ls->size to r1
    ldr r1, [r0, #4];
    
    @compare if r1 and int zero
    cmp r1, #0;
    
    @branch to label zero if r1 and 0 are equal
    beq return;
    
    @load ls->sortedlist to r2
    ldr r2, [r0];
    
    @ r3 is the index of the last element of sortedlist
    sub r3, r1, #1;
    
    @shift left 2 bits, aka multiply the r3 by 4.
    lsl r3, r3, #2;
    
    @store the value of the last element of sortedlist back to r0
    ldr r0, [r2, r3];
    
    @branch to label end unconditionally
    b end;
    
    @ put your return value in r0 here:
    @return -1
    return:mov r0, #-1;
    
    end:

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

