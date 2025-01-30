#include <iostream>

int recursiveSequentialSearch(int arr[], int size, int target, int index = 0) {
    if (index == size) {
        return -1; // Target not found
    }
    if (arr[index] == target) {
        return index; // Target found
    }
    return recursiveSequentialSearch(arr, size, target, index + 1);
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size]; // Dynamically allocate an array of the given size

    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int target;
    std::cout << "Enter the target element to search for: ";
    std::cin >> target;

    int result = recursiveSequentialSearch(arr, size, target);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    }
    else {
        std::cout << "Element not found in the array." << std::endl;
    }

    delete[] arr; // Free dynamically allocated memory

    return 0;
}
