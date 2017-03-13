#include <iostream>
#include "Classes/Monster.h"

using namespace std;

int main() {
    Monster m("pedal", 10, 10, 1, 30);
    Monster m2("pedal2", 20, 2, 7, 50);
    m.print();

    m.fight(m2);

    m.print();
    m2.print();


    return 0;
}