#include "UnsortedType.h"
#include <iostream>
using namespace std;

UnsortedType::UnsortedType() : length(0), isLinkedList(false) {} 

UnsortedType::~UnsortedType() {}

void UnsortedType::MakeEmpty() {
    length = 0;
}

bool UnsortedType::IsFull() const {
    return length == MAX_ITEMS;
}

int UnsortedType::GetLength() const {
    return length;
}

void UnsortedType::InsertItem(ItemType item) {
    if (!IsFull()) {
        info[length] = item;
        length++;
    }
    else {
        cout << "List is full." << endl;
    }
}

void UnsortedType::Print() const {
    for (int i = 0; i < length; i++) {
        info[i].Print(cout);
        cout << " ";
    }
    cout << endl;
}

void UnsortedType::SplitLists(UnsortedType list, ItemType item, UnsortedType& list1, UnsortedType& list2) {
    for (int i = 0; i < list.length; i++) {
        if (list.info[i].ComparedTo(item) == LESS || list.info[i].ComparedTo(item) == EQUAL) {
            list1.InsertItem(list.info[i]);
        }
        else {
            list2.InsertItem(list.info[i]);
        }
    }
}

bool UnsortedType::GetIsLinkedList() const {
    return isLinkedList;
}

void UnsortedType::SetIsLinkedList(bool value) {
    isLinkedList = value;
}
