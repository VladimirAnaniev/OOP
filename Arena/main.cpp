#include <iostream>
#include "Classes/Monster.h"

using namespace std;

int main() {
    Monster m("ppp", 10, 10, 1, 30);
    Monster m2("zzz", 20, 2, 7, 50);
    //m.print();

    m.fight(m2).print();

    Monster winner = m2.fight(m);

    winner.print();
//
//    m = m;
//    m.print();

    //m.print();
    //m2.print();


    return 0;
}