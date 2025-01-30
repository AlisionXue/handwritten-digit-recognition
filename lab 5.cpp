#include <iostream>
#include <string>
#include <iomanip> // for setw

using namespace std;

void process(string name) {
    int count = 0;
    int frontNum = 1;
    int spaceLocation = name.find(' ');

    for (int i = 0; i < name.size(); i++) {
        if (i == spaceLocation) {
            frontNum = 2; // Start numbering for the last name with 2
        }
        else {
            cout << setw(frontNum) << frontNum << " " << char(toupper(name[i])) << endl;
            frontNum += 2; // Increment by 2 to get the next odd or even number
        }
    }
}

int main() {
    string name;
    cout << "Please enter your name: ";
    getline(cin, name);

    process(name);

    return 0;
}

