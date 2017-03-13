#ifndef SOLARSYSTEM_PLANET_H
#define SOLARSYSTEM_PLANET_H

class Planet {
    char *name;
    int coords[3];
    double diameter;

public:
    /* Constructors */
    Planet(const char *name = "pedal", int x = 0, int y = 0, int z = 0, double diameter = 0);

    Planet(const char *name, const int coords[3], double diameter);

    Planet(const Planet &planet);


    /* Destructor */
    ~Planet();

    /* Accessors */
    const char *getName() const {return this->name;}

    int getX() const { return this->coords[0]; }

    int getY() const { return this->coords[1]; }

    int getZ() const { return this->coords[2]; }

    const int* getCoordinates() const {return this->coords;}

    double getDiameter() const { return this->diameter; }

    double getDistance() const;

    void print() const; //Output

    /* Mutators */
    void setName(const char *name);

    void setCoordinates(int x, int y, int z);
    void setCoordinates(const int coords[3]);

    void setX(int x) { this->coords[0] = x; }

    void setY(int y) { this->coords[1] = y; }

    void setZ(int z) { this->coords[2] = z; }

    void setDiameter(double diam) { this->diameter = diameter; }

    void read(); //Input


    /* Operations */
    Planet& operator= (const Planet& newPlanet);

};


#endif //SOLARSYSTEM_PLANET_H
