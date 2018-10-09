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


int main() {
    setbuf(stdout, 0);//CLion debugger fix
    printf("Enter the size of field:");
    int size1;
    scanf("%d", &size1);
    if (size1 > 2 && size1 <= 64) {}
    else {
        printf("Invalid input");
        return 0;
    }
    char field[size1][size1];

    for (int i = 0; i < size1 + 1; i++) {      //initial array with space
        for (int j = 0; j < size1 + 1; j++) {
            field[i][j] = ' ';
        }
    }


    draw(size1, field);



    


}
