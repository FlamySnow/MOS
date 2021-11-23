//
// Created by flamy on 23/11/21.
//

#ifndef MOS_CREATURE_H
#define MOS_CREATURE_H

#include <string>
#include <utility>
#include <stdexcept>
#include <iostream>

class Creature {
    std::string name;
    unsigned short attack;
    unsigned short speed;
    unsigned short initiative;
    unsigned short health;
    unsigned short exp;

    bool isCorrectATK(unsigned short a) {return  a <= 10000;};
    bool isCorrectINTV(unsigned short a) {return a <= 100; }
    bool isCorrectHP(unsigned short a) {return a >= 10 && a <= 10000;}
    bool isCorrectEXP(unsigned short a) {return a >= 1 && a <= 1000;}
    bool isCorrestSPD(unsigned short a) {return a <= 10;};
public:
    Creature():name("Nameless"), attack(0), speed(0), initiative(0), health(10), exp(1) {};
    Creature(const std::string&, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);

    [[nodiscard]] const std::string& getName () const;
    [[nodiscard]] unsigned short getATK() const {return attack;};
    [[nodiscard]] unsigned short getINTV() const {return initiative;};
    [[nodiscard]] unsigned short getHP() const {return health;};
    [[nodiscard]] unsigned short getEXP() const {return exp;};
    [[nodiscard]] unsigned short getSPD() const {return speed;};
};


#endif //MOS_CREATURE_H
