#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"

class UnsortedType {
public:
    UnsortedType();                 // Constructor
    ~UnsortedType();                // Destructor

    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    void InsertItem(ItemType item);
    void Print() const;

    // SplitLists function as specified in Exercise 2
    void SplitLists(UnsortedType list, ItemType item, UnsortedType& list1, UnsortedType& list2);

    // Getter and Setter for isLinkedList
    bool GetIsLinkedList() const;      // ��� getter ��������
    void SetIsLinkedList(bool value);  // ��� setter ��������

private:
    static const int MAX_ITEMS = 50;
    ItemType info[MAX_ITEMS];
    int length;
    bool isLinkedList; // ���������Ƿ�Ϊ����
};

#endif
