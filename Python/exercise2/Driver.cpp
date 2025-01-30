#include "UnsortedType.h"
#include "ItemType.h"
#include <iostream>

int main() {
    UnsortedType list;
    list.isLinkedList = true;  // Set to true for linked list implementation, false for array

    int testValues[] = { 5, -12, 34, 34, 5, 45, 8, -6, 15, 40, 20, 2, 1, 12 };
    for (int value : testValues) {
        ItemType item;
        item.Initialize(value);
        list.InsertItem(item);
    }

    std::cout << "Original list: ";
    list.Print();

    UnsortedType list1, list2;
    ItemType splitItem;
    splitItem.Initialize(10);

    list.SplitLists(list, splitItem, list1, list2);

    std::cout << "List1 (<= 10): ";
    list1.Print();

    std::cout << "List2 (> 10): ";
    list2.Print();

    return 0;
}
