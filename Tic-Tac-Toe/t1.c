//
// Created by UY114514 on 2018/10/8.
//

#include <stdio.h>

int is_solved(const char field[], int size) {
    for (int i = 0; i < size - 2; ++i) {
        if (field[i] == 'X') {
            if (field[i + 1] == 'X') {
                if (field[i + 2] == 'X') {
                    return 1;
                }
            }
        }
    }
    return 0;

}

int add_cross(char field[], int size, int position) {
    if (position > size) {
        return -1;
    }

    if (field[position] == 'X') {
        return 0;
    } else {
        field[position] = 'X';
        return 1;
    }
}


void draw_field(const char field[], int size) {
    //draw first line
    for (int i = 0; i < size + 1; i++) {
        if (i == 0) {
            printf("+");
        } else {
            printf("-+");
        }
    }
    printf("\n");

    //2nd line
    for (int j = 0; j < size + 1; ++j) {
        if (j == 0) {
            printf("|");
        } else {
            printf("%c|", field[j]);
        }
    }
    printf("\n");

    //3rd line
    for (int i = 0; i < size + 1; i++) {
        if (i == 0) {
            printf("+");
        } else {
            printf("-+");
        }
    }
    printf("\n");

    //4th line: draw number
    for (int i = 1; i < size + 1; i++) {
        printf(" %d", i);
    }
    printf("\n");
}
int main() {
    printf("Enter the size of field:");
    int size1;
    scanf("%d", &size1);
    if (size1 > 2 && size1 <= 64) {}
    else {
        printf("Invalid input");
        return 0;
    }
    char     field[size1];
    for (int i = 0; i < size1; i++) {//initial array with space
        field[i] = ' ';
    }
    draw_field(field, size1);
}

