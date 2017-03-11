#include <cmath>
#include <iostream>
#include "PointInSpace.h"

PointInSpace::PointInSpace(PointInThePlane const &p, double z) {
    this->p = p;
    setZ(z);
}

PointInSpace::PointInSpace(double x, double y, double z) {
    setX(x);
    setY(y);
    setZ(z);
}

double PointInSpace::radius() const {
    return sqrt(p.radius() * p.radius() + z * z);
}

void PointInSpace::reflectOrigin() {
    p.reflect();
    setZ(-getZ());
}

void PointInSpace::translateX(double dx) {
    p.translateX(dx);
}

void PointInSpace::translateY(double dy) {
    p.translateY(dy);
}

void PointInSpace::translateZ(double dz) {
    setZ(getZ() + dz);
}

void PointInSpace::translate(PointInSpace const &v) {
    translateX(v.getX());
    translateY(v.getY());
    translateZ(v.getZ());
}

void PointInSpace::print() const {
    std::cout << '(' << getX() << ", " << getY() << ", " << getZ() << ')';
}

void PointInSpace::read() {
    double x, y, z;
    std::cin>>x>>y>>z;
    setX(x);
    setY(y);
    setZ(z);
}

double PointInSpace::distance(PointInSpace p) const {
    p.translateX(-getX());
    p.translateY(-getY());
    p.translateZ(-getZ());
    return p.radius();
}