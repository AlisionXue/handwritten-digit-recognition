#ifndef BINARY_TREE_TYPE_H
#define BINARY_TREE_TYPE_H

#include <iostream>

template <class T>
struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
};

template <class T>
class binaryTreeType {
public:
    binaryTreeType(); // 构造函数
    int nodeCount() const; // 计算节点数的函数
    void insert(const T& item); // 插入节点的函数

private:
    TreeNode<T>* root;
    int countNodes(TreeNode<T>* node) const; // 递归帮助函数
    void insertNode(TreeNode<T>*& node, const T& item); // 插入节点的递归帮助函数
};

#endif
