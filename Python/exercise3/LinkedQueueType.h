#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

class FullQueue {};   // Queue full exception
class EmptyQueue {};  // Queue empty exception

typedef int ItemType;

struct NodeType {
    ItemType info;
    NodeType* next;
};

class LinkedQueueType {
public:
    LinkedQueueType();                        // Constructor
    LinkedQueueType(const LinkedQueueType&);  // Copy constructor
    LinkedQueueType& operator=(const LinkedQueueType& rhs); // Assignment operator
    ~LinkedQueueType();                       // Destructor

    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
    void Print() const;

private:
    NodeType* rear; // Points to the last node in the queue
    int length;     // Tracks the number of items in the queue
};

#endif

