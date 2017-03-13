#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "Planet.h"

void Planet::setName(const char *name) {
    if (this->name != NULL) delete this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Planet::Planet(const char *name, int x, int y, int z, double diameter) {
    this->name = NULL;
    this->setName(name);
    this->setCoordinates(x, y, z);
    this->setDiameter(diameter);
}

Planet::Planet(const char *name, const int coords[3], double diameter) {
    this->name = NULL;
    this->setName(name);
    this->setCoordinates(coords);
    this->setDiameter(diameter);
}

Planet::~Planet() {
    delete this->name;
}

double Planet::getDistance() const {
    return sqrt(this->getX() * this->getX() +
                this->getY() * this->getY() +
                this->getZ() * this->getZ());
}

void Planet::setCoordinates(int x, int y, int z) {
    this->setX(x);
    this->setY(y);
    this->setZ(z);
}

Planet::Planet(const Planet &planet) {
    this->setName(planet.getName());
    this->setCoordinates(planet.getCoordinates());
    this->setDiameter(planet.getDiameter());
}

Planet &Planet::operator=(const Planet &newPlanet) {
    if (this != &newPlanet) {
        this->setName(newPlanet.getName());
        this->setCoordinates(newPlanet.getCoordinates());
        this->setDiameter(newPlanet.getDiameter());
    }
    return *this;
}

void Planet::setCoordinates(const int *coords) {
    this->setCoordinates(coords[0], coords[1], coords[2]);
}

void Planet::print() const {
    std::cout << std::fixed << std::setprecision(5) << "Planet " << this->getName()
              << " with coordinates ("
              << this->getX() << ", " << this->getY() << ", " << this->getZ()
              << ") and diameter " << this->getDiameter() << std::endl;
}

void Planet::read() {
    char name[64];
    int x, y, z;
    double diameter;

    std::cin.getline(name, 64);
    std::cin >> x >> y >> z >> diameter;

    this->setName(name);
    this->setCoordinates(x, y, z);
    this->setDiameter(diameter);
}