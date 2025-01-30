#include "studentType.h"
#include <iostream>
using namespace std;

studentType::studentType(string fName, string lName, int a, double g) {
    firstName = fName;
    lastName = lName;
    age = a;
    GPA = g;
}

void studentType::setStudentInfo(string fName, string lName, int a, double g) {
    firstName = fName;
    lastName = lName;
    age = a;
    GPA = g;
}

string studentType::getFirstName() const {
    return firstName;
}

string studentType::getLastName() const {
    return lastName;
}

int studentType::getAge() const {
    return age;
}

double studentType::getGPA() const {
    return GPA;
}

void studentType::printStudentInfo() const {
    cout << "Student Name: " << firstName << " " << lastName << endl;
    cout << "Age: " << age << endl;
    cout << "GPA: " << GPA << endl;
}
