#ifndef SOLARSYSTEM_SOLARSYSTEM_H
#define SOLARSYSTEM_SOLARSYSTEM_H
#include "Planet.h"

class SolarSystem {
    char* name;
    Planet* planets;
    int count;

public:
    SolarSystem(const char* name = "Milky Way", Planet* planets = nullptr, int count = 0);
    SolarSystem(const SolarSystem& system);

    void setName(const char* name);
    void setPlanets(const Planet* planets, int count);

    const Planet* getPlanets() const;
    int getCount() const;
    const char* getName() const;

    ~SolarSystem();
};


#endif //SOLARSYSTEM_SOLARSYSTEM_H
