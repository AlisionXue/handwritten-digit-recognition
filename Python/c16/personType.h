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
    std::string getFirstName() const; // 获取名字
    std::string getLastName() const;  // 获取姓氏
    void printName() const;           // 打印姓名
};

#endif
