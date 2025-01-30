#include "extClockType.h"
#include <iostream>
using namespace std;

int main() {
    extClockType clock(14, 30, 45, -5);  

    cout << "Initial time and time zone: ";
    clock.printTime();
    cout << endl;

    clock.incrementSeconds();
    cout << "After incrementing seconds: ";
    clock.printTime();
    cout << endl;

    
    clock.setTimeZone(3); 
    cout << "After changing time zone to UTC+3: ";
    clock.printTime();
    cout << endl;

    return 0;
}
