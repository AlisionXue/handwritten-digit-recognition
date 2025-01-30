#ifndef HASHTYPE_H
#define HASHTYPE_H

#include <string>
#include <vector>
#include <cmath>

using namespace std;

template <class ItemType>
class HashType {
public:
    HashType();
    HashType(int s, int factor);
    void MakeEmpty();
    bool IsFull() const;
    int GetNumItems() const;
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItemLinear(ItemType item);
    void InsertItemQuadratic(ItemType item);
    void DeleteItem(ItemType item);
    int Hash(string item) const;
    unsigned long int GetCollisions() const;

private:
    int a; // 多项式哈希函数中的 a 值
    int numItems;
    int size;
    vector<ItemType> info;
    ItemType emptyItem = ""; // 空字符串表示空位置
    unsigned long int numCollisions;
};

// 实现部分

template <class ItemType>
HashType<ItemType>::HashType() : size(101), a(33), numItems(0), numCollisions(0) {
    info.resize(size, emptyItem);
}

template <class ItemType>
HashType<ItemType>::HashType(int s, int factor) : size(s), a(factor), numItems(0), numCollisions(0) {
    info.resize(size, emptyItem);
}

template <class ItemType>
void HashType<ItemType>::MakeEmpty() {
    numItems = 0;
    numCollisions = 0;
    fill(info.begin(), info.end(), emptyItem);
}

template <class ItemType>
bool HashType<ItemType>::IsFull() const {
    return numItems == size;
}

template <class ItemType>
int HashType<ItemType>::GetNumItems() const {
    return numItems;
}

template <class ItemType>
void HashType<ItemType>::RetrieveItem(ItemType& item, bool& found) {
    int location = Hash(item);
    int originalLocation = location;
    found = false;

    for (int i = 0; i < size; i++) {
        if (info[location] == item) {
            found = true;
            item = info[location];
            return;
        }
        if (info[location] == emptyItem) {
            return;
        }
        location = (originalLocation + i) % size;
    }
}

template <class ItemType>
void HashType<ItemType>::InsertItemLinear(ItemType item) {
    int location = Hash(item);
    while (info[location] != emptyItem) {
        location = (location + 1) % size;
        numCollisions++;
    }
    info[location] = item;
    numItems++;
}

template <class ItemType>
void HashType<ItemType>::InsertItemQuadratic(ItemType item) {
    int location = Hash(item);
    int i = 1;
    while (info[location] != emptyItem) {
        location = (location + i * i) % size;
        i++;
        numCollisions++;
    }
    info[location] = item;
    numItems++;
}

template <class ItemType>
void HashType<ItemType>::DeleteItem(ItemType item) {
    bool found;
    RetrieveItem(item, found);
    if (found) {
        int location = Hash(item);
        info[location] = emptyItem;
        numItems--;
    }
}

template <class ItemType>
int HashType<ItemType>::Hash(string item) const {
    int hash = 0;
    for (char ch : item) {
        hash = a * hash + ch;
    }
    return abs(hash % size);
}

template <class ItemType>
unsigned long int HashType<ItemType>::GetCollisions() const {
    return numCollisions;
}

#endif
