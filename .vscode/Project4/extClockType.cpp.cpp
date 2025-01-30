#include "extClockType.h"
#include <iostream>
using namespace std;

clockType::clockType(int hours, int minutes, int seconds) {
    hr = (hours >= 0 && hours < 24) ? hours : 0;
    min = (minutes >= 0 && minutes < 60) ? minutes : 0;
    sec = (seconds >= 0 && seconds < 60) ? seconds : 0;
}

void clockType::setTime(int hours, int minutes, int seconds) {
    hr = (hours >= 0 && hours < 24) ? hours : 0;
    min = (minutes >= 0 && minutes < 60) ? minutes : 0;
    sec = (seconds >= 0 && seconds < 60) ? seconds : 0;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const {
    hours = hr;
    minutes = min;
    seconds = sec;
}

void clockType::printTime() const {
    if (hr < 10)
        cout << "0";
    cout << hr << ":";
    if (min < 10)
        cout << "0";
    cout << min << ":";
    if (sec < 10)
        cout << "0";
    cout << sec;
}

void clockType::incrementSeconds() {
    sec++;
    if (sec > 59) {
        sec = 0;
        min++;
    }
    if (min > 59) {
        min = 0;
        hr++;
    }
    if (hr > 23) {
        hr = 0;
    }
}

bool clockType::equalTime(const clockType& otherClock) const {
    return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}

extClockType::extClockType(int hours, int minutes, int seconds, int tz)
    : clockType(hours, minutes, seconds) {
    timeZone = tz;
}

void extClockType::setTimeZone(int tz) {
    timeZone = tz;
}

int extClockType::getTimeZone() const {
    return timeZone;
}

void extClockType::printTime() const {
    clockType::printTime();
    cout << " UTC";
    if (timeZone >= 0)
        cout << "+";
    cout << timeZone;
}
