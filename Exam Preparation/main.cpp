#include <iostream>
#include "Necklace/Necklace.h"

int main() {
    Necklace<int> neck;

    for(int i=1;i<=21;i++) {
        neck.insert(i);
    }

    std::cout<<neck;

    return 0;
}