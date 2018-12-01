//
// Created by UY114514 on 2018/11/12.
//
#include <stdio.h>

int main() {
    char str1[100], str2[100], result[1000];
    int  length_1, length_2, j;
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

//    printf("%s", str1);
//
//    printf("\n%s", str2);
//
    for (length_1 = 0; str1[length_1] != '\0'; ++length_1) {
        result[length_1] = str1[length_1];
    }

    for (length_2               = 0; str2[length_2] != '\0'; ++length_2) {
        result[length_1 + length_2] = str2[length_2];
    }
    result[length_1 + length_2] = '\n';

    printf("%s", result);
}

