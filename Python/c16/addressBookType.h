#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H

#include "extPersonType.h"
#include <list>
#include <string>
#include <iostream> // Added for input/output operations

class addressBookType {
private:
    std::list<extPersonType> entries;

public:
    void addEntry(const extPersonType& person);
    void deleteEntry(const std::string& lastName);
    void saveToFile(const std::string& filename) const;
    void loadDataFromFile(const std::string& filename);
    void sortByName();
    void printInfo(const std::string& lastName) const;
};

#endif
