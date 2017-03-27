#ifndef BYCICLE_CYCLEPART_H
#define BYCICLE_CYCLEPART_H

#include "Quality.h"


class CyclePart {
    char *name;
    double price;
    Quality quality;

    void setName(const char *name);

public:
    CyclePart(const char *name = "", double price = 0.0, Quality quality = Low);

    CyclePart(const CyclePart &copy);

    double getPrice() const { return this->price; }

    Quality getQuality() const { return this->quality; }

    const char *getName() const { return this->name; }

    ~CyclePart();
};


#endif //BYCICLE_CYCLEPART_H
