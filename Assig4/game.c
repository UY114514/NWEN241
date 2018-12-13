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

#if defined(FORK_IMPL)
/*====== Fork Only Implementation Start ======*/
/**
 * Fork Only Implementation Block
 * Write all code related to the fork only implementation within this block
 */

int main(void)
{
    int pid = 1;
    int input = 0;
    // FIXME: Implement Task 3 here
    // printf("PID=%i\n", getpid());
    if (getpid() < 0)
    { //fork failed
        fprintf(stderr, "%s\n", "Fork failed");
        return -1;
    }

    printf("PID=%i\n", getpid());
    printf("(1) Guessing Game\n(2) Tic-Tac-Toe \n(3) Exit\n");
    printf("-> ENTER YOUR CHOICE: ");
    scanf("%i", &input);
    switch (input)
    {
    case 1:
        pid = fork();
        break;
    case 2:
        pid = fork();
        break;
    case 3:
        return 0;
    }
    wait();

    if (pid == 0)
    {
        switch (input)
        {
        case 1:
            guess_run();
            break;
        case 2:
            ttt_run();
            break;
        }
    }

    // printf("PID=%i", getpid());
    // if (getpid() < 0)
    // { //fork failed
    //     fprintf(stderr, "%s\n", "Fork failed");
    //     return -1;
    // }
    // else if (getpid() != 0)
    // {
    //     printf("\nnot 0\n");
    // }
    // if (getpid() == 0)
    // { //child
    //     printf("\nis 0\n");
    //     switch (input)
    //     {
    //     case 1:
    //         guess_run();
    //     case 2:
    //         ttt_run();
    //     case 3:
    //         return 0;
    //     }
    // }
}

/*====== Fork Only Implementation End ======*/

//#elif defined(FORK_EXEC_IMPL)
#elif defined(FORK_EXEC_IMPL)
/*====== Fork + Exec Implementation Start ======*/
/**
 * Fork + Exec Implementation Block
 * Write all code related to the fork + exec implementation within this block
 */

int main(void)
{
    // FIXME: Implement Task 4 here
    printf("FORK_EXEC_IMPL\n");
    return 0;
}

/*====== Fork + Exec Implementation End ======*/

#else
/*====== No Implementation Start ======*/
/**
 * No Implementation Block
 * Do not write anything in this block
 */
//#error "Did not specify implementation to compile."

/*====== No Implementation End ======*/
#endif
