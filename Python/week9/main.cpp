#include <iostream>
#include "binaryTreeType.h"

int main() {
    binaryTreeType<int> tree;

    int numNodes;
    std::cout << "Enter the number of nodes you want to insert: ";
    std::cin >> numNodes;

    std::cout << "Enter the values of the nodes: ";
    for (int i = 0; i < numNodes; ++i) {
        int value;
        std::cin >> value;
        tree.insert(value);
    }

    // 计算并显示节点数
    int numNodesInTree = tree.nodeCount();
    std::cout << "Number of nodes in the binary tree: " << numNodesInTree << std::endl;

    return 0;
}
