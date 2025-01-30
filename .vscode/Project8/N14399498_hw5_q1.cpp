#include <iostream>
using namespace std;

// Function to return the nth Fibonacci number
int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int num;

    // Prompt user to enter a positive integer
    cout << "Please enter a positive integer: ";
    cin >> num;

    // Output Fibonacci sequence up to the nth number
    for (int i = 1; i <= num; i++) {
        cout << fib(i) << " ";
    }
    cout << endl;

    return 0;
}
