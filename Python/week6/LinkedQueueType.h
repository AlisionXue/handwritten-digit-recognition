#ifndef LINKEDQUEUETYPE_H
#define LINKEDQUEUETYPE_H

#include <iterator>
#include <iostream>

typedef int ItemType;

struct NodeType {
    ItemType info;
    NodeType* next;
};

class LinkedQueueTypeIterator;

class LinkedQueueType {
public:
    LinkedQueueType();
    ~LinkedQueueType();

    void Enqueue(ItemType newItem);
    void Dequeue();
    ItemType Front() const;
    ItemType Rear() const;
    bool IsEmpty() const;

    // Iterator functions
    LinkedQueueTypeIterator begin();
    LinkedQueueTypeIterator end();

private:
    NodeType* front;
    NodeType* rear;
    friend class LinkedQueueTypeIterator;
};

class LinkedQueueTypeIterator {
public:
    LinkedQueueTypeIterator(NodeType* startNode, NodeType* endNode);

    bool operator!=(const LinkedQueueTypeIterator& other) const;
    LinkedQueueTypeIterator& operator++();
    ItemType& operator*() const;

private:
    NodeType* currentNode;
    NodeType* endNode;
};

#endif

