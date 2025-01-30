#include "PersonType.h"

PersonType::PersonType() : name(""), age(0) {}

PersonType::PersonType(std::string name, int age) : name(name), age(age) {}

std::string PersonType::GetName() const {
    return name;
}

int PersonType::GetAge() const {
    return age;
}

void PersonType::SetName(std::string name) {
    this->name = name;
}

void PersonType::SetAge(int age) {
    this->age = age;
}
