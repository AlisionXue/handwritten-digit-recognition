#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // Added for std::iota
using namespace std;

bool isMagicSquare(const vector<int>& square, int n) {
    int magicSum = static_cast<long long>(n) * (n * n + 1) / 2;  // Prevent overflow with static_cast

    // Check rows and columns
    for (int i = 0; i < n; i++) {
        long long rowSum = 0, colSum = 0;  // Use long long to prevent overflow
        for (int j = 0; j < n; j++) {
            rowSum += square[i * n + j];
            colSum += square[j * n + i];
        }
        if (rowSum != magicSum || colSum != magicSum) {
            return false;
        }
    }

    // Check diagonals
    long long diagSum1 = 0, diagSum2 = 0;  // Use long long to prevent overflow
    for (int i = 0; i < n; i++) {
        diagSum1 += square[i * n + i];
        diagSum2 += square[i * n + (n - i - 1)];
    }
    return diagSum1 == magicSum && diagSum2 == magicSum;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid value for n." << endl;
        return 1;
    }

    int size = n * n;
    vector<int> square(size);
    cout << "Enter " << size << " numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> square[i];
    }

    // Check if all numbers from 1 to n^2 are present
    vector<int> check(size);
    iota(check.begin(), check.end(), 1);
    sort(square.begin(), square.end());
    if (square != check) {
        cout << "The numbers are not all unique from 1 to " << size << "." << endl;
        return 1;
    }

    if (isMagicSquare(square, n)) {
        cout << "This is a magic square." << endl;
    }
    else {
        cout << "This is not a magic square." << endl;
    }

    return 0;
}