//
// Created by flamy on 24/11/21.
//

#ifndef MOS_SUMMONER_H
#define MOS_SUMMONER_H

#include "SchoolTable.h"

class Summoner {
    std::string name;
    static const unsigned short max_health = 100;
    unsigned short cur_health;
    static const unsigned short accumulation = 5;
    static const unsigned short max_energy = 100;
    unsigned short cur_exp;
    unsigned short cur_energy;
    static const unsigned short attack = 10;

public:
    std::map<std::string, unsigned short> knowledge;
    explicit Summoner (const std::string& n = "Nameless", unsigned short health = max_health, unsigned short ex = 0, unsigned short energy = 50);

    void accumulate(unsigned short energy);
    void receiveEXP(unsigned short exp) {cur_exp += exp;};
    void enhance(const std::string& school, unsigned short exp);
    void getHurt(unsigned short damage);

    friend std::ostream& operator << (std::ostream&, const Summoner&);
};


#endif //MOS_SUMMONER_H
