#include <iostream>
#include "roman.h" // introduce roman.h heart file

using namespace std;

int main() {
    romanType romanNumber;
    string romanInput;
    char choice;

    do {
        cout << "Enter a Roman numeral: ";
        cin >> romanInput;

        // set roman
        romanNumber.setRoman(romanInput);

        cout << "Choose output format:\n";
        cout << "1. Roman numeral\n";
        cout << "2. Decimal number\n";
        cout << "Enter your choice (1 or 2): ";
        int formatChoice;
        cin >> formatChoice;

        // output using unser introduction
        if (formatChoice == 1) {
            romanNumber.printRoman();
        }
        else if (formatChoice == 2) {
            romanNumber.printDecimal();
        }
        else {
            cout << "Invalid choice.\n";
        }

        // ask user if continue
        cout << "Do you want to convert another number? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
