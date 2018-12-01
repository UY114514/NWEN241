//
// Created by UY114514 on 2018/9/17.
//
#include <stdio.h>
#define HKD 1.14
#define PHP 7.90
#define SGD 0.20
#define AUD 0.20
#define FJD 0.31

int get_type() {
    printf("Convert CNY to:\n");
    printf("1.HKD\n");
    printf("2.PHP\n");
    printf("3.SGD\n");
    printf("4.AUD\n");
    printf("5.FJD\n");
    int input;
    scanf("%d", &input);
    return input;
}

double get_amount(){
    printf("\nCNY:");
    float input2;
    scanf("%f", &input2);
    return input2;
}
double convert(int currencyNo, double amout) {
    switch (currencyNo) {
        case 1://HKD
            return amout * HKD;
        case 2:
            return amout * PHP;
        case 3:
            return amout * SGD;
        case 4:
            return amout * AUD;
        case 5:
            return amout * FJD;
    }
}


int main() {
    printf("\n*Result: %.2lf", convert(get_type(), get_amount()));
}

