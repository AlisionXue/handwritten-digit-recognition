#include "studentType.h"
#include <iostream>
using namespace std;

int main() {
    studentType student1;
    student1.setStudentInfo("Chang", "Xue", 25, 3.8);

    cout << "Displaying student information:" << endl;
    student1.printStudentInfo();

    return 0;
}
