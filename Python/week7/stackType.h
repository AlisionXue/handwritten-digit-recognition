#ifndef STACKTYPE_H
#define STACKTYPE_H

template <class T>
class stackType {
private:
    T* stackArray;
    int maxStackSize;
    int stackTop;

public:
    // Constructor
    stackType(int size = 100);

    // Destructor
    ~stackType();

    // Push and pop functions
    void push(const T& newItem);
    void pop();

    // Check if stack is empty or full
    bool isEmptyStack() const;
    bool isFullStack() const;

    // Overloaded equality operator
    bool operator==(const stackType<T>& otherStack) const;
};

#endif

