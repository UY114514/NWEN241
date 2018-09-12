#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    setbuf(stdout, 0);
    int randomNum, inputNum;
    srand(time(NULL));
    randomNum = (rand() % 100) + 1;
    printf("Guess my number between 1 and 100.You have max. 5 attempts");

    for (size_t i = 0; i < 5; i++) {
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
    printf("\nRestart?");

    scanf("\n%c", &input);
    printf("%c", input);


}