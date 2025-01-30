#include "roman.h"
#include <iostream>
#include <map>
#include <cctype>

using namespace std;


romanType::romanType() : romanNum(""), decimalNum(0) {}

romanType::romanType(const string& roman) {
    setRoman(roman);
}

void romanType::setRoman(const string& roman) {
    romanNum = roman;
    romanToDecimal();
}


void romanType::printRoman() const {
    cout << "Roman Numeral: " << romanNum << endl;
}

// print transfer
void romanType::printDecimal() const {
    cout << "Decimal Number: " << decimalNum << endl;
}

// transfer roman
void romanType::romanToDecimal() {
   
    map<char, int> romanValues = {
        {'M', 1000}, {'D', 500}, {'C', 100},
        {'L', 50},   {'X', 10},  {'V', 5}, {'I', 1}
    };

    int total = 0;
    int prevValue = 0;

   
    for (int i = romanNum.length() - 1; i >= 0; i--) {
        char c = toupper(romanNum[i]);
        int value = romanValues[c];

        if (value < prevValue) {
            total -= value; 
        }
        else {
            total += value; 
        }

        prevValue = value;
    }

    decimalNum = total;  
}
