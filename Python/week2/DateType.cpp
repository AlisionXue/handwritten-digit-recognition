#include "DateType.h"

DateType::DateType() : day(1), month(1), year(2000) {}

DateType::DateType(int day, int month, int year) : day(day), month(month), year(year) {}

int DateType::GetDay() const {
    return day;
}

int DateType::GetMonth() const {
    return month;
}

int DateType::GetYear() const {
    return year;
}

void DateType::SetDate(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}
