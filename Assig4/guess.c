/**
 * NWEN 241 Programming Assignment 4
 * guess.c C Source File
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "common.h"

#define MIN_NUMBER   1
#define MAX_NUMBER   100
#define MAX_ATTEMPTS 5

/**
 * Generate a random secret number.
 * @param start Minimum
 * @param end Maximum
 * @return Random number
 */
static int generate_secret(int start, int end) 
{
    return (rand() % end) + start;
}

/** 
 * Determine whether the game was won.
 * @param secret Secret number
 * @param guess Guess
 * @return TRUE if the game is won, FALSE otherwise
 */
static int is_game_won(int secret, int guess) 
{
    return (secret == guess);
}

/**
 * Run the guessing game.
 */ 
void guess_run(void)
{

    int secret, guess;
    char choice;
    int cont = TRUE;

    /* Initialise RNG */
    srand(time(NULL));

    while (cont) {
        int attempts = 0;

        /* Generate random number */    
        secret = generate_secret(MIN_NUMBER, MAX_NUMBER);

        /* Prompt and read user input */
        printf("Guess my number between %d and %d. You have max. %d attempts.\n",
            MIN_NUMBER, MAX_NUMBER, MAX_ATTEMPTS);

        while (attempts < MAX_ATTEMPTS) {

            guess = force_integer_input("Your guess: ", 
                    "Invalid input or out of range, please try again.\n", MIN_NUMBER, MAX_NUMBER);

            /* Compare */
            if (is_game_won(secret, guess)) {
                /* Success; end program */
                printf("Congratulations! You found it!\n");
                break;
            } else {
                printf("Sorry... My number is %s than yours.\n", secret > guess ? "bigger" : "smaller");
                attempts++;
            }
        }

        if (attempts >= MAX_ATTEMPTS) {
            /* Max. attempts reached; end game */
            printf("Game over. My number is %d.\n", secret);
        }

        while (TRUE) {

            choice = force_char_input("Play again? (y/n) ", 
                    "Sorry, didn't quite catch that. Please enter either 'y' or 'n'.\n", 
                    "YyNn", 4);

            if (choice == 'y' || choice == 'Y') {
                break;
            } else if (choice == 'n' || choice == 'N') {
                cont = FALSE;
                printf("See you later!\n");
                break;

            } 
        }
    }  
}

#ifdef FORK_EXEC_IMPL

int main(void)
{
    guess_run();
    
    return 0;
}

#endif /* FORK_EXEC_IMPL */
