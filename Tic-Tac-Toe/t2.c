//
// Created by UY114514 on 2018/10/8.
//

#include <stdio.h>


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

//    printf("\n***IS_SOLVED_DEBUG_INFO\n");
    for (int col = 0; col < size - 1; col++) {
        for (int row = 0; row < size - 1; row++) {
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


//    add_cross(size1, field, 'A', 2, 2);
//    add_cross(size1, field, 'A', 3, 3);
//    add_cross(size1, field, 'A', 2, 4);
//    add_cross(size1, field, 'A', 4, 2);
//    draw(size1, field);

//    printf("\n%d", is_solved(size1, field));
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
            int x, y;
            printf("\nENTER POSITION FOR PLAYER %c:\n", player);
            printf("X:");
            scanf("%d", &x);
            printf("Y:");
            scanf("%d", &y);
            int add_cross_return = add_cross(size1, field, player, x, y);
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



