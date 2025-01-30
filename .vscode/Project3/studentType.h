#ifndef STUDENTTYPE_H
#define STUDENTTYPE_H

#include <string>
using namespace std;

class studentType {
private:
    string firstName;
    string lastName;
    int age;
    double GPA;

public:
    studentType(string fName = "", string lName = "", int a = 0, double g = 0.0);
    void setStudentInfo(string fName, string lName, int a, double g);
    string getFirstName() const;
    string getLastName() const;
    int getAge() const;
    double getGPA() const;
    void printStudentInfo() const;
};

#endif
