@Lingfei Lu      A91046735
@Junxi Li        A91105747
.syntax unified

.text

.align 8
.global createlist_ARM
.func createlist_ARM, createlist_ARM
.type createlist_ARM, %function

createlist_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (int maxElements is in r0)
    
    @check if maxElement < 1
    cmp r0, #1
    
    @skip next line if r0 >= 1
    bge next
    
    @r0 = 10
    mov r0, #10
    
    
    
    @ r4 = maxSize = maxElement
    next:mov r4, r0;
    
    @r0 = 12 which is the size of struct list
    mov r0, #12;
    
    @r0 = malloc (sizeof(list))
    bl malloc
    
    @check if malloc sucessfully
    cmp r0, #0;
    
    @if malloc fails, return immediately
    beq end
    
    @move r0 into r5, now r0 can be malloced again
    @and r5 is the new list struct
    mov r5, r0;
    
    @ r0 = maxSize*4
    lsl r0, r4, #2
    
    @malloc r0 = maxSize*4
    bl malloc
    
    @check if malloc successfully
    cmp r0, #0;
    
    @if malloc fails, return immediately
    beq end
    
    @ list->sortedlist = r0 = maxSize*4
    str r0, [r5];
    
    @r6 = sortedlist
    mov r6, r0;
    
    @size = 0
    mov r7, #0;
    
    @list->size = r7
    str r7, [r5, #4];
   
    
    @list->maxSize = r4, which is maxSize
    str r4, [r5, #8];
    
    @assign struct list from r5 back to r0 to return
    mov r0, r5;

    end:

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

