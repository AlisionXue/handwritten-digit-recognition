#include <iostream>
#include <string>
using namespace std;

template <class ItemType>
struct TreeNode {
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

template <class ItemType>
class TreeType {
public:
    TreeType(); 
    ~TreeType(); 
    void PutItem(ItemType item);
    string Ancestors(ItemType item) const; 

private:
    TreeNode<ItemType>* root;
    void PutItemHelper(TreeNode<ItemType>*& node, ItemType item);
    string AncestorsHelper(TreeNode<ItemType>* node, ItemType item) const;
    void Destroy(TreeNode<ItemType>*& node);
};

template <class ItemType>
TreeType<ItemType>::TreeType() {
    root = nullptr;
}

template <class ItemType>
TreeType<ItemType>::~TreeType() {
    Destroy(root);
}

template <class ItemType>
void TreeType<ItemType>::Destroy(TreeNode<ItemType>*& node) {
    if (node != nullptr) {
        Destroy(node->left);
        Destroy(node->right);
        delete node;
        node = nullptr;
    }
}

template <class ItemType>
void TreeType<ItemType>::PutItem(ItemType item) {
    PutItemHelper(root, item);
}

template <class ItemType>
void TreeType<ItemType>::PutItemHelper(TreeNode<ItemType>*& node, ItemType item) {
    if (node == nullptr) {
        node = new TreeNode<ItemType>;
        node->info = item;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (item < node->info) {
        PutItemHelper(node->left, item);
    }
    else {
        PutItemHelper(node->right, item);
    }
}

template <class ItemType>
string TreeType<ItemType>::Ancestors(ItemType item) const {
    return AncestorsHelper(root, item);
}

template <class ItemType>
string TreeType<ItemType>::AncestorsHelper(TreeNode<ItemType>* node, ItemType item) const {
    if (node == nullptr) {
        return "";
    }

    if (node->info == item) {
        return "";
    }

    string leftResult = AncestorsHelper(node->left, item);
    if (!leftResult.empty() || (node->left && node->left->info == item)) {
        return node->info + " " + leftResult;
    }

    string rightResult = AncestorsHelper(node->right, item);
    if (!rightResult.empty() || (node->right && node->right->info == item)) {
        return node->info + " " + rightResult;
    }

    return "";
}

int main() {
    TreeType<string> tree;
    tree.PutItem("J");
    tree.PutItem("P");
    tree.PutItem("S");
    tree.PutItem("U");
    tree.PutItem("T");

    string ancestors = tree.Ancestors("T");
    if (!ancestors.empty()) {
        cout << "Ancestors of T: " << ancestors << endl;
    }
    else {
        cout << "No ancestors found for T." << endl;
    }

    return 0;
}
