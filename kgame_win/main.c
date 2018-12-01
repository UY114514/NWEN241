#pragma warning(disable : 4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "kgame.h"

#define VALID_INPUTS_STRING   "Valid Inputs: [UP/DN/LT/RT] [S/s:Save] [L/l:Load] [X/x:Exit]\n"
#define DEFAULT_OUTPUT_STRING "You have not implemented kgame_render() yet.\n"

#define KEY_UP 56
#define KEY_DOWN 53
#define KEY_LEFT 52
#define KEY_RIGHT 54

int get_user_input(void)
{
	int c;
	do {
		printf(VALID_INPUTS_STRING);
		c = getchar();

		switch (c)
		{
		case KEY_UP:
			return UP;
		case KEY_DOWN:
			return DOWN;
		case KEY_LEFT:
			return LEFT;
		case KEY_RIGHT:
			return RIGHT;
		case 'S':
		case 's':
			return SAVE;
		case 'L':
		case 'l':
			return LOAD;
		case 'X':
		case 'x':
			return EXIT;
			//default:
				//break;

		}
	} while (1);
}

int main()
{
	setbuf(stdout, 0);
	kgame_t kgame;
	int input_key;
	bool render = true;

	char kgame_buffer[KGAME_OUTPUT_BUFLEN] = DEFAULT_OUTPUT_STRING;
	kgame_init(&kgame);
	while (true)
	{


		if (render)
		{

			kgame_render(kgame_buffer, &kgame);
		}

		printf(kgame_buffer);                /*put the score into the array after the board*/

		if (kgame_is_won(&kgame))
		{
			printf("Congratulations! You won the game.");
		}
		if (kgame_is_move_possible(&kgame) == false)
		{
			printf("Sorry, you ran out of moves. Game over!");
		}

		input_key = get_user_input();

		switch (input_key)
		{
		case EXIT:
			printf("Exiting...");
			return 0;
		case SAVE:
			kgame_save(&kgame);
			printf("Tried to save game.");
			break;
		case LOAD:
			render = kgame_load(&kgame);
			printf("Tried to load game.");
			break;
		case UP:
		case DOWN:
		case LEFT:
		case RIGHT:
			render = kgame_update(&kgame, (dir_t)input_key);
			break;
		default:
			break;
		}
	}

	return 0;
}