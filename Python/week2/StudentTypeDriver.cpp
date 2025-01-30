#include "unsorted.h"
#include "StudentType.h"
#include <iostream>

int main() {

    StudentType student1("Jim", 2);
    StudentType student2("Ivan", 1);

    std::cout << "Compare student1 to student1: " << student1.ComparedTo(student1) << std::endl;
    std::cout << "Compare student1 to student2: " << student1.ComparedTo(student2) << std::endl;

    {
        UnsortedType list0;
        list0.InsertItem(student1);
        list0.InsertItem(student2);
        std::cout << "Print list 0:" << std::endl;
        list0.Print();
    }

    {
        UnsortedType list1;
        list1.InsertItem(student1);
        std::cout << "Print list 1:" << std::endl;
        list1.Print();
    }

    {
        UnsortedType list2;
        StudentType student3("Billy", 0);
        list2.InsertItem(student3);
        list2.InsertItem(student1);
        std::cout << "Print list 2:" << std::endl;
        list2.Print();
    }

    {
        UnsortedType list3;
        std::cout << "Print list 3:" << std::endl;
        list3.Print();
    }

    return 0;
}
