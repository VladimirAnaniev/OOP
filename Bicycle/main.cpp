#include <iostream>
#include "Quality.h"
#include "CyclePart.h"
#include "Bicycle.h"

int main() {
    CyclePart arr[3];
    arr[0] = CyclePart("chast", 20.9, High);
    arr[1] = CyclePart("Part", 8, Low);
    arr[2] = CyclePart("au", 9, High);
    Bicycle b("zzz", arr, 2);
    Bicycle b2("zzz", arr, 3);
    std::cout<<b.getPrice()<<std::endl;
    std::cout<<b.isLessThan(b2)<<std::endl;

    return 0;
}