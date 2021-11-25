//
// Created by flamy on 23/11/21.
//


#include "Creature.h"



Creature::Creature(const std::string& n, unsigned short atk, unsigned short spd, unsigned short intv, unsigned short hp, unsigned short exp, bool mrl, bool rvl): morale(mrl), revival(rvl) {
    if (n.empty())
        throw std::invalid_argument("Name is empty! ):");
    if (!isCorrectATK(atk) || !isCorrectINTV(intv) || !isCorrectHP(hp) || !isCorrectEXP(exp) || !isCorrectSPD(spd))
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

void Creature::setName(const std::string& s) {
    if (s.empty())
        throw std::invalid_argument("Empty string!");
    name = s;
}

void Creature::setATK(unsigned short a) {
    if (!isCorrectATK(a))
        throw std::invalid_argument("Incorrect argument!");
    attack = a;
}

void Creature::setSPD(unsigned short a) {
    if (!isCorrectSPD(a))
        throw std::invalid_argument("Incorrect argument!");
    speed = a;
}

void Creature::setINTV(unsigned short a) {
    if (!isCorrectINTV(a))
        throw std::invalid_argument("Incorrect argument!");
    initiative = a;
}

void Creature::setHP(unsigned short a) {
    if (!isCorrectHP(a))
        throw std::invalid_argument("Incorrect argument!");
    health = a;
}

void Creature::setEXP(unsigned short a) {
    if (!isCorrectEXP(a))
        throw std::invalid_argument("Incorrect argument!");
    exp = a;
}

std::ostream &operator<<(std::ostream &s, const Creature &c) {
    s << "Creature: " << c.name << std::endl;
    s << "Attack: " << c.attack << std::endl;
    s << "Speed: " << c.speed << std::endl;
    s << "Initiative: " << c.initiative << std::endl;
    s << "Health: " << c.health << std::endl;
    s << "Experience for kill: " << c.exp << std::endl;
    s << "Morale? " << c.morale << std::endl;
    s << "Revival? " << c.revival << std::endl;
    return s;
}

