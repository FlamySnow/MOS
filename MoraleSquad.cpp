//
// Created by flamy on 24/11/21.
//

#include "MoraleSquad.h"

MoraleSquad::MoraleSquad(const std::string &s, const Creature &c, int def, int num, int dead, int mrl): Squad(s, c, def, num, dead) {
    if (mrl < -100 || mrl > 100)
        throw std::invalid_argument("Incorrect morale!");
    morale = mrl;
}

void MoraleSquad::increaseMorale() {
    if (morale + quota > 100)
        morale = 100;
    else
        morale += quota;
}

void MoraleSquad::balanceMorale() {
    if (morale == 0)
        return;
    if (morale > 0) {
        if (morale - quota < 0)
            morale = 0;
        else
            morale -= quota;
    }
    else
    {
        if (morale + quota > 0)
            morale = 0;
        else
            morale += quota;
    }
}

int MoraleSquad::getHurt(int damage) {
    unsigned short newnum;
    if (defense - damage <= 0)
        newnum = 0;
    else {
        defense -= damage;
        if (defense % creature.getHP() != 0)
            newnum = defense/creature.getHP() + 1;
        else
            newnum = defense/creature.getHP();
    }
    unsigned short d = number - newnum;
    for (int i = 0; i < d; i++)
        decreaseMorale();
    dead += d;
    number = newnum;
    attack = number * creature.getATK();
    return number;
}

void MoraleSquad::decreaseMorale() {
    if (morale - quota < -100)
        morale = -100;
    else
        morale -= quota;
}

std::ostream &operator<<(std::ostream &s, const MoraleSquad &m) {
    s << "Summoner: " << m.owner << std::endl;
    s << m.creature;
    s << "Attack: " << m.attack << std::endl;
    s << "Defense: " << m.defense << std::endl;
    s << "Morale: " << m.morale;
    s << "Number: " << m.number;
    return s;
}



