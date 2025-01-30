#ifndef STUDENTTYPE_H
#define STUDENTTYPE_H

#include <string>

class StudentType {
public:
    StudentType();
    StudentType(std::string name, int status);
    std::string GetName() const;
    int GetStatus() const;
    int ComparedTo(const StudentType& otherStudent) const;  
private:
    std::string name;
    int status;
};

#endif

