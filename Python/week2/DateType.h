#ifndef DATETYPE_H
#define DATETYPE_H

class DateType {
public:
    DateType();
    DateType(int day, int month, int year);
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
    void SetDate(int day, int month, int year);
private:
    int day;
    int month;
    int year;
};

#endif
