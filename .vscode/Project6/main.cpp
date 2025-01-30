#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <stdexcept>

// Exception classes
class invalidDay : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid day entered. Please enter a valid day.";
    }
};

class invalidMonth : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid month entered. Please enter a valid month.";
    }
};

class invalidYear : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid year entered. Please enter a year between 150 years ago and the current year.";
    }
};

// Month names
static std::string getMonthName(int month) {
    static const std::string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    return months[month - 1];
}

// Function to process the user input and convert date
static std::string convertDate(std::string dateOfBirth, std::vector<int>& years) {
    int month, day, year;
    char dash1, dash2;

    std::istringstream dateStream(dateOfBirth);
    dateStream >> month >> dash1 >> day >> dash2 >> year;

    // Validate input format
    if (dash1 != '-' || dash2 != '-') {
        throw std::invalid_argument("Invalid date format. Please use MM-DD-YYYY.");
    }

    // Validate month
    if (month < 1 || month > 12) {
        throw invalidMonth();
    }

    // Validate day
    if (day < 1 || day > 31) {
        throw invalidDay();
    }

    // Check for specific months with fewer than 31 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        throw invalidDay();
    }

    // Check for February (no leap year logic for simplicity)
    if (month == 2 && day > 28) {
        throw invalidDay();
    }

    // Validate year
    time_t t = time(0);
    tm now;
    localtime_s(&now, &t);
    int currentYear = now.tm_year + 1900;
    if (year < currentYear - 150 || year > currentYear) {
        throw invalidYear();
    }

    // Store valid year
    years.push_back(year);

    // Convert and return formatted date
    return getMonthName(month) + " " + std::to_string(day) + ", " + std::to_string(year);
}

int main() {
    std::vector<int> years;
    std::string dateOfBirth;
    int count = 0;

    while (count < 10) {
        try {
            std::cout << "Enter date of birth (MM-DD-YYYY): ";
            std::cin >> dateOfBirth;
            std::string formattedDate = convertDate(dateOfBirth, years);
            std::cout << "Formatted Date: " << formattedDate << std::endl;
            count++;
        }
        catch (const invalidDay& e) {
            std::cout << e.what() << std::endl;
        }
        catch (const invalidMonth& e) {
            std::cout << e.what() << std::endl;
        }
        catch (const invalidYear& e) {
            std::cout << e.what() << std::endl;
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }

    // Sort and display years
    std::sort(years.begin(), years.end());
    std::cout << "\nSorted Years of Birth: " << std::endl;
    for (int year : years) {
        std::cout << year << std::endl;
    }

    return 0;
}