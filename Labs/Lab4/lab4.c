//
// Created by UY114514 on 2018/10/8.
//
#include <stdio.h>

void function_that_accepts_two_integer_arguments_and_returns_a_long_integer(int a, int b) {
    long int long_int = 1145141919;
    printf("LONG INT POINTER: %u\n", &long_int);
}


void function_that_accepts_two_arguments_and_returns_a_long_integer(int *a, int *b) {
    long int long_int2 = 1145141919;
    printf("LONG INT: %u\n", long_int2);
}

float function_that_accepts_three_integer_arguments_and_returns_a_floating_point_quantity(int a, int b, int c) {
    float floating_point_num = 114.514;
    return floating_point_num;
}
int func ( void (*f)(int) ) {
    char ch1 = 'X';
    char *ch;
    ch = &ch1;
    return ch;
}


int main() {
/*
    char strings[][64] = {"red", "green", "blue"};

    //a
    float  floating_point_num   = 114.514;
    double double_precision_num = 19.19;
    float  *float_pointer;
    double *double_pointer;
//    float_pointer = &floating_point_num;
    float_pointer  = &floating_point_num;
    double_pointer = &double_precision_num;
    function_that_accepts_two_integer_arguments_and_returns_a_long_integer(1, 2);
    function_that_accepts_two_arguments_and_returns_a_long_integer(3, 4);

*/


}
