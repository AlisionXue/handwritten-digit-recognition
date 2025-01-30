#include "extPersonType.h"
#include <iostream>

extPersonType::extPersonType(std::string first, std::string last, std::string rel, std::string phone)
    : personType(first, last), relationship(rel), phoneNumber(phone) {}

void extPersonType::setPersonInfo(std::string first, std::string last, std::string rel, std::string phone, addressType addr, dateType dob) {
    setName(first, last);
    relationship = rel;
    phoneNumber = phone;
    address = addr;
    dateOfBirth = dob;
}

// 在此处实现 getRelationship 和 getPhoneNumber
std::string extPersonType::getRelationship() const {
    return relationship;
}

std::string extPersonType::getPhoneNumber() const {
    return phoneNumber;
}

void extPersonType::printInfo() const {
    printName();
    std::cout << ", " << relationship << ", " << phoneNumber << std::endl;
    address.printAddress();
    dateOfBirth.printDate();
}

bool extPersonType::operator<(const extPersonType& other) const {
    return lastName < other.getLastName();
}
