#include "addressBookType.h"
#include <fstream>
#include <iostream>

void addressBookType::addEntry(const extPersonType& person) {
    entries.push_back(person);
}

void addressBookType::deleteEntry(const std::string& lastName) {
    for (auto it = entries.begin(); it != entries.end(); ++it) {
        if (it->getLastName() == lastName) {
            entries.erase(it);
            std::cout << "Entry deleted for " << lastName << std::endl;
            return;
        }
    }
    std::cout << "Entry not found for " << lastName << std::endl;
}

void addressBookType::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "File could not be opened for writing." << std::endl;
        return;
    }

    for (const auto& person : entries) {
        outFile << person.getFirstName() << " "
            << person.getLastName() << " "
            << person.getRelationship() << " "
            << person.getPhoneNumber() << std::endl;
    }

    outFile.close();
    std::cout << "Data saved to " << filename << std::endl;
}

void addressBookType::loadDataFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "File could not be opened for reading." << std::endl;
        return;
    }

    std::string firstName, lastName, relationship, phoneNumber;
    while (inFile >> firstName >> lastName >> relationship >> phoneNumber) {
        extPersonType person;
        person.setPersonInfo(firstName, lastName, relationship, phoneNumber, addressType(), dateType());
        entries.push_back(person);
    }

    inFile.close();
}

void addressBookType::sortByName() {
    entries.sort();
}

void addressBookType::printInfo(const std::string& lastName) const {
    for (const auto& person : entries) {
        if (person.getLastName() == lastName) {
            person.printInfo();
            return;
        }
    }
    std::cout << "No entry found for " << lastName << std::endl;
}
