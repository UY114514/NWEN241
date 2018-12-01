cmake_minimum_required(VERSION 3.12)
project(git_NWEN241_Assignments)

set(CMAKE_CXX_STANDARD 14)
include_directories(.)
add_compile_definitions(_MSC_VER)
add_executable(git_NWEN241_Assignments
kgame_win/kgame.c kgame_win/kgame.h kgame_win/main.c      )
