#include <stdio.h>
#include <ctype.h>

#define N 4
int main() {
    char s6[] = "Hello";
    char *s7 = "hello";
    printf("%c\n", s7[0]);
    s7 = s6;
    printf("%c\n", s7[0]);
}