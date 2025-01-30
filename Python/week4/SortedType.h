#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include "ItemType.h"

class SortedType {
public:
    SortedType(int size = 10); // Constructor with initial size
    ~SortedType();              // Destructor

    void InsertItem(ItemType item);
    void Print() const;
    int GetLength() const;

private:
    void ResizeArray();         // Function to double array size
    ItemType* info;             // Dynamically allocated array
    int length;                 // Current number of items in array
    int maxItems;               // Current maximum capacity of the array
};

#endif

