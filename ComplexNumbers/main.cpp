#include <iostream>
#include "ComplexNumber.h"

int main() {
    ComplexNumber c1(3, 5);
    ComplexNumber c2;

    c2+=c1;
    ComplexNumber c3(7, 8);


    c1.print();
    c3 += c2+c1;
    c3.print();

    return 0;
}