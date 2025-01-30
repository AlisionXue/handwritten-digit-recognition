#include "dateType.h"
#include <iostream>

dateType::dateType(int d, int m, int y) : day(d), month(m), year(y) {}

void dateType::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

void dateType::printDate() const {
    std::cout << month << "/" << day << "/" << year << std::endl;
}
