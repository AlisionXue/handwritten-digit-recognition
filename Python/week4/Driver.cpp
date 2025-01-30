#include <iostream>
#include "SortedType.h"
#include "ItemType.h"

using namespace std;

int main() {
    SortedType list;

    // Insert items to fill and resize the array
    for (int i = 1; i <= 20; i++) {
        ItemType item(i * 2);
        list.InsertItem(item);
    }

    cout << "List contents after inserting 20 items:" << endl;
    list.Print();

    cout << "Current length: " << list.GetLength() << endl;

    // Insert another item to trigger resizing
    ItemType extraItem(42);
    list.InsertItem(extraItem);

    cout << "List contents after inserting an additional item (trigger resize):" << endl;
    list.Print();

    cout << "Final length: " << list.GetLength() << endl;

    return 0;
}
