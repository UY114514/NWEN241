//
// Created by UY114514 on 2018/9/16.
//
#include <stdio.h>
#include <stdbool.h>


int check_guess(int guess) {
    /* ask user if generated guess is right or not
     * @return -1 for lower
     * @return 0  for equal
     * @return 1  for higher
     */
    printf("Your number is %d, am I right?\nIf not, my guess should be lower or higher?\n", guess);
    printf("Type y/Y if that's right.Type l/L for LOWER, h/H for HIGHER:");
    char inputChar;
    scanf("\n%c", &inputChar);
    switch (inputChar) {
        case 'Y':
        case 'y':
            return 0;
        case 'l':
        case 'L':
            return -1;
        case 'h':
        case 'H':
            return 1;
//        default:
//            printf("*%c", inputChar);
    }


    return inputChar;
}

int guess_tester(int guess) {
    /* an auto test tool
     * @return -1 for lower
     * @return 0  for equal
     * @return 1  for higher
     */
    int target = 24;

    if (guess > target) {
        return -1;
    } else if (guess < target) {
        return 1;
    } else {
        return 0;
    }


}

int main(void) {//BUG:may generate guesses higher than 100
    int c = 0;
    int count = 10;
    int guess = 50;
    bool exit = false;
    while (!exit) {
        c++;
        if (count > 1) {
            count = count - 1;
        }
//        printf("\nturn %d,guess %d,count %d", c, guess, count); //for debug
        if (guess > 100) {
            guess = 100;
            continue;
        } else if (guess < 0) {
            guess = 0;
        }
        switch (check_guess(guess)) {
            case 0:
                printf("\nRestart?(y/n)");
                char input;
                scanf("\n%c", &input);
                if (input == 'y' || input == 'Y') {
                    main();
                } else {
                    printf("See u later! ");
                    exit = true;
                    break;
                }
                return 0;
            case 1:
                if (count == 1) {
                    guess++;

                } else {
                    guess = (int) ((1 + count * 0.1) * guess);
                }
                break;
            case -1:
                if (count == 1) {
                    guess--;

                } else {
                    guess = (int) ((1 - count * 0.1) * guess);
                }
                break;
        }

    }


    return 0;


}