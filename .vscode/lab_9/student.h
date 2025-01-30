#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class Student {
public:
    Student() : name("Unnamed"), address("Unknown") {}
    Student(const std::string& name, const std::string& address) : name(name), address(address) {}

    void addCourse(const Course& course) { courses.push_back(course); }
    void setAddress(const std::string& addr) { address = addr; }
    double gpa_calc() const; // Calculate GPA based on courses and grades
    void gpa_override(double newGpa) { gpa = newGpa; }

    friend std::ostream& operator<<(std::ostream& os, const Student& s);

private:
    std::string name;
    std::string address;
    std::vector<Course> courses;
    double gpa;

    void print() const;
};

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Student: " << s.name << "\nAddress: " << s.address << "\nCourses:\n";
    for (const auto& course : s.courses) {
        os << course << "\n";
    }
    os << "Current GPA: " << std::fixed << std::setprecision(2) << s.gpa_calc();
    return os;
}

double Student::gpa_calc() const {
    // Dummy GPA calculation as example
    return 4.0; // Replace with actual calculation logic
}

#endif
#pragma once
