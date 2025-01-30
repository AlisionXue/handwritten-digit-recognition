#ifndef UNSORTED_H
#define UNSORTED_H

#include "ItemType.h"

class UnsortedType {
public:
    UnsortedType();
    ~UnsortedType();

    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ShiftRight();
    void Print() const;
    int GetLength() const;
    void ResetList();

private:
    static const int MAX_ITEMS = 50;
    ItemType info[MAX_ITEMS];
    int length;
};

#endif
