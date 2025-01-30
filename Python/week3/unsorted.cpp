#include "unsorted.h"
#include <iostream>

UnsortedType::UnsortedType() : length(0) {}

UnsortedType::~UnsortedType() {}

void UnsortedType::PutItem(ItemType item) {
    if (length < MAX_ITEMS) {
        info[length] = item;
        length++;
    }
}

void UnsortedType::DeleteItem(ItemType item) {
    int i = 0;
    while (i < length) {
        if (info[i].ComparedTo(item) == EQUAL) {
            for (int j = i; j < length - 1; j++) {
                info[j] = info[j + 1];
            }
            length--;
        }
        else {
            i++;
        }
    }
}

void UnsortedType::ShiftRight() {
    if (length > 0) {
        ItemType lastItem = info[length - 1];
        for (int i = length - 1; i > 0; i--) {
            info[i] = info[i - 1];
        }
        info[0] = lastItem;
    }
}

void UnsortedType::Print() const {
    for (int i = 0; i < length; i++) {
        info[i].Print(std::cout);
        std::cout << " ";
    }
    std::cout << std::endl;
}

int UnsortedType::GetLength() const {
    return length;
}

void UnsortedType::ResetList() {
    // 不修改 length，仅重置游标或做其他需要的操作
}
