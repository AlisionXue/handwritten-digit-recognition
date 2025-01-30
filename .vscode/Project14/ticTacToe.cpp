#include <iostream>
#include "ticTacToe.h"
using namespace std;

ticTacToe::ticTacToe() {
    // Initialize board with spaces
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void ticTacToe::displayBoard() const {
    cout << "  1   2   3\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        if (i < 2) cout << "\n ---|---|---\n";
    }
    cout << endl;
}

bool ticTacToe::getXOMove(char player) {
    int row, col;
    cout << "Player " << player << ", enter your move (row and column): ";
    cin >> row >> col;

    // Adjust for 0-indexed array
    row--; col--;

    // Validate move
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        displayBoard();
        return checkWinner() || checkFull(); // Check if game ends
    }
    else {
        cout << "Invalid move. Try again.\n";
        return getXOMove(player); // Recursive call for valid move
    }
}

bool ticTacToe::checkWinner() const {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;
    return false;
}

bool ticTacToe::checkFull() const {
    // Check if board is full
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void ticTacToe::play() {
    bool done = false;
    char player = 'X';
    displayBoard();

    while (!done) {
        done = getXOMove(player);

        // Switch player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    if (checkFull() && !checkWinner()) {
        cout << "It's a tie!" << endl;
    }
    else {
        cout << "Player " << (player == 'X' ? 'O' : 'X') << " wins!" << endl;
    }
}
