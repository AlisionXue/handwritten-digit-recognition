#ifndef EXTPERSONTYPE_H
#define EXTPERSONTYPE_H

#include "addressType.h"
#include "personType.h"
#include "dateType.h"
#include <string>

class extPersonType : public personType {
private:
    addressType address;
    dateType dateOfBirth;
    std::string relationship;
    std::string phoneNumber;

public:
    extPersonType(std::string first = "", std::string last = "", std::string rel = "Friend", std::string phone = "");

    void setPersonInfo(std::string first, std::string last, std::string rel, std::string phone, addressType addr, dateType dob);
    std::string getFirstName() const { return firstName; }
    std::string getFullName() const { return firstName + " " + lastName; }

    // 仅声明，不要定义
    std::string getRelationship() const;
    std::string getPhoneNumber() const;
    void printInfo() const;

    bool operator<(const extPersonType& other) const;
};

#endif
