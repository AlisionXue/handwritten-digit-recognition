#include <iostream>
#include "stackType.h"

int main() {
    stackType<int> stack1(5);
    stackType<int> stack2(5);

    // Push elements onto stack1
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    // Push same elements onto stack2
    stack2.push(10);
    stack2.push(20);
    stack2.push(30);

    // Compare stacks
    if (stack1 == stack2) {
        std::cout << "The stacks are equal." << std::endl;
    }
    else {
        std::cout << "The stacks are not equal." << std::endl;
    }

    // Modify stack2
    stack2.pop();
    stack2.push(40);

    // Compare stacks again
    if (stack1 == stack2) {
        std::cout << "The stacks are equal." << std::endl;
    }
    else {
        std::cout << "The stacks are not equal." << std::endl;
    }

    return 0;
}
