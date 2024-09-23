#include "view_compact.hpp"

void printTitle() {
    std::cout << "  _____ ___ ____    _____  _    ____    _____ ___  _____ " << std::endl;
    std::cout << " |_   _|_ _/ ___|  |_   _|/ \\  / ___|  |_   _/ _ \\| ____|" << std::endl;
    std::cout << "   | |  | | |   _____| | / _ \\| |   _____| || | | |  _|  " << std::endl;
    std::cout << "   | |  | | |__|_____| |/ ___ \\ |__|_____| || |_| | |___ " << std::endl;
    std::cout << "   |_| |__ \\____|    |_/_/    \\_\\____|   |_| \\___/|_____|" << std::endl;
    std::cout << std::endl;
}

void clear_terminal() {
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Unix/Linux
#endif
}

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