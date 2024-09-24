#include "view_compact.hpp"
#include "game.hpp"

bool WIN = false;
char player = 'O';

bool win_check(const std::vector<std::vector<char>> &board, char player) {
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        for (int j = 0; j <= SIZE_OF_BOARD - WINNING_COUNT; j++) {
            if (board[i][j] == player && 
                board[i][j + 1] == player && 
                board[i][j + 2] == player && 
                board[i][j + 3] == player && 
                board[i][j + 4] == player) {
                return true;
            }
            if (board[j][i] == player && 
                board[j + 1][i] == player && 
                board[j + 2][i] == player && 
                board[j + 3][i] == player && 
                board[j + 4][i] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i <= SIZE_OF_BOARD - WINNING_COUNT; i++) {
        for (int j = 0; j <= SIZE_OF_BOARD - WINNING_COUNT; j++) {
            if (board[i][j] == player && 
                board[i + 1][j + 1] == player && 
                board[i + 2][j + 2] == player && 
                board[i + 3][j + 3] == player && 
                board[i + 4][j + 4] == player) {
                return true;
            }
            if (board[i][j + 4] == player && 
                board[i + 1][j + 3] == player &&
                board[i + 2][j + 2] == player && 
                board[i + 3][j + 1] == player &&
                board[i + 4][j] == player) {
                return true;
            }
        }
    }

    return false;
}

bool checking_correct_moves(const std::vector<std::vector<char>> &board, int x, int y) {
    return (x >= 0 && x < SIZE_OF_BOARD && y >= 0 && y < SIZE_OF_BOARD && board[x][y] == ' ');
}

bool is_board_full(const std::vector<std::vector<char>> &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

void moves(std::vector<std::vector<char>> &board, char &player) {
    int x, y;
    while (true) {
        std::cout << "Player " << player << ", make a move (row and column): ";
        if (std::cin >> x >> y) {
            if (checking_correct_moves(board, x, y)) {
                board[x][y] = player;
                break;
            } else {
                std::cout << "INCORRECT MOVE!! Please try again." << std::endl;
            }
        } else {
            std::cout << "Invalid input! Please enter numbers." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }
    if (win_check(board, player)) {
        board[x][y] = player;
        drawBoard(board);
        WIN = true;
        std::cout << "Player " << player << " wins!!!" << std::endl;
    } else if (is_board_full(board)) {
        WIN = true;
        std::cout << "It's a draw!" << std::endl;
    } else {
        player = (player == 'O') ? 'X' : 'O';
    }
}

void start() {
    std::vector<std::vector<char>> board(SIZE_OF_BOARD, std::vector<char>(SIZE_OF_BOARD, ' '));

    while (!WIN) {
        clear_terminal();
        printTitle();
        drawBoard(board);
        moves(board, player);
    }
}