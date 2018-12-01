//
// Created by UY114514 on 2018/11/7.
//

#include <stdio.h>

int main(void) {
    char str[1000];
    int  length;
    char letter_to_found;
    printf("Enter a string:");
    gets(str);
//    printf("\nWhich letter to be found?:");
//    scanf("%c", &letter_to_found);

    char char2[1000];
    int  i       = 0;
    int  count   = 0;
    while (i < 1000) {
        if (str[i] != '\0') {
            count++;
            char2[i] = str[i];
            i++;
        } else {
            break;
        }
    }
    char2[count] = '\n';

    printf("%s", char2);

    int* (*doit)(float *a, float *b);

}




