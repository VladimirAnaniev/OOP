#include <cstring>
#include "Bicycle.h"

Bicycle::Bicycle(const Bicycle &copy)
        : brand(nullptr), parts(nullptr), partsCount(copy.partsCount) {
    this->setBrand(copy.getBrand());
    this->setParts(copy.getParts(), copy.partsCount);
}

Bicycle::Bicycle(const char *brand, const CyclePart *parts, int partsCount)
        : brand(nullptr), parts(nullptr), partsCount(partsCount) {
    this->setBrand(brand);
    this->setParts(parts, partsCount);
}

void Bicycle::setBrand(const char *brand) {
    delete[] this->brand;
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
}

void Bicycle::setParts(const CyclePart *parts, int count) {
    delete[] this->parts;
    this->parts = new CyclePart[count];
    for (int i = 0; i < count; i++) {
        this->parts[i] = parts[i];
    }
}

Bicycle::~Bicycle() {
    delete[] this->brand;
    delete[] this->parts;
}

double Bicycle::getPrice() const {
    double price = 0;
    for (int i = 0; i < this->partsCount; i++) {
        price += this->parts[i].getPrice();
    }
    return price * 1.5;
}

bool Bicycle::equals(const Bicycle &compare) const {
    return strcmp(this->brand, compare.brand) == 0 && this->getPrice() == compare.getPrice();
}

int Bicycle::getHighQualityParts() const {
    int count = 0;
    for (int i = 0; i < this->partsCount; i++) {
        if (this->parts[i].getQuality() == High) count++;
    }
    return count;
}

bool Bicycle::isLessThan(const Bicycle &compare) const {
    return this->getHighQualityParts() < compare.getHighQualityParts();
}

void Bicycle::addPart(CyclePart part) {
    CyclePart *newArr = new CyclePart[this->partsCount + 1];
    for (int i = 0; i < partsCount; i++) {
        newArr[i] = this->parts[i];
    }
    this->parts[this->partsCount] = part;
    delete[] this->parts;
    this->parts = newArr;
}

void Bicycle::removePart(int index) {
    if (index >= 0 && index < this->partsCount) {
        CyclePart *newArr = new CyclePart[this->partsCount -1];
        for (int i = 0, j = 0; i < partsCount; i++) {
            if(i!=index) {
                newArr[j++] = this->parts[i];
            }
        }
        delete[] this->parts;
        this->parts = newArr;
    }
}