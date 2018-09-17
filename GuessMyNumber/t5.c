
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN_NUMBER (int)0
#define MAX_NUMBER (int)100
#define MAX_ATTEMPTS (int)5


int get_guess(void) {
    int inputNum;
    printf("\nInput your number:");
    scanf("%d", &inputNum);
    printf("\n");
    return inputNum;
}

bool is_game_won(int secret, int guess) {
    if (guess != secret) {
        return false;
    }
    return true;
}

int generate_secret(int start, int end) {
    srand(time(NULL));
    return (rand() % end) + start;//generate random num
}

int main() {
    setbuf(stdout, 0);//CLion debugger fix


    int randomNum, inputNum;
    randomNum = generate_secret(MIN_NUMBER, MAX_NUMBER);
//    printf("*%d*", randomNum); //for test
    printf("Guess my number between 1 and 100.You have max. 5 attempts");
    for (size_t i = 0; i < MAX_ATTEMPTS; i++) {
        int input = get_guess();
        if (is_game_won(randomNum, input)) {
            printf("Congratulations! You found it! ");
            break;
        } else if (inputNum > randomNum) {
            printf("Sorry...My number is smaller than yours.");
        } else if (inputNum < randomNum) {
            printf("Sorry...My number is bigger than yours.");
        }
    }
    printf("\n***GAME OVER***\nMy number is %d.", randomNum);

    printf("\nRestart?(y/n)");
    char input;
    scanf("\n%c", &input);
    if (input == 'y' || input == 'Y') {
        main();
    } else {
        printf("See u later! ");
        return 0;
    }

}


