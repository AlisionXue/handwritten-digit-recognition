#include <iostream>
#include "FractionType.h"

using namespace std;

// Ĭ�Ϲ��캯��
FractionType::FractionType() : num(0), den(1) {}

// ��ʼ������
void FractionType::Initialize(int numerator, int denominator) {
    num = numerator;
    den = denominator;
    simplify();
}

// ���� + �����
FractionType FractionType::operator+(const FractionType& addend) const {
    FractionType result;
    result.num = num * addend.den + den * addend.num;
    result.den = den * addend.den;
    result.simplify();
    return result;
}

// ���� - �����
FractionType FractionType::operator-(const FractionType& subtrahend) const {
    FractionType result;
    result.num = num * subtrahend.den - den * subtrahend.num;
    result.den = den * subtrahend.den;
    result.simplify();
    return result;
}

// ���� * �����
FractionType FractionType::operator*(const FractionType& multiplier) const {
    FractionType result;
    result.num = num * multiplier.num;
    result.den = den * multiplier.den;
    result.simplify();
    return result;
}

// ���� / �����
FractionType FractionType::operator/(const FractionType& divisor) const {
    FractionType result;
    result.num = num * divisor.den;
    result.den = den * divisor.num;
    result.simplify();
    return result;
}

// ��ӡ����
void FractionType::print() const {
    cout << num << "/" << den << endl;
}

// �������Լ��
int FractionType::gcd(int a, int b) const {
    return (b == 0) ? a : gcd(b, a % b);
}

// �������
void FractionType::simplify() {
    int gcdValue = gcd(num, den);
    num /= gcdValue;
    den /= gcdValue;
}
