/**
 * NWEN 241 Programming Assignment 4
 * common.h Header File
 */

#ifndef __UTIL_H__
#define __UTIL_H__

#define TRUE  1
#define FALSE 0

/* Command to run the guessing game */
#define CMD_GUESS   "guess"

/* Command to run the tic-tac-toe game */
#define CMD_TICTACTOE   "ttt"

/**
 * Check if inputted line consists of digits
 * @param str String
 * @return TRUE if str consists of digts, FALSE otherwise
 */ 
int is_number(char *str);

/**
 * Force user to input integer and perform necessary validation
 * @param prompt String to prompt user
 * @param err_msg String to display in case of validation failure.
 *        If NULL, no error message will be displayed when validation
 *        fails.
 * @param min Minimum required
 * @param max Maximum required
 * @return The integer input
 */ 
int force_integer_input(char *prompt, char *err_msg, int min, int max);

/**
 * Force user to input a character and perform necessary validation
 * @param prompt String to prompt user
 * @param err_msg String to display in case of validation failure.
 *        If NULL, no error message will be displayed when validation
 *        fails.
 * @param valid_chars Array of valid characters
 * @param len Length of valid_chars array
 * @return The character input
 */
char force_char_input(char *prompt, char *err_msg, char *valid_chars, int len);

/**
 * Run the guessing game
 * This function will invoke the guessing game.
 */
void guess_run(void);

/**
 * Run the tic-tac-toe game
 * This function will invoke the guessing game.
 */ 
void ttt_run(void);

#endif /* __UTIL_H__ */
