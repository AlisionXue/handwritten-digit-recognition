#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H

#include <string>
using namespace std;

class addressType {
private:
    string streetAddress, city, state;
    int zipCode;

public:
    addressType(string street = "", string city = "", string state = "", int zip = 0);
    void setAddress(string street, string city, string state, int zip);
    void printAddress() const;
};

#endif
