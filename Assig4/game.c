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
    // FIXME: Implement Task 3 here
    printf("\ntest FORK_IMPL\n");
    return 0;
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

