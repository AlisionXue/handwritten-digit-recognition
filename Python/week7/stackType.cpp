#include "stackType.h"
#include <iostream>
#include <cassert>

template <class T>
stackType<T>::stackType(int size) {
    if (size <= 0) {
        std::cerr << "Size of the array must be positive." << std::endl;
        size = 100;
    }
    maxStackSize = size;
    stackTop = 0;
    stackArray = new T[maxStackSize];
}

template <class T>
stackType<T>::~stackType() {
    delete[] stackArray;
}

template <class T>
void stackType<T>::push(const T& newItem) {
    assert(!isFullStack());
    stackArray[stackTop++] = newItem;
}

template <class T>
void stackType<T>::pop() {
    assert(!isEmptyStack());
    stackTop--;
}

template <class T>
bool stackType<T>::isEmptyStack() const {
    return (stackTop == 0);
}

template <class T>
bool stackType<T>::isFullStack() const {
    return (stackTop == maxStackSize);
}

// Overloaded == operator
template <class T>
bool stackType<T>::operator==(const stackType<T>& otherStack) const {
    if (stackTop != otherStack.stackTop) {
        return false;
    }

    for (int i = 0; i < stackTop; i++) {
        if (stackArray[i] != otherStack.stackArray[i]) {
            return false;
        }
    }

    return true;
}

// Explicit instantiation for common types (optional, if needed for template classes)
template class stackType<int>;
template class stackType<double>;
template class stackType<std::string>;
