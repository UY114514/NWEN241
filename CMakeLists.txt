cmake_minimum_required(VERSION 3.10)
project(git_NWEN241_Assignments)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)
include_directories(.)
add_executable(git_NWEN241_Assignments
        Assig4/common.c Assig4/common.h Assig4/game.c Assig4/guess.c Assig4/ttt.c Assig4/Makefile)
