#ifndef FRACTIONTYPE_H
#define FRACTIONTYPE_H

class FractionType {
public:
    FractionType();                               // Ĭ�Ϲ��캯��
    void Initialize(int numerator, int denominator);  // ��ʼ������

    FractionType operator+(const FractionType& addend) const;  // ����+
    FractionType operator-(const FractionType& subtrahend) const;  // ����-
    FractionType operator*(const FractionType& multiplier) const;  // ����*
    FractionType operator/(const FractionType& divisor) const;  // ����/

    void print() const;                          // �������

private:
    int num;  // ����
    int den;  // ��ĸ

    int gcd(int a, int b) const;  // �������Լ��
    void simplify();              // �������
};

#endif
