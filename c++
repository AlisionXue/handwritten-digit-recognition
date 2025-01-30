#include <iostream>
#include <vector>
using namespace std;

bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

int main() {
    vector<int> years;
    int year;

    cout << "Enter years (enter -1 to stop): " << endl;
    while (true) {
        cin >> year;
        if (year == -1) break; // 输入-1停止输入
        years.push_back(year);
    }

    cout << "Leap year results:" << endl;
    for (int y : years) {
        if (isLeapYear(y)) {
            cout << y << " is a leap year." << endl;
        } else {
            cout << y << " is not a leap year." << endl;
        }
    }

    return 0;
}
