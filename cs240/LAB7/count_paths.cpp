#include <iostream>
#include <vector>
using namespace std;

int countPaths(int row, int col, int n) {
    if (row == n - 1 && col == n - 1) {
        return 1;
    }
    if (row >= n || col >= n) {
        return 0;
    }
    return countPaths(row + 1, col, n) + countPaths(row, col + 1, n);
}

int countPathsMemo(int row, int col, int n, vector<vector<int>>& memo) {
    if (row == n - 1 && col == n - 1) {
        return 1;
    }
    if (row >= n || col >= n) {
        return 0;
    }
    if (memo[row][col] != -1) {
        return memo[row][col];
    }
    memo[row][col] = countPathsMemo(row + 1, col, n, memo) + countPathsMemo(row, col + 1, n, memo);
    return memo[row][col];
}

int main() {
    int n;
    cout << "Enter the size of the grid (N x N): ";
    cin >> n;

    int totalPathsRecursive = countPaths(0, 0, n);
    cout << "Total number of paths (Recursive): " << totalPathsRecursive << endl;

    vector<vector<int>> memo(n, vector<int>(n, -1));
    int totalPathsMemo = countPathsMemo(0, 0, n, memo);
    cout << "Total number of paths (Memoized): " << totalPathsMemo << endl;

    return 0;
}
