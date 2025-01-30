#include <iostream>
#include "roster.h"
#include "degree.h"

int main() {
    std::cout << "Course Title: Scripting and Programming - Applications ¡ª C867\nPRFA ¡ª JYM1\nProgramming Language: C++, WGU Student ID: 012313502, Name: Chang Xue" << std::endl;



    const std::string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "012313502,Chang,Xue,cxue1@wgu.edu,25,30,35,40,SOFTWARE"
    };

  
    Roster classRoster;

   
    for (int i = 0; i < 5; i++) {
        std::string data = studentData[i];
        size_t rhs = data.find(",");
        std::string studentID = data.substr(0, rhs);

        size_t lhs = rhs + 1;
        rhs = data.find(",", lhs);
        std::string firstName = data.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        std::string lastName = data.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        std::string emailAddress = data.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        int age = std::stoi(data.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        int daysInCourse1 = std::stoi(data.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        int daysInCourse2 = std::stoi(data.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        int daysInCourse3 = std::stoi(data.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        DegreeProgram degreeProgram = SOFTWARE;
        std::string degreeStr = data.substr(lhs);
        if (degreeStr == "SECURITY") degreeProgram = SECURITY;
        else if (degreeStr == "NETWORK") degreeProgram = NETWORK;

        classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }

  
    std::cout << "Print all students:" << std::endl;
    classRoster.printAll();

    std::cout << "\nPrint invalid emails:" << std::endl;
    classRoster.printInvalidEmails();

    std::cout << "\nPrint average days in course for each student:" << std::endl;
    for (int i = 0; i < 5; i++) {
      
        std::string studentID = classRoster.getStudentAt(i)->getStudentID();
        classRoster.printAverageDaysInCourse(studentID);
    }

    std::cout << "\nPrint students in the SOFTWARE degree program:" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);

    std::cout << "\nRemove student A3 and print all:" << std::endl;
    classRoster.remove("A3");
    classRoster.printAll();

    std::cout << "\nAttempt to remove student A3 again:" << std::endl;
    classRoster.remove("A3");

    return 0;
}
