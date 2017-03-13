#ifndef ARENA_MONSTER_H
#define ARENA_MONSTER_H

class Monster {
    char *name;
    int age, att, def, health;

public:
    /* Constructor and Destructor*/
    Monster(const char *name = "", int age = 0, int att = 0, int def = 0, int health = 0);

    Monster(const Monster &monster);

    ~Monster();

    /* Getters */
    int getAge() const { return this->age; }

    int getAttack() const { return this->att; }

    int getDefence() const { return this->def; }

    int getHealth() const { return this->health; }

    const char *getName() const { return this->name; }

    bool isAlive() const { return this->getHealth() > 0; }

    /* Setters */
    void setName(const char *name);

    void setAge(int age) { this->age = age; }

    void setAttack(int attack) { this->att = attack; }

    void setDefence(int defence) { this->def = defence; }

    void setHealth(int health) { this->health = health; }

    int dealDamage(int dmg);

    void fight(Monster &opponent);

    void attack(Monster &opponent);

    /* Output */
    void print() const;

    /* Operators */

    Monster &operator=(const Monster &monster);
};


#endif //ARENA_MONSTER_H
