#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}

    void setTime(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    void print() const {
        std::cout << hour << ":" << minute << ":" << second << std::endl;
    }

private:
    int hour;
    int minute;
    int second;
};

#endif // TIME_H
#pragma once
