#include <iostream>
#include <stdexcept>
using namespace std;

// Conversion factor constants
const double FEET_TO_CM = 30.48;
const double INCH_TO_CM = 2.54;

// Function to convert feet and inches to centimeters
double convertToCentimeters(int feet, int inches) {
    return (feet * FEET_TO_CM) + (inches * INCH_TO_CM);
}

// Function to validate and input feet and inches
void inputLength(int& feet, int& inches) {
    while (true) {
        try {
            cout << "Enter length in feet: ";
            cin >> feet;
            if (cin.fail() || feet < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input. Feet must be a non-negative integer.");
            }

            cout << "Enter length in inches: ";
            cin >> inches;
            if (cin.fail() || inches < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input. Inches must be a non-negative integer.");
            }

            break; // Valid input received, exit the loop
        }
        catch (const invalid_argument& e) {
            cout << e.what() << " Please enter again.\n";
        }
    }
}

int main() {
    int feet, inches;

    inputLength(feet, inches);

    double centimeters = convertToCentimeters(feet, inches);
    cout << "Equivalent length in centimeters: " << centimeters << " cm" << endl;

    return 0;
}
