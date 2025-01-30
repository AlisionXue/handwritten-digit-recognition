#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"

const int MAX_ITEMS = 50;

class UnsortedType {
public:
    UnsortedType();                 // Constructor
    ~UnsortedType();                // Destructor
    UnsortedType(const UnsortedType& other); // Copy constructor (for linked list)

    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    void InsertItem(ItemType item);
    void Print() const;

    void SplitLists(UnsortedType list, ItemType item, UnsortedType& list1, UnsortedType& list2);

    // Linked list node for linked list version
    struct NodeType {
        ItemType info;
        NodeType* next;
    };

    NodeType* head; // Used in linked list version
    ItemType info[MAX_ITEMS]; // Used in array-based version
    int length;

    bool isLinkedList; // Flag to choose array or linked list version
};

#endif

