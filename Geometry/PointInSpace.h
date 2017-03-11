#ifndef POINTINTHEPLANE_POINTINSPACE_H
#define POINTINTHEPLANE_POINTINSPACE_H

#include "PointInThePlane.h"


class PointInSpace {
private:
    PointInThePlane p;
    double z;

public:

    /** Constructors **/

    PointInSpace(PointInThePlane const& p, double z = 0);
    PointInSpace(double x = 0, double y = 0, double z = 0);

    /** Accessors **/

    // Getters for coordinates
    double getX() const { return p.getX(); }
    double getY() const { return p.getY(); }
    double getZ() const { return z; }

    // Distance to the origin
    double radius() const;

    // Distance between 2 points
    double distance(PointInSpace p) const;

    // Output
    void print() const;

    /** Mutators **/

    // Translate by all coordinates
    void translateX(double dx);
    void translateY(double dy);
    void translateZ(double dz);
    void translate(PointInSpace const& v);

    // Input
    void read();

    // Symmetry to the origin
    void reflectOrigin();

    // Setters for all coordinates
    void setX(double x) { p.setX(x); }
    void setY(double y) { p.setY(y); }
    void setZ(double z) { this->z = z; }
};


#endif //POINTINTHEPLANE_POINTINSPACE_H
