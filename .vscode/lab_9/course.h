#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

class Course {
public:
    Course() : name("Undefined"), hours(0), grade('U') {} // Default constructor
    Course(const std::string& name, int hours) : name(name), hours(hours), grade('U') {} // Constructor

    void changeGrade(char g) { grade = g; }
    char getGrade() const { return grade; }
    int getHours() const { return hours; }

    friend std::ostream& operator<<(std::ostream& os, const Course& c);

private:
    std::string name;
    int hours;
    char grade;
};

std::ostream& operator<<(std::ostream& os, const Course& c) {
    os << c.name << " (" << c.hours << " credit hours) - Grade: " << c.grade;
    return os;
}

#endif

