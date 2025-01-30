#include "LinkedQueueType.h"
#include <iostream>
using namespace std;

LinkedQueueType::LinkedQueueType() : rear(nullptr), length(0) {}

LinkedQueueType::LinkedQueueType(const LinkedQueueType& qt) : rear(nullptr), length(0) {
    if (!qt.IsEmpty()) {
        NodeType* current = qt.rear->next;
        do {
            Enqueue(current->info);
            current = current->next;
        } while (current != qt.rear->next);
    }
}

LinkedQueueType& LinkedQueueType::operator=(const LinkedQueueType& rhs) {
    if (this != &rhs) {
        MakeEmpty();
        NodeType* current = rhs.rear->next;
        do {
            Enqueue(current->info);
            current = current->next;
        } while (current != rhs.rear->next);
    }
    return *this;
}

LinkedQueueType::~LinkedQueueType() {
    MakeEmpty();
}

void LinkedQueueType::MakeEmpty() {
    while (!IsEmpty()) {
        ItemType temp;
        Dequeue(temp);
    }
}

bool LinkedQueueType::IsEmpty() const {
    return rear == nullptr;
}

bool LinkedQueueType::IsFull() const {
    return false; 
}

void LinkedQueueType::Enqueue(ItemType newItem) {
    NodeType* newNode = new NodeType;
    newNode->info = newItem;
    if (IsEmpty()) {
        rear = newNode;
        rear->next = rear; 
    }
    else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
    length++;
}

void LinkedQueueType::Dequeue(ItemType& item) {
    if (IsEmpty()) throw EmptyQueue();

    NodeType* frontNode = rear->next;
    item = frontNode->info;
    if (rear == frontNode) {
        rear = nullptr;
    }
    else {
        rear->next = frontNode->next;
    }
    delete frontNode;
    length--;
}

void LinkedQueueType::Print() const {
    if (IsEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    NodeType* current = rear->next;
    do {
        cout << current->info << " ";
        current = current->next;
    } while (current != rear->next);
    cout << endl;
}
