#include "StudentType.h"

StudentType::StudentType() : name(""), status(0) {}

StudentType::StudentType(std::string name, int status) : name(name), status(status) {}

std::string StudentType::GetName() const {
    return name;
}

int StudentType::GetStatus() const {
    return status;
}

int StudentType::ComparedTo(const StudentType& otherStudent) const {
    if (name == otherStudent.name) {
        return 1;
    }
    else if (name < otherStudent.name) {
        return -1;
    }
    else {
        return 0;
    }
}
