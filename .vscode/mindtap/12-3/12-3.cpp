#include <iostream>
#include <vector>
#include <string> // Add this header for getline function
using namespace std;

class Course {
protected:
    string courseId;
    string title;
    string roomNumber;
    int contactHours;

public:
    Course(string id, string t, string room, int hours) : courseId(id), title(t), roomNumber(room), contactHours(hours) {}
    virtual void show() const = 0; // Pure virtual function
    virtual ~Course() {}
};

class CurriculumCourse : public Course {
private:
    int creditHours;
    double tuitionRate;

public:
    CurriculumCourse(string id, string t, string room, int hours, int credits, double rate)
        : Course(id, t, room, hours), creditHours(credits), tuitionRate(rate) {}

    void show() const override {
        cout << "Curriculum Course: " << title << endl;
        cout << "Course ID: " << courseId << ", Room: " << roomNumber << ", Contact Hours: " << contactHours << endl;
        cout << "Credit Hours: " << creditHours << ", Tuition Rate: " << tuitionRate << endl;
        cout << "Total Tuition: " << creditHours * tuitionRate << endl;
    }
};

class ContinuingEducationCourse : public Course {
private:
    double flatFee;

public:
    ContinuingEducationCourse(string id, string t, string room, int hours, double fee)
        : Course(id, t, room, hours), flatFee(fee) {}

    void show() const override {
        cout << "Continuing Education Course: " << title << endl;
        cout << "Course ID: " << courseId << ", Room: " << roomNumber << ", Contact Hours: " << contactHours << endl;
        cout << "Flat Fee: " << flatFee << endl;
    }
};

int main() {
    vector<Course*> courses;
    int choice;
    do {
        cout << "Main Menu\n";
        cout << "1. Add a curriculum class to schedule\n";
        cout << "2. Add a continuing education class to schedule\n";
        cout << "3. Display all records\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string id, title, room;
            int contactHours, creditHours;
            double tuitionRate;
            cout << "Enter Course ID: ";
            cin >> id;
            cout << "Enter Course Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Room Number: ";
            cin >> room;
            cout << "Enter Contact Hours: ";
            cin >> contactHours;
            cout << "Enter Credit Hours: ";
            cin >> creditHours;
            cout << "Enter Tuition Rate: ";
            cin >> tuitionRate;
            courses.push_back(new CurriculumCourse(id, title, room, contactHours, creditHours, tuitionRate));
            break;
        }
        case 2: {
            string id, title, room;
            int contactHours;
            double flatFee;
            cout << "Enter Course ID: ";
            cin >> id;
            cout << "Enter Course Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Room Number: ";
            cin >> room;
            cout << "Enter Contact Hours: ";
            cin >> contactHours;
            cout << "Enter Flat Fee: ";
            cin >> flatFee;
            courses.push_back(new ContinuingEducationCourse(id, title, room, contactHours, flatFee));
            break;
        }
        case 3: {
            for (const auto& course : courses) {
                course->show();
                cout << "--------------------\n";
            }
            break;
        }
        case 4: {
            cout << "Exiting...\n";
            break;
        }
        default: {
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    } while (choice != 4);

    // Clean up dynamically allocated memory
    for (auto& course : courses) {
        delete course;
    }

    return 0;
}