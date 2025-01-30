#ifndef ROMAN_H
#define ROMAN_H

#include <string>

class romanType {
public:
    romanType();  // default build function
    romanType(const std::string& roman);  // build function with paremeters

    void setRoman(const std::string& roman);  // build roman number
    void printRoman() const;  // print roman number
    void printDecimal() const;  // print decimal number 

private:
    std::string romanNum;  // storage roman number 
    int decimalNum;  // storage decimal number

    void romanToDecimal();  // transfer roman number to decimal number
};

#endif // ROMAN_H
#pragma once
