#ifndef POINTINTHEPLANE_POINTINTHEPLANE_H
#define POINTINTHEPLANE_POINTINTHEPLANE_H


class PointInThePlane {
private:
    double x, y;

public:

    /** Constructors **/

    // Default Constructor
    PointInThePlane();

    // Constructor with arguments
    PointInThePlane(double x, double y);

    /** Accessors **/

    // Getters for the coordinates
    double getX() const { return x; }
    double getY() const { return y; }

    // Distance from the origin
    double radius() const;

    // Distance to another point
    double distance(PointInThePlane p) const;

    // The quadrant of the point
    // Returns number 1 to 4
    // Returns -1 to -4 if on an axis
    // Returns 0 if point is on the origin
    short quadrant() const;

    // Display
    void print() const;

    /** Mutators **/

    // Translate by x, y or another point
    void translateX(double dx);
    void translateY(double dy);
    void translate(PointInThePlane const& v);

    // Input
    void read();

    // Symmetry on x = y
    void reflect();

    // Setters for the coordinates
    void setX(double x);
    void setY(double y);
};


#endif //POINTINTHEPLANE_POINTINTHEPLANE_H
