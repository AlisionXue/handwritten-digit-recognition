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
    binaryTreeType(); // ���캯��
    int nodeCount() const; // ����ڵ����ĺ���
    void insert(const T& item); // ����ڵ�ĺ���

private:
    TreeNode<T>* root;
    int countNodes(TreeNode<T>* node) const; // �ݹ��������
    void insertNode(TreeNode<T>*& node, const T& item); // ����ڵ�ĵݹ��������
};

#endif
