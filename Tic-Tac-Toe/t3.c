//
// Created by UY114514 on 2018/10/10.
//


#include <stdio.h>
#include <stdlib.h>


void draw(int size, const char field[][size]) {
    printf("\n");
    for (int col = size; col > 0; col--) {
        for (int row = 0; row < size + 1; ++row) {
            if (row == 0) {
                printf("  +");
            } else {
                printf("-+");
            }
        }
        printf("\n%d ", col);
        for (int row = 0; row < size + 1; row++) {
            if (row == 0) {
                printf("|");
            } else {
                printf("%c|", field[row][col]);
            }
        }
        printf("\n");


    }
    for (int row = 0; row < size + 1; ++row) {
        if (row == 0) {
            printf("  +");
        } else {
            printf("-+");
        }
    }
    printf("\n");
    for (int row = 1; row < size + 1; ++row) {
        if (row == 1) {
            printf("   %d", row);
        } else {
            printf(" %d", row);
        }
    }
}

int is_solved(int size, const char field[][size]) {
    /*returns:
     * 0 Unsolved
     * 1 Solved
     *
     * */

    for (int col = 0; col < size - 1; col++) {
        for (int row = 0; row < size; row++) {
            if (field[row][col] != ' ') {
                if ((field[row][col] == field[row + 1][col]) &&
                    (field[row + 1][col] == field[row + 2][col])) {                   //HORIZONTAL
                    return 1;
                } else if ((field[row][col] == field[row][col + 1]) &&
                           (field[row][col] == field[row][col + 2])) {               //VERTICAL
                    return 1;
                } else if ((field[row][col] == field[row + 1][col + 1]) &&
                           (field[row][col] == field[row + 2][col + 2])) {          //MAIN DIAGONAL
                    return 1;
                } else if ((field[row][col] == field[row + 1][col - 1]) &&
                           (field[row][col] == field[row - 1][col + 1])) {         //ANTIDIAGONAL
                    return 1;
                }
            }
        }
    }


    return 0;


}


int add_cross(int size, char field[][size], char player, int x, int y) {
    /*returns:
     * -1  Out Of Bounds
     * -2  Position Occupied
     * 0   Success
     *
     * */
    if (x > size || x == 0 || y > size || y == 0) {
        return -1;
    } else if (field[x][y] != ' ') {
        return -2;
    }
    field[x][y] = player;
    return 0;
}

void make_turn(int size, char field[][size]) {
//    (1 + (int) size * rand() / (RAND_MAX + 1)); //generate random int
    while (add_cross(size, field, 'O', (1 + (int) size * rand() / (RAND_MAX + 1)),
                     (1 + (int) size * rand() / (RAND_MAX + 1))) != 0) {
    }

}

int main() {
    setbuf(stdout, 0);//CLion debugger fix
    printf("Enter the size of field:");
    int size1;
    scanf("%d", &size1);
    if (size1 > 2 && size1 <= 64) {}
    else {
        printf("INVALID INPUT");
        return 0;
    }
    char     field[size1][size1];
    for (int i = 0; i < size1 + 1; i++) {      //initial array with space
        for (int j = 0; j < size1 + 1; j++) {
            field[i][j] = ' ';
        }
    }
    printf("\nYOU ARE PLAYER A\n");


    char player = 'B';
    while (is_solved(size1, field) == 0) {
        if (player == 'A') {
            player = 'B';
        } else {
            player = 'A';
        }
        draw(size1, field);
        printf("\n");
        while (1) {
            if (player == 'B') {
                make_turn(size1, field);
                break;
            }//computer play as B
            int x, y;
            printf("\nENTER POSITION FOR PLAYER %c:\n", player);
            printf("X:");
            scanf("%d", &x);
            printf("Y:");
            scanf("%d", &y);
            char mark = 'X';
            if (player == 'A') {
                mark = 'X';
            } else {
                mark = 'O';
            }
            int add_cross_return = add_cross(size1, field, mark, x, y);
            if (add_cross_return == 0) {
                break;
            } else if (add_cross_return == -1) {
                printf("\n***POSITION OUT OF BOUNDS***\n");
            } else if (add_cross_return == -2) {
                printf("\n***POSITION OCCUPIED***");
            }
        }

    }

    printf("\n****************\nPLAYER %c WON!", player);

}



