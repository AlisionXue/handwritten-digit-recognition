#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>

enum RelationType { LESS, GREATER, EQUAL };

class ItemType {
public:
    ItemType();
    ItemType(int value);
    RelationType ComparedTo(ItemType) const;
    void Print(std::ostream&) const;
    void Initialize(int number);

private:
    int value;
};

#endif
