#include "Monster.h"
#include <iostream>
#include <cstring>

Monster::Monster(const char *name, int age, int att, int def, int health) {
    this->name = NULL;
    setName(name);
    setAge(age);
    setAttack(att);
    setDefence(def);
    setHealth(health);
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
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Age: " << getAge() << std::endl;
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Attack: " << getAttack() << std::endl;
    std::cout << "Defence: " << getDefence() << std::endl;
}

Monster &Monster::operator=(const Monster &monster) {
    if (this != &monster) {
        this->setName(monster.getName());
        this->setAge(monster.getAge());
        this->setAttack(monster.getAttack());
        this->setDefence(monster.getDefence());
        this->setHealth(monster.getHealth());
    }
    return *this;
}

void Monster::attack(Monster &opponent) {
    if (opponent.isAlive()) {
        std::cout << this->getName() << " deals " << opponent.dealDamage(this->getAttack()) << " damage. ";
    } else {
        std::cout << "You cannot attack a dead monster!" << std::endl;
    }
}

int Monster::dealDamage(int dmg) {
    int damageDealt = dmg - this->getDefence();
    if (damageDealt < 0) damageDealt = 0;
    this->setHealth(this->getHealth() - damageDealt);

    if (this->getHealth() < 0) {
        this->setHealth(0);
        std::cout << this->getName() << " has died. Horribly" << std::endl;
    } else {
        std::cout << this->getName() << " has " << this->getHealth() << " Health left." << std::endl;
    }

    return damageDealt;
}

void Monster::fight(Monster &opponent) {
    std::cout << this->getName() << " will fight " << opponent.getName() << " to the death!" << std::endl;

    if (this->getAttack() <= opponent.getDefence() && opponent.getAttack() <= this->getDefence()) {
        std::cout << "The monsters have even strength and became friends.. No show for the crowd today!" << std::endl;
    } else {
        for (int i = 0; this->isAlive() && opponent.isAlive(); i++) {
            if (i % 2 == 0 && opponent.isAlive()) {
                this->attack(opponent);
            } else if (i % 2 == 1 && this->isAlive()) {
                opponent.attack(*this);
            } else {
                break;
            }
        }

        if (this->isAlive()) std::cout << "The winner is " << this->getName() << std::endl;
        else std::cout << "The winner is " << opponent.getName() << std::endl;
    }
}
