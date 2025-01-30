#include <iostream>
#include <cmath>  // For sqrt function
using namespace std;

// Function to print all divisors of a given number in ascending order
void printDivisors(int num) {
    // We will first find divisors up to sqrt(num)
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            cout << i << " ";  // Print the divisor
        }
    }

    // Now we will print the divisors greater than sqrt(num)
    for (int i = sqrt(num); i >= 1; i--) {
        if (num % i == 0 && i != num / i) {
            cout << num / i << " ";  // Print the corresponding divisor
        }
    }
    cout << endl;
}

int main() {
    int num;

    // Prompt user to enter a positive integer
    cout << "Please enter a positive integer >= 2: ";
    cin >> num;

    // Call the function to print divisors
    printDivisors(num);

    return 0;
}
