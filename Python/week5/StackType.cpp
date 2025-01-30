#include "StackType.h"
#include <iostream>

StackType::StackType() {
    topPtr = nullptr;
}

StackType::~StackType() {
    while (!IsEmpty()) {
        Pop();
    }
}

bool StackType::IsFull() const {
    // Assume stack is never full for a linked list implementation.
    return false;
}

bool StackType::IsEmpty() const {
    return topPtr == nullptr;
}

void StackType::Push(ItemType item) {
    NodeType* newNode = new NodeType;
    newNode->info = item;
    newNode->next = topPtr;
    topPtr = newNode;
}

void StackType::Pop() {
    if (IsEmpty()) throw EmptyStack();
    NodeType* tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;
}

ItemType StackType::Top() const {
    if (IsEmpty()) throw EmptyStack();
    return topPtr->info;
}

void StackType::Print() const {
    NodeType* current = topPtr;
    while (current != nullptr) {
        current->info.Print(std::cout);
        std::cout << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
