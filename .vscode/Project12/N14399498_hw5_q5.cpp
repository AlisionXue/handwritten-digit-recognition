#include <iostream>
#include <cmath>  // For sqrt function
using namespace std;

// Function to analyze divisors, outputs the count and sum of proper divisors
void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
    outCountDivs = 0;
    outSumDivs = 0;

    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            outCountDivs++; // Count proper divisor
            outSumDivs += i; // Add proper divisor

            if (i != 1 && i != num / i && num / i != num) { // Avoid duplicate divisors and num itself
                outCountDivs++;
                outSumDivs += num / i;
            }
        }
    }
}

// Function to check if a number is perfect
bool isPerfect(int num) {
    int countDivs, sumDivs;
    analyzeDivisors(num, countDivs, sumDivs);
    return sumDivs == num; // A number is perfect if the sum of its proper divisors equals the number
}

// Function to print perfect numbers and amicable pairs up to M
void printPerfectAndAmicable(int M) {
    cout << "Perfect numbers between 2 and " << M << " are: ";
    for (int i = 2; i <= M; i++) {
        if (isPerfect(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "Amicable numbers between 2 and " << M << " are: " << endl;
    for (int i = 2; i <= M; i++) {
        int countDivs, sumDivs;
        analyzeDivisors(i, countDivs, sumDivs);

        if (sumDivs > i && sumDivs <= M) {
            int otherCountDivs, otherSumDivs;
            analyzeDivisors(sumDivs, otherCountDivs, otherSumDivs);

            if (otherSumDivs == i) {
                cout << i << " and " << sumDivs << endl; // Print the amicable pair
            }
        }
    }
}

int main() {
    int M;

    // Prompt the user to enter a positive integer M
    cout << "Enter a positive integer M (>= 2): ";
    cin >> M;

    // Call the function to print perfect and amicable numbers
    printPerfectAndAmicable(M);

    return 0;
}
