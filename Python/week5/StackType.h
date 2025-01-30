#ifndef STACKTYPE_H
#define STACKTYPE_H

#include "ItemType.h"

class FullStack {};  // Exception class for full stack
class EmptyStack {}; // Exception class for empty stack

class StackType {
public:
    StackType();            // Constructor
    ~StackType();           // Destructor

    bool IsFull() const;
    bool IsEmpty() const;
    void Push(ItemType item);
    void Pop();
    ItemType Top() const;
    void Print() const;

    friend bool Identical(const StackType& stack1, const StackType& stack2);

private:
    struct NodeType {
        ItemType info;
        NodeType* next;
    };
    NodeType* topPtr; // Pointer to top of stack
};

#endif

