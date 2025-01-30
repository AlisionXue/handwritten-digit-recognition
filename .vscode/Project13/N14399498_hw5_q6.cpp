#include <iostream>
using namespace std;

// Function to approximate e using n terms of the series
double eApprox(int n) {
    double e = 1.0;  // Start with the first term, 1
    double factorial = 1.0;  // Initialize the factorial for 0!

    for (int i = 1; i <= n; i++) {
        factorial *= i;  // Calculate the next factorial, i!
        e += 1.0 / factorial;  // Add the current term to the sum
    }

    return e;
}

int main() {
    cout.precision(30);  // Set high precision for the output

    // Loop to test eApprox for n from 1 to 15
    for (int n = 1; n <= 15; n++) {
        cout << "n = " << n << "\t" << eApprox(n) << endl;
    }

    return 0;
}
