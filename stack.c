/*
* Add NetID and names of all project partners
*
* Pavitra Patel - php51
* Kush Patel - kp1085
* CS 416
* ilab2
*
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/* Part 1 - Step 1 and 2: Do your tricks here
 * Your goal must be to change the stack frame of caller (main function)
 * such that you get to the line after "r2 = *( (int *) 0 )"
 */
void signal_handle(int signalno) {

    printf("handling segmentation fault!\n");

    /* Step 2: Handle segfault and change the stack*/
    int *add = &signalno;
    //printf("Address of signalno: %p\n", add);

    add = (int *)((char *)add + 60);
    //printf("Address with offset: %p\n", add);

    //read value at address add
    //printf("%x\n", *add);

    *add += 5;
    //printf("%x\n", *add);
}

int main(int argc, char *argv[]) {

    int r2 = 0;

    /* Step 1: Register signal handler first*/
    signal(SIGSEGV, signal_handle);

    r2 = *( (int *) 0 ); // This will generate segmentation fault

    r2 = r2 + 1 * 30;
    printf("result after handling seg fault %d!\n", r2);

    return 0;
}
