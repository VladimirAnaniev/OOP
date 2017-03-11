#include <cmath>
#include <iostream>
#include "PointInThePlane.h"

PointInThePlane::PointInThePlane() {
    this->x = 0;
    this->y = 0;
}

PointInThePlane::PointInThePlane(double x, double y) {
    this->x = x;
    this->y = y;
}

double PointInThePlane::radius() const {
    return sqrt(getX() * getX() + getY() * getY());
}

void PointInThePlane::translateX(double dx) {
    this->x += dx;
}

void PointInThePlane::translateY(double dy) {
    this->y += dy;
}

void PointInThePlane::translate(PointInThePlane const &v) {
    translateX(v.getX());
    translateY(v.getY());
}

void PointInThePlane::setX(double x) {
    this->x = x;
}

void PointInThePlane::setY(double y) {
    this->y = y;
}

short PointInThePlane::quadrant() const {
    if (getX() == 0) {
        if (getY() == 0) {
            return 0;
        } else if (getY() > 0) {
            return -2;
        } else if (getY() < 0) {
            return -4;
        }
    } else if (getX() > 0) {
        if (getY() == 0) {
            return -1;
        } else if (getY() > 0) {
            return 1;
        } else if (getY() < 0) {
            return 4;
        }
    } else if (getX() < 0) {
        if (getY() == 0) {
            return -3;
        } else if (getY() > 0) {
            return 2;
        } else if (getY() < 0) {
            return 3;
        }
    }
}

void PointInThePlane::read() {
    int x, y;
    std::cin >> x >> y;
    setX(x);
    setY(y);
}

void PointInThePlane::print() const {
    std::cout << "(" << getX() << ", " << getY() << ")" << std::endl;
}

double PointInThePlane::distance(PointInThePlane p) const {
    p.translateX(-getX());
    p.translateY(-getY());
    return p.radius();
}

void PointInThePlane::reflect() {
    double x = getX();
    setX(getY());
    setY(x);
}

