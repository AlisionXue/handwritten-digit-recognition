#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>

class personType {
protected:
    std::string firstName;
    std::string lastName;

public:
    personType(std::string first = "", std::string last = "");

    void setName(std::string first, std::string last);
    std::string getFirstName() const; // ��ȡ����
    std::string getLastName() const;  // ��ȡ����
    void printName() const;           // ��ӡ����
};

#endif
