#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

bool isSorted(const vector<int>& array) {
    for (size_t i = 1; i < array.size(); i++) {
        if (array[i] < array[i - 1]) {
            return false;
        }
    }
    return true;
}


double median(const vector<int>& array) {
    int size = array.size();

   
    if (size == 0) {
        throw - 1;
    }

    if (!isSorted(array)) {
        throw - 2;
    }

    
    if (size % 2 == 1) { 
        return array[size / 2];
    }
    else { 
        return (array[size / 2 - 1] + array[size / 2]) / 2.0;
    }
}

int main() {
    vector<int> array1 = { 30, 60, 90 };
    vector<int> array2 = { 30, 60, 90, 100 };
    vector<int> emptyArray = {};
    vector<int> unsortedArray = { 90, 60, 30 };

    try {
        cout << "Median of array1: " << median(array1) << endl;
        cout << "Median of array2: " << median(array2) << endl;
        cout << "Median of emptyArray: " << median(emptyArray) << endl;
    }
    catch (int e) {
        if (e == -1) {
            cout << "Error: No elements in array." << endl;
        }
        else if (e == -2) {
            cout << "Error: Array not in sorted order." << endl;
        }
    }

    try {
        cout << "Median of unsortedArray: " << median(unsortedArray) << endl;
    }
    catch (int e) {
        if (e == -1) {
            cout << "Error: No elements in array." << endl;
        }
        else if (e == -2) {
            cout << "Error: Array not in sorted order." << endl;
        }
    }

    return 0;
}