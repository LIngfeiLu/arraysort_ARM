/* Source code for CSE30 HW2 GDB exercise.
 * Taken and modified from Geoff Kuenning's HMC CS105 Debugging assignment.*/
#include <stdio.h>
#include <stdlib.h>

static long long puzzle1 = 0x303320455343;
static char puzzle2[] = {0x43, 0x53, 0x45, 0x20, 0xBD, 0x67, 0x01, 0x00};
static long long puzzle3[] = {0x8000400020001, 0x80004000200010, 0x0800040002000100};

int swapper(int x)
{
    if (x == 42)
        return 47;
    else if (x == 47)
        return 42;
    else
        return x;
}

void fix_array(int *a, int a_size)
{
    int i;

    for (i = 0;  i < a_size;  i++, a++) {
        *a = swapper(*a);
    }
}

int main(int argc, char *argv[])
{
    int *array;
    int i;

    array = (int *)malloc(argc * sizeof(int));
    /* argv[0] is the program name so we skip it */
    for (i = 1;  i < argc;  i++) {
        array[i] = atoi(argv[i]);
    }
    fix_array(array, argc - 1);
    for (i = 1;  i < argc;  i++) {
        printf ("%d ", array[i]);
    }
    printf ("\n");
    return 0;
}
