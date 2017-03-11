#include <iostream>
using namespace std;
#include "PointInThePlane.h"
#include "PointInSpace.h"

void testPoint2D() {
    PointInThePlane p;
    PointInThePlane q(3, 4), r(7, 7);
    cout << p.radius() << ' ' << q.radius() << endl;
    cout << p.distance(q) << endl;
    cout << q.distance(r) << endl;
    q.translate(r);
    q.print();
    cout << endl;
    q.read();
    r.read();
    cout << q.distance(r) << endl;
}

void testPoint3D() {
    PointInSpace p;
    PointInSpace q(3, 4, 12);
    cout << q.radius() << endl;
    PointInSpace r(15, 7, 16);
    cout << q.distance(r) << endl;
}

int main() {
    testPoint2D();
    testPoint3D();
}