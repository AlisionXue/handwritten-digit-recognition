#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const int SIZE = 20;

void generateBoard(int board[SIZE][SIZE]) {
    std::srand(std::time(0));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = std::rand() % 100; // Random numbers between 0 and 99
        }
    }
}

void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isPeakMax(int board[SIZE][SIZE], int i, int j) {
    int current = board[i][j];
    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            if (x == 0 && y == 0) continue;
            int ni = i + x, nj = j + y;
            if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE) {
                if (board[ni][nj] >= current) return false;
            }
        }
    }
    return true;
}

bool isPeakMin(int board[SIZE][SIZE], int i, int j) {
    int current = board[i][j];
    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            if (x == 0 && y == 0) continue;
            int ni = i + x, nj = j + y;
            if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE) {
                if (board[ni][nj] <= current) return false;
            }
        }
    }
    return true;
}

int main() {
    int board[SIZE][SIZE];
    generateBoard(board);
    printBoard(board);

    std::vector<std::pair<int, std::pair<int, int>>> peaksMax;
    std::vector<std::pair<int, std::pair<int, int>>> peaksMin;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (isPeakMax(board, i, j)) {
                peaksMax.push_back({ board[i][j], {i, j} });
            }
            if (isPeakMin(board, i, j)) {
                peaksMin.push_back({ board[i][j], {i, j} });
            }
        }
    }

    // Output peaks
    std::cout << "\nPeaks found:\n";
    for (const auto& peak : peaksMax) {
        std::cout << "Peak max: " << peak.first << ", found at: (" << peak.second.first << ", " << peak.second.second << ")\n";
    }
    for (const auto& peak : peaksMin) {
        std::cout << "Peak min: " << peak.first << ", found at: (" << peak.second.first << ", " << peak.second.second << ")\n";
    }

    // Extra Credit: Sort peaks and display them
    std::sort(peaksMax.begin(), peaksMax.end());
    std::sort(peaksMin.begin(), peaksMin.end());

    std::cout << "\nMins in order:\n";
    for (const auto& peak : peaksMin) {
        std::cout << peak.first << " ";
    }
    std::cout << "\nMaxes in order:\n";
    for (const auto& peak : peaksMax) {
        std::cout << peak.first << " ";
    }
    std::cout << std::endl;

    return 0;
}