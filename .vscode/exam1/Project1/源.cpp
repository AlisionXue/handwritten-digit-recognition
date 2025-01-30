#include <iostream>
#include <vector>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time() to seed rand()
using namespace std;

// Function to compute the average of vector elements
double average(vector<int>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return static_cast<double>(sum) / v.size();
}

int main() {

    srand(time(0)); 
    vector<int> numbers(20);
    for (int i = 0; i < 20; i++) {
        numbers[i] = rand() % 100 + 1;
    }

  
    cout << "Vector values: ";
    for (int i = 0; i < 20; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    
    int evenIndexSum = 0;
    for (int i = 0; i < 20; i += 2) {
        evenIndexSum += numbers[i];
    }
    cout << "Sum of even index values: " << evenIndexSum << endl;

   
    int oddIndexSum = 0;
    for (int i = 1; i < 20; i += 4) {
        oddIndexSum += numbers[i];
    }
    cout << "Sum of every other odd index value: " << oddIndexSum << endl;

   
    double avg = average(numbers);
    cout << "Average of the vector values: " << avg << endl;

    return 0;
}
