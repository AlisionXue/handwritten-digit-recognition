#include "SortedType.h"
#include <iostream>

SortedType::SortedType(int size) : length(0), maxItems(size) {
    info = new ItemType[maxItems];
}

SortedType::~SortedType() {
    delete[] info;
}

void SortedType::InsertItem(ItemType item) {
    if (length == maxItems) {  // Array is full, so resize
        ResizeArray();
    }
    // Insert the item in sorted order
    int i = length - 1;
    while (i >= 0 && info[i].ComparedTo(item) == GREATER) {
        info[i + 1] = info[i];
        i--;
    }
    info[i + 1] = item;
    length++;
}

void SortedType::ResizeArray() {
    maxItems *= 2;                   // Double the size
    ItemType* newInfo = new ItemType[maxItems];
    for (int i = 0; i < length; i++) {
        newInfo[i] = info[i];        // Copy elements to new array
    }
    delete[] info;                   // Deallocate old array
    info = newInfo;                  // Update pointer to new array
}

void SortedType::Print() const {
    for (int i = 0; i < length; i++) {
        info[i].Print(std::cout);
        std::cout << " ";
    }
    std::cout << std::endl;
}

int SortedType::GetLength() const {
    return length;
}
