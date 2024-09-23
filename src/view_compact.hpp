#pragma once

#include "globals.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>

void printTitle();

void clear_terminal();

void drawBoard(const std::vector<std::vector<char>> &board);