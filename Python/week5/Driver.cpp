#include <iostream>
#include "StackType.h"
#include "ItemType.h"

void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem) {
    StackType tempStack;
    while (!stack.IsEmpty()) {
        ItemType item = stack.Top();
        stack.Pop();
        if (item.ComparedTo(oldItem) == EQUAL) {
            tempStack.Push(newItem);
        }
        else {
            tempStack.Push(item);
        }
    }
    while (!tempStack.IsEmpty()) {
        stack.Push(tempStack.Top());
        tempStack.Pop();
    }
}

bool Identical(const StackType& stack1, const StackType& stack2) {
    StackType tempStack1 = stack1;
    StackType tempStack2 = stack2;
    while (!tempStack1.IsEmpty() && !tempStack2.IsEmpty()) {
        if (tempStack1.Top().ComparedTo(tempStack2.Top()) != EQUAL) {
            return false;
        }
        tempStack1.Pop();
        tempStack2.Pop();
    }
    return tempStack1.IsEmpty() && tempStack2.IsEmpty();
}

int main() {
    StackType stack;
    stack.Push(ItemType(4));
    stack.Push(ItemType(4));
    stack.Push(ItemType(5));
    stack.Push(ItemType(4));
    stack.Push(ItemType(3));
    stack.Push(ItemType(4));
    stack.Print();

    ReplaceItem(stack, ItemType(4), ItemType(8));
    stack.Print();

    StackType myStack;
    myStack.Push(ItemType(4));
    myStack.Push(ItemType(4));
    myStack.Push(ItemType(5));
    myStack.Push(ItemType(4));
    myStack.Push(ItemType(3));
    myStack.Push(ItemType(4));
    myStack.Print();

    if (Identical(stack, myStack)) {
        std::cout << "The stacks are identical." << std::endl;
    }
    else {
        std::cout << "The stacks are NOT identical." << std::endl;
    }

    return 0;
}
