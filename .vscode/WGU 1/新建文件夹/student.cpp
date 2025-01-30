#include <iostream>
#include "student.h"


Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
    this->degreeProgram = degreeProgram;
}


std::string Student::getStudentID() const { return this->studentID; }
std::string Student::getFirstName() const { return this->firstName; }
std::string Student::getLastName() const { return this->lastName; }
std::string Student::getEmailAddress() const { return this->emailAddress; }
int Student::getAge() const { return this->age; }
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() const { return this->degreeProgram; }


void Student::setStudentID(std::string studentID) { this->studentID = studentID; }
void Student::setFirstName(std::string firstName) { this->firstName = firstName; }
void Student::setLastName(std::string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(std::string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[]) {
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }


void Student::print() const {
    std::cout << this->studentID << "\t";
    std::cout << "First Name: " << this->firstName << "\t";
    std::cout << "Last Name: " << this->lastName << "\t";
    std::cout << "Age: " << this->age << "\t";
    std::cout << "daysInCourse: {" << this->daysInCourse[0] << ", " << this->daysInCourse[1] << ", " << this->daysInCourse[2] << "} ";
    std::cout << "Degree Program: " << degreeProgramToString(this->degreeProgram) << std::endl;
}
