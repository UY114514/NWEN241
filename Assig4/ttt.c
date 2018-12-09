/**
 * NWEN 241 Programming Assignment 4
 * ttt.c C Source File
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"

/* Switch between player A and B */
#define switch_player(p)    (((p)=='A') ? 'B' : 'A')

/* Switch between mark X and O */
#define switch_mark(m)    (((m)=='X') ? 'O' : 'X')

/**
 * Draw top and bottom border of game field 
 * @param size Number or rows/columns
 */
static void draw_border(int size) 
{
    int i;
    printf("   ");
    for(i = 0; i < size; i++) {
        printf("+---");
    }
    printf("+\n");
}

/**
 * Draw spaces for game field for a particular row
 * @param size Number or rows/columns
 * @param field Tic-tac-toe board
 * @param row Row to draw
 */
static void draw_row(int size, const char field[][size], int row) 
{
    int i;
    for(i = 0; i < size; i++)
        printf("| %c ", field[row][i]);

    printf("|\n");
}

/**
 * Assign and print row numbers one by one
 * @param size Number or rows/columns
 * @param row Current row number
 */
static void label_vpos(int size, int row) 
{
    printf("%2d ", size-row);
}

/**
 * Assign column numbers all at once 
 * @param size Number or rows/columns
 */
static void label_hpos(int size) 
{
    int i = 1;
    printf("   ");
    while(i < size+1) {
        printf(" %2d ", i); //print underneath field
        i++;
    }
}

/**
 * Draw out the entire game field 
 * @param size Number or rows/columns
 * @param field Tic-tac-toe board
 */
static void draw(int size, const char field[][size]) 
{
    printf("\n");
    for(int i = 0; i < size; i++) {
        draw_border(size);
        label_vpos(size, i);
        draw_row(size, field, i);
    }
    draw_border(size);
    label_hpos(size);
    printf("\n");
}

/** 
 * From a single mark on the board, check if it is part of a chain of 3.  
 */
int check_three_in_a_row(char mark, int down, int across, int size, const char field[][size]) 
{
    int tooCloseForDiagRight = 1;

    if(across < size-2) { //valid conditions for across check?
        tooCloseForDiagRight = 0;
        if(field[down][across+1] == mark && field[down][across+2] == mark)  //check across for win
            return 1;
    }
    if(down < size-2) { //valid conditions for down check?
        tooCloseForDiagRight = 0;
        if(field[down+1][across] == mark && field[down+2][across] == mark) //check down for win
            return 1;
    } else {
        tooCloseForDiagRight = 1; //if we entered horiz check but not this one
    }
    if(!tooCloseForDiagRight) { //if we entered both conditions above, we have enough space to bother to check for diagonal (southeast) win
        if(field[down+1][across+1] == mark && field[down+2][across+2] == mark) //check down for win
            return 1;
    }
    if(down < size-2 && across-2 >= 0) { //diagonal(southwest) check. Will catch antidiagonal cases
        if(field[down+1][across-1] == mark && field[down+2][across-2] == mark)
            return 1;
    }
    return 0;
}

/** 
 * Check if a player has won 
 * @param size Number or rows/columns
 * @param field Tic-tac-toe board
 * @return 1 if already solved, 0 otherwise
 */
int is_solved(int size, const char field[][size]) {
    int i;

    for(i = 0; i < size; i++) {
        int j;
        for(j = 0; j < size; j++) {
            if(field[i][j] != ' ' ) {
                if(check_three_in_a_row(field[i][j], i, j, size, field))
                    return 1;
            }
        }
    }
    return 0;
}

/**
 * Add X or O according to player's move
 * @param size Number or rows/columns
 * @param field Tic-tac-toe board
 * @param player Player mark to use
 * @param x Row number
 * @param y Column number
 * @return 1 if mark is added, 0 otherwise
 */ 
int add_cross(int size, char field[][size], char player, int x, int y)
{
    if(field[size-x][y-1] != ' ') {
        printf("Position is not empty.\n");
        return 0;
    } else if(x < 0 || x > size || y < 0 || y > size) {  
        printf("No such position!\n");
        return 0;
    } 

    field[size-x][y-1] = player;
    
    return 1;
}

/**
 * Initialize game field.
 * @param size Number or rows/columns
 * @param field Tic-tac-toe board
 */ 
static void init_field(int size, char field[][size])
{
    for(int i=0; i<size; i++) 
        for(int j=0; j<size; j++) 
            field[i][j] = ' ';
}

/**
 * Run the tic-tac-toe game.
 */
void ttt_run(void)
{
    int size = 0;
    char line[100];
    
    while(size < 3 || size > 64) {
        printf("\nEnter size between 3-64: ");
        fgets(line, 100, stdin);
        size = is_number(line) ? atoi(line) : 0;
    }

    char field[size][size]; 
    init_field(size, field);

    char player = 'A'; //alternate between 2 players
    char mark = 'X';   //alternate btwn 2 marks

    draw(size, field); 
    
    while(!is_solved(size, field)) {

        printf("Player %c's turn: \n", player);
        int x = force_integer_input("-> Enter X (row): ", NULL, 1, size);
        int y = force_integer_input("-> Enter Y (col): ", NULL, 1, size);        
        int added = add_cross(size, field, mark, x, y);
        if(added == 1) {
            printf("Drew %c at: (%d, %d)\n", mark, x, y);
            player = switch_player(player);
            mark = switch_mark(mark);
        }
        
        draw(size, field); 
    }

    printf("\nPlayer %c won!\n", switch_player(player));    
}

#ifdef FORK_EXEC_IMPL

int main(void) 
{
    ttt_run();
    
    return 0;
}

#endif /* FORK_EXEC_IMPL */
