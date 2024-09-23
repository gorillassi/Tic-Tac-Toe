#pragma once

#include "view_compact.hpp"

bool win_check(const std::vector<std::vector<char>> &board, char player);

bool checking_correct_moves(const std::vector<std::vector<char>> &board, int x , int y);

bool is_board_full(const std::vector<std::vector<char>> &board);

void moves(const std::vector<std::vector<char>> &board, char &player);

void start();