#include <iostream>
using namespace std;
int main() {
	int arraySize;
	cout << "Please enter the size of the array:";
	cin >> arraySize;
	int* dynamicArray = new int[arraySize];

	cout << "Enter" << arraySize << "elements:" << endl;
	for (int i = 0; i < arraySize; i++) {
		cin >> dynamicArray[i];
	}
	int maxVal = dynamicArray[0];
	int minVal = dynamicArray[0];
	for (int i = 1; i < arraySize; i++) {
		if (dynamicArray[i] > maxVal) {
			maxVal = dynamicArray[i];
		}
		if (dynamicArray[i] < minVal) {
			minVal = dynamicArray[i];
		}
	}
	cout << "Maximum value:" << maxVal << endl;
	cout << "Minimum value:" << minVal << endl;

	delete[] dynamicArray;
	return 0;
}