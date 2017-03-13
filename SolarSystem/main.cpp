#include <iostream>
#include "Planet.h"

int main() {
    Planet p;

    p.print();

    p.setName("Probbba");

    p.print();

    Planet p2("wot", 30, 40, 120, 123.56);

    std::cout << p2.getDistance() << std::endl;

    p2.print();

    p2.read();

    p = p2;
    p.print();

    return 0;
}