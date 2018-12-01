/**
 * NWEN 241 Programming Assignment 3
 * kgame.c C Source File
 *
 * Name:
 * Student ID:
 * 
 * IMPORTANT: Implement the functions specified in kgame.h here. 
 * You are free to implement additional functions that are not specified in kgame.h here.
 */
#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include "kgame.h"
#include <string.h>

#if defined _MSC_VER
char *clear = "cls";
#elif defined __GNUC__
char *clear = "clear";
#endif




void kgame_init(kgame_t *game) {
    if (!game) return;

    for (int i = 0; i < KGAME_SIDES; i++)
        for (int j = 0; j < KGAME_SIDES; j++)
            game->board[i][j] = ' ';
    game->score = 0;
}

void kgame_add_random_tile(kgame_t *game) {
    int row, col;

    if (!game) return;

    // find random, but empty tile
    // FIXME: will go to infinite loop if no empty tile
    do {
        row = rand() % 4;
        col = rand() % 4;
    } while (game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    game->board[row][col] = 'A' + (rand() % 2);

}


void kgame_render(char *output_buffer, const kgame_t *game) //render a 4*4 grid
{
    system(clear);
    memset(output_buffer, 0, sizeof(*output_buffer));//clear buffer

    static char LINE[] = "\n+---+---+---+---+\n";
    static char WARP[] = "|";
    char        str1[] = "|   ";

    for (int row = 0; row < KGAME_SIDES; ++row) {
        strcat(output_buffer, LINE);
        for (int col = 0; col < KGAME_SIDES; ++col) {
            str1[2] = game->board[row][col];
            strcat(output_buffer, str1);
        }
        strcat(output_buffer, WARP);
    }
    strcat(output_buffer, LINE);//add the bottom edge
}


bool kgame_is_won(const kgame_t *game) {
    // FIXME: Implement correctly (task 2)
    for (int row = 0; row < KGAME_SIDES; ++row) { //traverse the board to find K
        for (int col = 0; col < KGAME_SIDES; ++col) {
            if (game->board[row][col == 'K']) {
                return true;
            }
        }
    }
    return false;
}

bool board_can_move(const kgame_t *game, int direction) {//TODO
    switch (direction) {
        case UP:
            return true;
        case DOWN:
            return true;
        case LEFT:
            return true;
        case RIGHT:
            return true;
    }
}

bool kgame_is_move_possible(const kgame_t *game) {
    // FIXME: Implement correctly (task 3)

    for (int row = 0; row < KGAME_SIDES; ++row) { //traverse the board to find empty spaces
        for (int col = 0; col < KGAME_SIDES; ++col) {
            if (game->board[row][col] == ' ') {
                return false;                     // at least one empty field
            }
        }
    }

    /*
     * Traverse the board to find same characters
     * located either vertically or horizontally
     * in the grid.
     */


    for (int row = 0; row < KGAME_SIDES - 1; ++row) {  //vertically
        for (int col = 0; col < KGAME_SIDES; ++col) {
            if (game->board[row][col] == game->board[row + 1][col]) {
                return false;
            }
        }
    }
    for (int row = 0; row < KGAME_SIDES; ++row) {  //horizontally
        for (int col = 0; col < KGAME_SIDES - 1; ++col) {
            if (game->board[row][col] == game->board[row][col + 1]) {
                return false;
            }
        }
    }


    return true;
}


void move_down(kgame_t *game) {
    for (int count = 0; count <= KGAME_SIDES; count++) {
        if (count == 1) {//move tiles first then add'em up
            for (int row = KGAME_SIDES - 1; row > 0; row--) {//add tiles
                for (int col = KGAME_SIDES - 1; col >= 0; col--) {
                    if (game->board[row][col] != ' ' && game->board[row][col] == game->board[row - 1][col]) {
                        game->board[row][col]     = ++game->board[row][col];
                        game->board[row - 1][col] = ' ';
                    }
                }
            }
        } else {
            for (int i = 0; i < 5; i++) {//move tiles
                for (int row = KGAME_SIDES - 1; row > 0; row--) {
                    for (int col = KGAME_SIDES - 1; col >= 0; col--) {
                        if (game->board[row][col] == ' ') {
                            game->board[row][col]     = game->board[row - 1][col];
                            game->board[row - 1][col] = ' ';
                        }
                    }
                }
            }
        }
    }
}

void move_up(kgame_t *game) {
    for (int count = 0; count <= KGAME_SIDES; count++) {
        if (count == 1) {//move tile first then add'em up
            for (int row = 0; row < KGAME_SIDES - 1; row++) {//add things up
                for (int col = 0; col <= KGAME_SIDES - 1; col++) {
                    if (game->board[row][col] != ' ' && game->board[row][col] == game->board[row + 1][col]) {
                        game->board[row][col]     = ++game->board[row][col];
                        game->board[row + 1][col] = ' ';
                    }
                }
            }
        } else {
            for (int i = 0; i < 5; i++) {
                for (int row = 0; row < KGAME_SIDES - 1; row++) {
                    for (int col = 0; col <= KGAME_SIDES - 1; col++) {
                        if (game->board[row][col] == ' ') {
                            game->board[row][col]     = game->board[row + 1][col];
                            game->board[row + 1][col] = ' ';
                        }
                    }
                }
            }
        }
    }
}


void move_left(kgame_t *game) {
    for (int count = 0; count <= KGAME_SIDES; count++) {
        if (count == 1) {
            for (int row = 0; row < KGAME_SIDES; row++) {
                for (int col = 0; col < KGAME_SIDES - 1; col++) {
                    if (game->board[row][col] != ' ' && game->board[row][col] == game->board[row][col + 1]) {
                        game->board[row][col]     = ++game->board[row][col];
                        game->board[row][col + 1] = ' ';
                    }
                }
            }
        } else {
            for (int row = 0; row < KGAME_SIDES; row++) {//move tiles
                for (int col = 0; col < (KGAME_SIDES - 1); col++) {
                    if (game->board[row][col] == ' ') {
                        game->board[row][col]     = game->board[row][col + 1];
                        game->board[row][col + 1] = ' ';
                    }
                }
            }
        }
    }


}

void move_right(kgame_t *game) {
    for (int count = 0; count <= KGAME_SIDES; count++) {
        if (count == 1) {
            for (int row = KGAME_SIDES - 1; row >= 0; row--) {
                for (int col = KGAME_SIDES - 1; col > 0; col--) {
                    if (game->board[row][col] != ' ' && game->board[row][col] == game->board[row][col - 1]) {
                        game->board[row][col]     = ++game->board[row][col - 1];
                        game->board[row][col - 1] = ' ';
                    }
                }
            }
        } else {
            for (int row = KGAME_SIDES - 1; row >= 0; row--) {//move tiles
                for (int col = KGAME_SIDES - 1; col > 0; col--) {
                    if (game->board[row][col] == ' ') {
                        game->board[row][col]     = game->board[row][col - 1];
                        game->board[row][col - 1] = ' ';
                    }
                }
            }
        }
    }

}

bool kgame_update(kgame_t *game,
                  dir_t direction) {//direction = 1,2,3,4 : typedef enum direction { UP = 1, DOWN, LEFT, RIGHT } dir_t;
    // FIXME: Implement correctly (task 4)
    if (board_can_move(game, direction)) {
        switch (direction) {
            case UP:
                move_up(game);
                break;
            case DOWN:
                move_down(game);
                break;
            case LEFT:
                move_left(game);
                break;
            case RIGHT:
                move_right(game);
                break;
        }
        kgame_add_random_tile(game);
        return true;
    }

    kgame_add_random_tile(game);
    return false;
}


void kgame_save(const kgame_t *game) {
    // FIXME: Implement correctly (task 5)
}


bool kgame_load(kgame_t *game) {
    // FIXME: Implement correctly (task 6)
    return false;
}


