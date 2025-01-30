#ifndef EXTCLOCKTYPE_H
#define EXTCLOCKTYPE_H

class clockType {
protected:
    int hr;
    int min;
    int sec;

public:
    clockType(int hours = 0, int minutes = 0, int seconds = 0);

    void setTime(int hours, int minutes, int seconds);

    void getTime(int& hours, int& minutes, int& seconds) const;

    void printTime() const;

    
    void incrementSeconds();

    
    bool equalTime(const clockType& otherClock) const;
};

class extClockType : public clockType {
private:
    int timeZone;  

public:
    
    extClockType(int hours = 0, int minutes = 0, int seconds = 0, int tz = 0);

    
    void setTimeZone(int tz);

   
    int getTimeZone() const;

    
    void printTime() const;
};

#endif
#pragma once
