//
// Created by flamy on 24/11/21.
//

#include "Squad.h"

Squad::Squad(const std::string &s, const Creature& c , int num): creature(c), dead(0), STile(c.getINTV(), squad) {
    if (s.empty())
        owner = "Nameless";
    if (num == 0)
        throw std::invalid_argument("Size of squad can't be zero!");
    if (num > 100)
        number = 100;
    else
        number = num;
    owner = s;
    attack = creature.getATK()*number;
    defense = creature.getHP()*number;
}

std::ostream& operator<<(std::ostream &s, const Squad &sq) {
    s << "Summoner: " << sq.owner << std::endl;
    s << sq.creature;
    s << "Attack: " << sq.attack << std::endl;
    s << "Defense: " << sq.defense << std::endl;
    s << "Number: " << sq.number << std::endl;
    return s;
}

int Squad::getHurt(int damage) {
    unsigned short newnum;
    if (defense - damage <= 0) {
        defense = 0;
        attack = 0;
        number = 0;
        return number;
    }
    defense -= damage;
        if (defense % creature.getHP() != 0)
            newnum = defense/creature.getHP() + 1;
        else
            newnum = defense/creature.getHP();
    dead += number - newnum;
    number = newnum;
    attack = number*creature.getATK();
    return number;
}

Squad::Squad(const std::string & ow, const Creature & cr, int def, int num, int d): creature(cr), STile(cr.getINTV(), squad) {
    if (ow.empty())
        throw std::invalid_argument("Empty name of owner!");
    if (def > 0  && num >= 0 && num <= 100 && d >= 0 && d <= 100 && def / cr.getHP() == num) {
        defense = def;
        number = num;
        dead = d;
        attack = number * creature.getATK();
        owner = ow;
    }
    else
        throw std::invalid_argument("Incorrect parameters!");
}

int Squad::resurrect(int n) {
    if (!creature.isRevival())
        throw std::invalid_argument("Creature isn't revival!");
    if (n < 1 || n > dead)
        throw std::invalid_argument("Incorrect parameter!");
    dead -= n;
    number += n;
    attack = number * creature.getATK();
    defense += n * creature.getHP();
    return 0;
}
