#include <iostream>
using namespace std;

// Function to print a formatted monthly calendar
int printMonthCalendar(int numOfDays, int startingDay) {
    cout << "Mon Tue Wed Thu Fri Sat Sun" << endl;

    // Print initial spacing for the first week
    int currentDay = 1;
    for (int i = 1; i < startingDay; i++) {
        cout << "    "; // 4 spaces for empty days
    }

    // Print the days of the month
    for (int day = 1; day <= numOfDays; day++) {
        cout << (day < 10 ? "  " : " ") << day;
        if ((startingDay + day - 1) % 7 == 0) {
            cout << endl;  // Move to the next line after Sunday
        }
    }
    cout << endl;

    // Calculate and return the day of the week for the last day
    return (startingDay + numOfDays - 1) % 7 == 0 ? 7 : (startingDay + numOfDays - 1) % 7;
}

// Function to check if a year is a leap year
bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return (year % 400 == 0);
        }
        return true;
    }
    return false;
}

// Function to print a formatted yearly calendar
void printYearCalendar(int year, int startingDay) {
    const int daysInMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    const string months[12] = { "January", "February", "March", "April", "May", "June",
                               "July", "August", "September", "October", "November", "December" };

    int currentStartingDay = startingDay;

    // Adjust for leap year
    int adjustedDaysInMonths[12];
    for (int i = 0; i < 12; i++) {
        adjustedDaysInMonths[i] = daysInMonths[i];
    }
    if (isLeapYear(year)) {
        adjustedDaysInMonths[1] = 29;  // February has 29 days in a leap year
    }

    // Print each month
    for (int month = 0; month < 12; month++) {
        cout << months[month] << " " << year << endl;
        currentStartingDay = printMonthCalendar(adjustedDaysInMonths[month], currentStartingDay);
        cout << endl;
    }
}

int main() {
    int year, startingDay;

    // Prompt user for input
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the starting day of the week (1=Monday, ..., 7=Sunday): ";
    cin >> startingDay;

    // Print the calendar for the year
    printYearCalendar(year, startingDay);

    return 0;
}
