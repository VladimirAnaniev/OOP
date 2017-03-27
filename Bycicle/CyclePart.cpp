#include <cstring>
#include "CyclePart.h"

CyclePart::CyclePart(const char *name, double price, Quality quality) : name(nullptr), price(price), quality(quality) {
    this->setName(name);
}

void CyclePart::setName(const char *name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

CyclePart::~CyclePart() {
    delete[] this->name;
}

CyclePart::CyclePart(const CyclePart &copy) : name(nullptr), price(copy.price), quality(copy.quality) {
    this->setName(copy.getName());
}
