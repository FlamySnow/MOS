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
    bool morale;
    bool revival;

    static bool isCorrectATK(unsigned short a) {return  a <= 10000;};
    static bool isCorrectINTV(unsigned short a) {return a <= 100; }
    static bool isCorrectHP(unsigned short a) {return a >= 10 && a <= 10000;}
    static bool isCorrectEXP(unsigned short a) {return a >= 1 && a <= 1000;}
    static bool isCorrectSPD(unsigned short a) {return a <= 10;};
public:
    explicit Creature(const std::string& s = "Nameless", unsigned short atk = 0, unsigned short spd = 0, unsigned short intv = 0, unsigned short hp = 10, unsigned short exp = 1, bool mrl = true, bool rvl = false);

    [[nodiscard]] const std::string& getName () const;
    [[nodiscard]] unsigned short getATK() const {return attack;};
    [[nodiscard]] unsigned short getINTV() const {return initiative;};
    [[nodiscard]] unsigned short getHP() const {return health;};
    [[nodiscard]] unsigned short getEXP() const {return exp;};
    [[nodiscard]] unsigned short getSPD() const {return speed;};
    [[nodiscard]] bool isRevival() const {return revival;};
    [[nodiscard]] bool isMorale() const {return morale;};

    void setName(const std::string&);
    void setATK(unsigned short);
    void setSPD(unsigned short);
    void setINTV(unsigned short);
    void setHP(unsigned short);
    void setEXP(unsigned short);
    void setRVL(bool a) {revival = a;};
    void setMRL(bool a) {morale = a;};

    friend std::ostream& operator << (std::ostream&, const Creature&);
};


#endif //MOS_CREATURE_H
