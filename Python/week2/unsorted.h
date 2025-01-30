#ifndef UNSORTED_H
#define UNSORTED_H

#include "StudentType.h"

struct NodeType {
    StudentType info;
    NodeType* next;
};

class UnsortedType {
public:
    UnsortedType();
    ~UnsortedType();
    void InsertItem(StudentType item);
    void Print() const;  
private:
    NodeType* listData;
};

#endif

