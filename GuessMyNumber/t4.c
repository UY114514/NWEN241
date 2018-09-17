#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER (int)0
#define MAX_NUMBER (int)100
#define MAX_ATTEMPTS (int)5

int main() {
    setbuf(stdout, 0);//CLion debugger fix



    int randomNum, inputNum;
    srand(time(NULL));
    randomNum = (rand() % MAX_NUMBER) + MIN_NUMBER;//generate random num
    printf("Guess my number between 1 and 100.You have max. 5 attempts");
    for (size_t i = 0; i < MAX_ATTEMPTS; i++) {
        printf("\nInput your number:");
        scanf("%d", &inputNum);
        printf("\n");
        if (inputNum > randomNum) {
            printf("Sorry...My number is smaller than yours.");
        } else if (inputNum < randomNum) {
            printf("Sorry...My number is bigger than yours.");
        } else {
            printf("Congratulations! You found it! ");
            return 0;
        }
    }
    printf("\n***GAME OVER!***\nMy number is %d.", randomNum);
    char input;

    printf("\nRestart?(y/n)");
    scanf("\n%c", &input);
    if (input == 'y' || input == 'Y') {
        main();
    } else {
        printf("See u later! ");
        return 0;
    }

}