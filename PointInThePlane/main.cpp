#include <iostream>
#include "PointInThePlane.h"

int main() {
    PointInThePlane point;

    point.print();
    std::cout<<point.quadrant();
    return 0;
}