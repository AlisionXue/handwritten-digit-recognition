#include "personType.h"
#include <iostream>

personType::personType(std::string first, std::string last) : firstName(first), lastName(last) {}

void personType::setName(std::string first, std::string last) {
    firstName = first;
    lastName = last;
}

std::string personType::getFirstName() const {
    return firstName;
}

std::string personType::getLastName() const {
    return lastName;
}

void personType::printName() const {
    std::cout << firstName << " " << lastName << std::endl;
}
