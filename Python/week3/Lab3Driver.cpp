#include <iostream>
#include "unsorted.h"
#include "ItemType.h"

using namespace std;

int main() {
    UnsortedType classList;

    classList.PutItem(ItemType(4));
    classList.PutItem(ItemType(5));
    classList.PutItem(ItemType(4));
    classList.PutItem(ItemType(4));
    classList.PutItem(ItemType(8));

    cout << "(original) length: " << classList.GetLength() << endl;
    classList.Print();

    classList.ShiftRight();
    cout << "(shifted right) length: " << classList.GetLength() << endl;
    classList.Print();

    classList.DeleteItem(ItemType(4));
    cout << "(delete all 4s) length: " << classList.GetLength() << endl;
    classList.Print();

    classList.ShiftRight();
    cout << "(shift right) length: " << classList.GetLength() << endl;
    classList.Print();

    return 0;
}
