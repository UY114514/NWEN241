cmake_minimum_required(VERSION 3.12)
project(git_NWEN241_Assignments)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(GuessMyNumber)

add_executable(git_NWEN241_Assignments
kgame_win/kgame.c kgame_win/kgame.h kgame_win/main.c      )
