#include <iostream>
using namespace std;

// Function to print a single shifted triangle
void printShiftedTriangle(int n, int m, char symbol) {
    for (int i = 1; i <= n; i++) {
        // Print the left margin spaces
        for (int j = 1; j <= m + (n - i); j++) {
            cout << " ";
        }
        // Print the symbol characters in the current row
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << symbol;
        }
        cout << endl;
    }
}

// Function to print a pine tree consisting of 'n' triangles
void printPineTree(int n, char symbol) {
    // Loop through the number of triangles
    for (int i = 1; i <= n; i++) {
        printShiftedTriangle(i + 1, n - i, symbol);  // Print each triangle
    }
}

int main() {
    int numTriangles;
    char symbol;

    // Prompt the user for the number of triangles and the symbol
    cout << "Enter the number of triangles: ";
    cin >> numTriangles;
    cout << "Enter the character for the tree: ";
    cin >> symbol;

    // Print the pine tree
    printPineTree(numTriangles, symbol);

    return 0;
}
