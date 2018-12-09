#
# NWEN 241 Makefile for Programming Assignment #4
#
# Name: Fangyi Yan
# Student ID: 1624092237
#

# Do not remove the line below:
.PHONY: clean egame

# Write the rules below, as specified in Task 2.


fgame: game.c
	gcc -D FORK_IMPL game.c guess.c ttt.c common.c -o fgame
egame:game.c guess.c common.c common.h ttt.c
	gcc -D FORK_EXEC_IMPL guess.c common.c -o guess
	gcc -D FORK_EXEC_IMPL game.c common.c -o game
	gcc -D FORK_EXEC_IMPL ttt.c common.c -o ttt
clean:
	rm -f *.o fgame game guess ttt