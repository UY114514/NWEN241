/**
 * NWEN 241 Programming Assignment 4
 * game.c C Source File
 *
 * Name:Fangyi Yan
 * Student ID:1624092237
 * 
 * IMPORTANT: You are to complete Tasks 1, 3 and 4 here
 */

#include "common.h"
#include <stdio.h>
#include <unistd.h>

#if defined(FORK_IMPL)
/*====== Fork Only Implementation Start ======*/
/**
 * Fork Only Implementation Block
 * Write all code related to the fork only implementation within this block
 */

int main(void) {
    // FIXME: Implement Task 3 here
//    setbuf(stdout, 0);
    while (1) {
        int pid = 1;
        int input = 0;
//        printf("PID=%i\n", getpid());
        printf("(1) Guessing Game\n(2) Tic-Tac-Toe \n(3) Exit\n");
        printf("-> ENTER YOUR CHOICE:");
        scanf("%i", &input);
        switch (input) {
            case 1:
                pid = fork();
                break;
            case 2:
                pid = fork();
                break;
            default:
                printf("Exiting...\n");
                return 0;
        }
        if (pid < 0) { //if fork failed
            fprintf(stderr, "%s\n", "Fork failed");
            return -1;
        }

        if (pid == 0) {
            switch (input) {
                case 1:
                    guess_run();
                    break;
                case 2:
                    ttt_run();
                    break;
            }
        } else {
            wait();
        }
    }


}

/*====== Fork Only Implementation End ======*/

//#elif defined(FORK_EXEC_IMPL)
#elif defined(FORK_EXEC_IMPL)
/*====== Fork + Exec Implementation Start ======*/
/**
 * Fork + Exec Implementation Block
 * Write all code related to the fork + exec implementation within this block
 */

int main(void) {
    // FIXME: Implement Task 4 here
//    printf("FORK_EXEC_IMPL\n");

    while (1) {
        int pid = 1;
        int input = 0;
        printf("(1) Guessing Game\n(2) Tic-Tac-Toe \n(3) Exit\n");
        printf("-> ENTER YOUR CHOICE:");
        scanf("%i", &input);
        switch (input) {
            case 1:
                pid = fork();
                break;
            case 2:
                pid = fork();
                break;
            default:
                printf("Exiting...\n");
                return 0;
        }


        if (pid < 0) { //fork failed
            fprintf(stderr, "%s\n", "Fork failed");
            return -1;
        }

        if (pid == 0) {//for CHILD process
            int exec_return;
            switch (input) {
                case 1:
                    exec_return = execlp("./guess", "./guess", NULL);
                    break;
                case 2:
                    exec_return = execlp("./ttt", "./ttt", NULL);
                    break;
            }
        } else {//for PARENT process
            wait();
        }



    }
    return 0;

}

/*====== Fork + Exec Implementation End ======*/

#else
/*====== No Implementation Start ======*/
/**
 * No Implementation Block
 * Do not write anything in this block
 */
#error "Did not specify implementation to compile."

/*====== No Implementation End ======*/
#endif
