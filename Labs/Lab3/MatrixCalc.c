//
// Created by UY114514 on 2018/9/26.
//

#include <stdio.h>

int main() {
    setbuf(stdout, 0);//CLion debugger fix
    int row, col, a[50][50], b[50][50], c[50][50];
    double result[2][2];
//    printf("enter num of row:\n");
//    scanf("%d", &row);
//    printf("enter num of col:");
//    scanf("%d", &col);
    row = col = 2;
    printf("\nelements of A");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("\n[%d,%d]:", i, j);
            scanf("%d", &a[i][j]);
        }
    }

/*    printf("\nelements of B");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("\n[%d,%d]:", i, j);
            scanf("%d", &b[i][j]);
        }
    }*/
    printf("\n**RESULT**\n");
    /*Do calculate*/
    double sbDuojiang = (1.0 / (a[0][0] * a[1][1] - a[0][1] * a[1][0]));

    b[0][0] = a[1][1];
    b[0][1] = -a[0][1];
    b[1][0] = -a[1][0];
    b[1][1] = a[0][0];


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = ((double)b[i][j] * sbDuojiang);
        }
    }


    /*OUTPUT*/
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf(" %f ", result[i][j]);
        }
        printf("\n");
    }


}