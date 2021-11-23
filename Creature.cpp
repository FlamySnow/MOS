//
// Created by flamy on 23/11/21.
//


#include "Creature.h"



Creature::Creature(const std::string& n, unsigned short atk, unsigned short spd, unsigned short intv, unsigned short hp, unsigned short exp) {
    if (n.empty())
        throw std::invalid_argument("Name is empty! ):");
    if (!isCorrectATK(atk) || !isCorrectINTV(intv) || !isCorrectHP(hp) || !isCorrectEXP(exp) || !isCorrestSPD(spd))
        throw std::invalid_argument("Incorrect parameters!");
    name = n;
    attack = atk;
    initiative = intv;
    speed = spd;
    health = hp;
    this->exp = exp;
}

const std::string &Creature::getName() const {
    if (name.empty())
        throw std::invalid_argument("Nameless creature!");
    return name;
}
