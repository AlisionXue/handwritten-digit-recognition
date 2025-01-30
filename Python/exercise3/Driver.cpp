#include "UnsortedType.h"
#include "ItemType.h"
#include <iostream>
using namespace std;

int main() {
    UnsortedType list, list1, list2;
    ItemType item;

    list.SetIsLinkedList(true);  
    if (list.GetIsLinkedList()) {  
        cout << "This is a linked list implementation." << endl;
    }

    int values[] = { 5, -12, 34, 34, 5, 45, 8, -6, 15, 40, 20, 2, 1, 12 };
    for (int value : values) {
        ItemType item;
        item.Initialize(value); 
        list.InsertItem(item);
    }


    cout << "Original list: ";
    list.Print();


    ItemType splitItem;
    splitItem.Initialize(10); 
    list.SplitLists(list, splitItem, list1, list2);


    cout << "List1 (<= 10): ";
    list1.Print();

    cout << "List2 (> 10): ";
    list2.Print();

    return 0;
}
