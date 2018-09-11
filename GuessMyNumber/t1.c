#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int randomNum, inputNum;
	srand(time(NULL));
	randomNum = (rand() % 100) + 1;
	printf("Guess my number between 1 and 100. \nInput your number:");
	scanf_s("%d", &inputNum);
	printf("\n");
	   
	if (inputNum>randomNum)
	{
		printf_s("Sorry...My number is smaller than yours.");
	}
	else if (inputNum<randomNum)
	{
		printf_s("Sorry...My number is bigger than yours.");
	}
	else {
		printf_s("Congratulations! You found it! ");
	}
}