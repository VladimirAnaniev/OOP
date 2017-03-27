#ifndef BYCICLE_BYCICLE_H
#define BYCICLE_BYCICLE_H

#include "CyclePart.h"

class Bicycle {
    char *brand;
    CyclePart *parts;
    int partsCount;

    void setBrand(const char *brand);

    void setParts(const CyclePart *parts, int count);

    int getHighQualityParts() const;

public:
    Bicycle(const char *name = "", const CyclePart *parts = nullptr, int partsCount = 0);

    Bicycle(const Bicycle &copy);

    void addPart(CyclePart part);

    void removePart(int index);

    double getPrice() const;

    const char *getBrand() const { return this->brand; }

    const CyclePart *getParts() const { return this->parts; }

    bool equals(const Bicycle &compare) const;

    bool isLessThan(const Bicycle &compare) const;

    bool operator==(const Bicycle &compare) const { return this->equals(compare); }

    bool operator!=(const Bicycle &compare) const { return !this->equals(compare); }

    bool operator<(const Bicycle &compare) const { return this->isLessThan(compare); }

    bool operator<=(const Bicycle &compare) const { return this->isLessThan(compare) || this->isLessThan(compare); }

    bool operator>(const Bicycle &compare) const { return compare.isLessThan(*this); }

    bool operator>=(const Bicycle &compare) const { return compare.isLessThan(*this) || compare.equals(*this); }

    ~Bicycle();
};


#endif //BYCICLE_BYCICLE_H
