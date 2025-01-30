#include "UnsortedType.h"
#include <iostream>

UnsortedType::UnsortedType() : length(0), head(nullptr), isLinkedList(false) {}

UnsortedType::~UnsortedType() {
    MakeEmpty();
}

UnsortedType::UnsortedType(const UnsortedType& other) {
    isLinkedList = other.isLinkedList;
    length = other.length;

    if (isLinkedList) {
        NodeType* origNode = other.head;
        NodeType* copyNode;
        head = new NodeType;
        head->info = origNode->info;
        head->next = nullptr;
        origNode = origNode->next;
        copyNode = head;

        while (origNode != nullptr) {
            NodeType* newNode = new NodeType;
            newNode->info = origNode->info;
            newNode->next = nullptr;
            copyNode->next = newNode;
            copyNode = newNode;
            origNode = origNode->next;
        }
    }
    else {
        for (int i = 0; i < length; i++) {
            info[i] = other.info[i];
        }
    }
}

void UnsortedType::MakeEmpty() {
    if (isLinkedList) {
        NodeType* tempPtr;
        while (head != nullptr) {
            tempPtr = head;
            head = head->next;
            delete tempPtr;
        }
        length = 0;
    }
    else {
        length = 0;
    }
}

bool UnsortedType::IsFull() const {
    return length == MAX_ITEMS;
}

int UnsortedType::GetLength() const {
    return length;
}

void UnsortedType::InsertItem(ItemType item) {
    if (isLinkedList) {
        NodeType* newNode = new NodeType;
        newNode->info = item;
        newNode->next = head;
        head = newNode;
    }
    else {
        info[length] = item;
    }
    length++;
}

void UnsortedType::Print() const {
    if (isLinkedList) {
        NodeType* temp = head;
        while (temp != nullptr) {
            temp->info.Print(std::cout);
            std::cout << " ";
            temp = temp->next;
        }
    }
    else {
        for (int i = 0; i < length; i++) {
            info[i].Print(std::cout);
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void UnsortedType::SplitLists(UnsortedType list, ItemType item, UnsortedType& list1, UnsortedType& list2) {
    list1.isLinkedList = list.isLinkedList;
    list2.isLinkedList = list.isLinkedList;

    if (list.isLinkedList) { // Linked list version
        NodeType* temp = list.head;
        while (temp != nullptr) {
            if (temp->info.ComparedTo(item) == LESS || temp->info.ComparedTo(item) == EQUAL) {
                list1.InsertItem(temp->info);
            }
            else {
                list2.InsertItem(temp->info);
            }
            temp = temp->next;
        }
    }
    else { // Array version
        for (int i = 0; i < list.length; i++) {
            if (list.info[i].ComparedTo(item) == LESS || list.info[i].ComparedTo(item) == EQUAL) {
                list1.InsertItem(list.info[i]);
            }
            else {
                list2.InsertItem(list.info[i]);
            }
        }
    }
}
