#ifndef COMPLEXNUMBERS_COMPLEXNUMBER_H
#define COMPLEXNUMBERS_COMPLEXNUMBER_H


class ComplexNumber {
    float real;
    float imag;

    static float calcRealAddition(const ComplexNumber& c1, const ComplexNumber& c2);
    static float calcImagAddition(const ComplexNumber& c1, const ComplexNumber& c2);
    static float calcRealMultiplication(const ComplexNumber& c1, const ComplexNumber& c2);
    static float calcImagMultiplication(const ComplexNumber& c1, const ComplexNumber& c2);

public:
    ComplexNumber(float r = 0, float i = 0);
    ComplexNumber operator*(const ComplexNumber& other);
    ComplexNumber& operator*=(const ComplexNumber& other);
    ComplexNumber operator+(const ComplexNumber& other);
    ComplexNumber& operator+=(const ComplexNumber& other);

    void print();

};


#endif //COMPLEXNUMBERS_COMPLEXNUMBER_H
