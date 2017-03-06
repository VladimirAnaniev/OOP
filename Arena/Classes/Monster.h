#ifndef ARENA_MONSTER_H
#define ARENA_MONSTER_H

class Monster
{
    char* name;
    int age, att, def;

public:
    Monster(char* name = new char[1] {'\0'}, int age = 0, int att = 0, int def = 0);
    ~Monster();
    void print() const;

    int getAge() const { return this->age; };
    int getAttack() const { return this->att; };
    int getDefence() const { return this->def; };
    const char* getName() const { return this->name; };

    void setName(const char* name);
    void setAge(int age) { this->age = age; };
    void setAttack(int attack) { this->att = attack; };
    void setDefence(int defence) { this->def = defence; };
};


#endif //ARENA_MONSTER_H