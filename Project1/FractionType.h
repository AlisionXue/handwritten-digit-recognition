#ifndef FRACTIONTYPE_H
#define FRACTIONTYPE_H

class FractionType {
public:
    FractionType();                               // 默认构造函数
    void Initialize(int numerator, int denominator);  // 初始化函数

    FractionType operator+(const FractionType& addend) const;  // 重载+
    FractionType operator-(const FractionType& subtrahend) const;  // 重载-
    FractionType operator*(const FractionType& multiplier) const;  // 重载*
    FractionType operator/(const FractionType& divisor) const;  // 重载/

    void print() const;                          // 输出分数

private:
    int num;  // 分子
    int den;  // 分母

    int gcd(int a, int b) const;  // 计算最大公约数
    void simplify();              // 化简分数
};

#endif
