#include "Monster.h"
#include <iostream>
#include <cstring>

using namespace std;

Monster::Monster(const char *name, int age, int att, int def) {
    this->name = NULL;
    setName(name);
    setAge(age);
    setAttack(att);
    setDefence(def);
}

Monster::Monster(const Monster &monster) {
    *this = monster;
}

Monster::~Monster() {
    delete this->name;
}

void Monster::setName(const char *name) {
    if (this->name != NULL) delete this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
};

void Monster::print() const {
    cout << "Name: " << getName() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Attack: " << getAttack() << endl;
    cout << "Defence: " << getDefence() << endl;
}

Monster& Monster::operator= (const Monster& monster) {
    if(this != monster) {
        this->setName(monster.getName());
        this->setAge(monster.getAge());
        this->setAttack(monster.getAttack());
        this->setDefence(monster.getDefence());
    }
    return *this;
}
