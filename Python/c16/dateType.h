#ifndef DATETYPE_H
#define DATETYPE_H

class dateType {
private:
    int day, month, year;

public:
    dateType(int d = 22, int m = 01, int y = 1999);
    void setDate(int d, int m, int y);   // 设置日期
    void printDate() const;              // 打印日期
};

#endif
