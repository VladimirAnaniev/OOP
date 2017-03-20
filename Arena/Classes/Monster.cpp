#include "Monster.h"
#include <iostream>
#include <cstring>

Monster::Monster(const char *name, int att, int def, int health) {
    this->name = NULL;
    setName(name);
    setAttack(att);
    setDefence(def);
    setHealth(health);
}

Monster::Monster(const Monster &monster) {
    this->name = NULL;
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
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Attack: " << getAttack() << std::endl;
    std::cout << "Defence: " << getDefence() << std::endl;
}

Monster &Monster::operator=(const Monster &monster) {
    if (this != &monster) {
        this->setName(monster.getName());
        this->setAttack(monster.getAttack());
        this->setDefence(monster.getDefence());
        this->setHealth(monster.getHealth());
    }
    return *this;
}

void Monster::attack(Monster &opponent) {
    if (opponent.isAlive()) {
        opponent.dealDamage(this->getAttack());
    } else {
        std::cout << "You cannot attack a dead monster!" << std::endl;
    }
}

int Monster::dealDamage(int dmg) {
    int damageDealt = dmg - this->getDefence();
    if (damageDealt < 0) damageDealt = 0;
    this->setHealth(this->getHealth() - damageDealt);

    return damageDealt;
}

Monster &Monster::fight(Monster &opponent) {
    if(this->isAlive()) {
        this->attack(opponent);
        return opponent.fight(*this);
    }
    std::cout << "The winner is " << opponent.getName() << std::endl;
    return opponent;
}