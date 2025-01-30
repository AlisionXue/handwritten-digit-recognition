#include "roster.h"
#include <iostream>


void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}


void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete classRosterArray[i];
            for (int j = i; j < lastIndex; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            lastIndex--;
            std::cout << "Student with ID " << studentID << " removed." << std::endl;
            return;
        }
    }
    if (!found) {
        std::cout << "Student with ID " << studentID << " not found." << std::endl;
    }
}


void Roster::printAll() {
    for (int i = 0; i <= lastIndex; i++) {
        classRosterArray[i]->print();
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; i++) {
        std::string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
            std::cout << "Invalid email: " << email << std::endl;
        }
    }
}


void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysInCourse();
            std::cout << "Average days for " << studentID << ": " << (days[0] + days[1] + days[2]) / 3 << std::endl;
            return;
        }
    }
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}


Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete classRosterArray[i];
    }
}
