#include "Student.h"
#include "Course.h"

int main() {
    Student s1("John Doe", "1234 Road St.");
    Course c1("Mathematics", 3), c2("English", 2);

    c1.changeGrade('A');
    c2.changeGrade('B');

    s1.addCourse(c1);
    s1.addCourse(c2);

    std::cout << s1 << std::endl;

    return 0;
}
