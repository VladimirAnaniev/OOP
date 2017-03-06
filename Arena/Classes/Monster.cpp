#include "Monster.h"
#include <iostream>
#include <cstring>

using namespace std;

Monster::Monster(char* name, int age, int att, int def) {
    this->name = nullptr;
    setName(name);
    setAge(age);
    setAttack(att);
    setDefence(def);
}

Monster::~Monster()
{
    delete this->name;
}

void Monster::setName(const char* name) {
    if(this->name != nullptr) delete this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
};

void Monster::print() const {
    cout << "Name: " << getName() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Attack: " << getAttack() << endl;
    cout << "Defence: " << getDefence() << endl;
}