@Lingfei Lu      A91046735
@Junxi Li        A91105747
.syntax unified

.text

.align 8
.global get_min_ARM
.func get_min_ARM, get_min_ARM
.type get_min_ARM, %function

get_min_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    
    @ YOUR CODE GOES HERE (list *ls is in r0)
    
    @ compare r0 and int zero
    cmp r0, #0;
    
    @branch to label return if r0 equals 0
    beq return;
    
    @load ls->size to r2
    ldr r2, [r0, #4];
    
    @compare r2 and in zero
    cmp r2, #0;
    
    @branch to label return 
    beq return;
    
    @load ls->sortedlist to r1
    ldr r1, [r0];
    
    @store the first element of sortedlist in r0 for return
    ldr r0, [r1];
    
    @branch to label end unconditionally
    b end;
    
    @ put your return value in r0 here:
    @return -1
    return: mov r0, #-1;

    end:

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

