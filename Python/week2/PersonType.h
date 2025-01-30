#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>

class PersonType {
public:
    PersonType();
    PersonType(std::string name, int age);
    std::string GetName() const;
    int GetAge() const;
    void SetName(std::string name);
    void SetAge(int age);
private:
    std::string name;
    int age;
};

#endif
