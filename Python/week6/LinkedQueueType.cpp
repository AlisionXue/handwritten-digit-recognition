#include "LinkedQueueType.h"

// LinkedQueueType Constructor and Destructor
LinkedQueueType::LinkedQueueType() : front(nullptr), rear(nullptr) {}

LinkedQueueType::~LinkedQueueType() {
    while (!IsEmpty()) {
        Dequeue();
    }
}

void LinkedQueueType::Enqueue(ItemType newItem) {
    NodeType* newNode = new NodeType;
    newNode->info = newItem;
    if (IsEmpty()) {
        front = newNode;
        rear = newNode;
        newNode->next = front; // Circular link
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Circular link
    }
}

void LinkedQueueType::Dequeue() {
    if (IsEmpty()) {
        std::cerr << "Queue is empty, cannot dequeue." << std::endl;
        return;
    }

    NodeType* tempNode = front;
    if (front == rear) { // Only one node in the queue
        front = nullptr;
        rear = nullptr;
    }
    else {
        front = front->next;
        rear->next = front; // Maintain circular link
    }
    delete tempNode;
}

ItemType LinkedQueueType::Front() const {
    if (!IsEmpty()) {
        return front->info;
    }
    else {
        throw std::runtime_error("Queue is empty, no front element.");
    }
}

ItemType LinkedQueueType::Rear() const {
    if (!IsEmpty()) {
        return rear->info;
    }
    else {
        throw std::runtime_error("Queue is empty, no rear element.");
    }
}

bool LinkedQueueType::IsEmpty() const {
    return front == nullptr;
}

// Iterator functions
LinkedQueueTypeIterator LinkedQueueType::begin() {
    return LinkedQueueTypeIterator(front, rear);
}

LinkedQueueTypeIterator LinkedQueueType::end() {
    return LinkedQueueTypeIterator(nullptr, rear);
}

// LinkedQueueTypeIterator Constructor and Operators
LinkedQueueTypeIterator::LinkedQueueTypeIterator(NodeType* startNode, NodeType* endNode)
    : currentNode(startNode), endNode(endNode) {}

bool LinkedQueueTypeIterator::operator!=(const LinkedQueueTypeIterator& other) const {
    return currentNode != other.currentNode;
}

LinkedQueueTypeIterator& LinkedQueueTypeIterator::operator++() {
    if (currentNode == endNode) {
        currentNode = nullptr; // End iteration if we've reached the rear
    }
    else {
        currentNode = currentNode->next;
    }
    return *this;
}

ItemType& LinkedQueueTypeIterator::operator*() const {
    return currentNode->info;
}
