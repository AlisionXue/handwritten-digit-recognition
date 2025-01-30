#include <iostream>
using namespace std;

// Recursive function to print a line of stars
void printStars(int n) {
    if (n == 0) {
        return;
    }
    cout << "*";
    printStars(n - 1);
}

// Recursive function to print the star pattern
void printPattern(int n, int original) {
    if (n == 0) {
        return;
    }

    // Print the decreasing part of the pattern
    printStars(n);
    cout << endl;
    printPattern(n - 1, original);

    // Print the increasing part of the pattern
    if (n < original) {
        printStars(n);
        cout << endl;
    }
}

int main() {
    int lines;
    cout << "Enter the number of lines: ";
    cin >> lines;

    if (lines >= 0) {
        printPattern(lines, lines);
    }
    else {
        cout << "Please enter a nonnegative integer." << endl;
    }

    return 0;
}
