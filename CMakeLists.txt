cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)

add_executable(tic_tac_toe src/main.cpp src/game.cpp src/view_compact.cpp)
