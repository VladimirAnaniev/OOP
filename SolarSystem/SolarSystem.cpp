#include <cstring>
#include "SolarSystem.h"

SolarSystem::SolarSystem(const char *name, Planet *planets, int count) : name(nullptr), planets(nullptr), count(count) {
    this->setName(name);
    this->setPlanets(planets, count);
}

void SolarSystem::setName(const char *name) {
    if (this->name != nullptr) delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void SolarSystem::setPlanets(const Planet *planets, int count) {
    if (this->planets != nullptr) delete[] this->planets;
    this->planets = new Planet[count];
    for(int i=0;i<count;i++) {
        this->planets[i] = planets[i];
    }
}

SolarSystem::SolarSystem(const SolarSystem &system) : name(nullptr), planets(nullptr) {
    this->setName(system.getName());
    this->setPlanets(system.getPlanets(), system.getCount());
    this->count = system.count;
}

int SolarSystem::getCount() const { return this->count; }

const char* SolarSystem::getName() const {
    return this->name;
}

const Planet* SolarSystem::getPlanets() const {
    return this->planets;
}

SolarSystem::~SolarSystem() {
    delete[] this->name;
    delete[] this->planets;
}
