#include "view_compact.hpp"

void drawBoard(const std::vector<std::vector<char>> &board) 
{ 
    std::cout << "-----------------------------------------\n"; 
    for (int i = 0; i < SIZE_OF_BOARD; i++) { 
        std::cout << "| "; 
        for (int j = 0; j < SIZE_OF_BOARD; j++) { 
            std::cout << board[i][j] << " | "; 
        } 
        std::cout << "\n-----------------------------------------\n"; 
    } 
} 