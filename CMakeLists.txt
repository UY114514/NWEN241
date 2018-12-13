cmake_minimum_required(VERSION 3.10)
project(git_NWEN241_Assignments)
add_definitions(-DFORK_IMPL)
set(CMAKE_C_STANDARD 11)
add_executable(git_NWEN241_Assignments Assig4/game.c
        Assig4/common.c  Assig4/guess.c Assig4/ttt.c)
include_directories("${CMAKE_CURRENT_LIST_DIR}/Assig4")