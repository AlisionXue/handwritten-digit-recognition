#include <iostream>
#include "FractionType.h"

using namespace std;

// 默认构造函数
FractionType::FractionType() : num(0), den(1) {}

// 初始化函数
void FractionType::Initialize(int numerator, int denominator) {
    num = numerator;
    den = denominator;
    simplify();
}

// 重载 + 运算符
FractionType FractionType::operator+(const FractionType& addend) const {
    FractionType result;
    result.num = num * addend.den + den * addend.num;
    result.den = den * addend.den;
    result.simplify();
    return result;
}

// 重载 - 运算符
FractionType FractionType::operator-(const FractionType& subtrahend) const {
    FractionType result;
    result.num = num * subtrahend.den - den * subtrahend.num;
    result.den = den * subtrahend.den;
    result.simplify();
    return result;
}

// 重载 * 运算符
FractionType FractionType::operator*(const FractionType& multiplier) const {
    FractionType result;
    result.num = num * multiplier.num;
    result.den = den * multiplier.den;
    result.simplify();
    return result;
}

// 重载 / 运算符
FractionType FractionType::operator/(const FractionType& divisor) const {
    FractionType result;
    result.num = num * divisor.den;
    result.den = den * divisor.num;
    result.simplify();
    return result;
}

// 打印分数
void FractionType::print() const {
    cout << num << "/" << den << endl;
}

// 计算最大公约数
int FractionType::gcd(int a, int b) const {
    return (b == 0) ? a : gcd(b, a % b);
}

// 化简分数
void FractionType::simplify() {
    int gcdValue = gcd(num, den);
    num /= gcdValue;
    den /= gcdValue;
}
