#include <iostream>
#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(float r, float i) : real(r), imag(i) {}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &other) {
    float newReal = calcRealMultiplication(*this, other);
    float newImag = calcImagMultiplication(*this, other);
    return ComplexNumber(newReal, newImag);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &other) {
    float newReal = this->ca
    float newImag = this->imag + other.imag;
    return ComplexNumber(newReal, newImag);
}

void ComplexNumber::print() {
    std::cout << this->real << " + " << this->imag << "i" << std::endl;
}

ComplexNumber &ComplexNumber::operator+=(const ComplexNumber &other) {
    this->real += other.real;
    this->imag += other.imag;
    return *this;
}

ComplexNumber &ComplexNumber::operator*=(const ComplexNumber &other) {
    this->real = this->real * other.real + this->imag * other.imag;
    this->imag = this->real * other.imag + this->imag * other.real;
    return *this;
}

float ComplexNumber::calcImagMultiplication(const ComplexNumber &c1, const ComplexNumber &c2) {
    return c1.real * c2.imag + c1.imag * c2.real;
}

float ComplexNumber::calcRealMultiplication(const ComplexNumber &c1, const ComplexNumber &c2) {
    return c1.real * c2.real + c1.imag * c2.imag;
}

float ComplexNumber::calcRealAddition(const ComplexNumber &c1, const ComplexNumber &c2) {
    return c1.real + c2.real;
}

float ComplexNumber::calcImagAddition(const ComplexNumber &c1, const ComplexNumber &c2) {
    return c1.imag + c2.imag;
}