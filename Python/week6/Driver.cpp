#include "LinkedQueueType.h"
#include <iostream>

int main() {
    LinkedQueueType queue;

    // Enqueue items to the queue
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);
    queue.Enqueue(50);

    std::cout << "Queue items using explicit iterator:" << std::endl;
    for (LinkedQueueTypeIterator iter = queue.begin(); iter != queue.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    std::cout << "Queue items using implicit iterator:" << std::endl;
    for (int& x : queue) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
