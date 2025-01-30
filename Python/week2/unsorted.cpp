#include "unsorted.h"
#include <iostream>

UnsortedType::UnsortedType() {
    listData = nullptr;
}

UnsortedType::~UnsortedType() {
    NodeType* tempPtr;
    while (listData != nullptr) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

void UnsortedType::InsertItem(StudentType item) {
    NodeType* newNode = new NodeType;
    newNode->info = item;
    newNode->next = nullptr;

    if (listData == nullptr) {  
        listData = newNode;
    }
    else {  
        NodeType* current = listData;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void UnsortedType::Print() const {
    NodeType* currentNode = listData;

    if (currentNode == nullptr) {
        std::cout << "Empty." << std::endl;
        return;
    }

    while (currentNode != nullptr) {
        std::cout << "Name: " << currentNode->info.GetName() << std::endl;
        std::cout << "Status: " << currentNode->info.GetStatus() << std::endl;
        currentNode = currentNode->next;
    }
}
