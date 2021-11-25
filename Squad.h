//
// Created by flamy on 24/11/21.
//

#ifndef MOS_SQUAD_H
#define MOS_SQUAD_H

#include "Creature.h"

class Squad {
protected:
    std::string owner;
    const Creature& creature;
    unsigned short attack;
    unsigned short defense;
    unsigned short number;
    unsigned short dead;
public:
    Squad(const std::string&, const Creature&, unsigned short);
    Squad(const std::string&, const Creature&, unsigned short, unsigned short, unsigned short);

    const std::string& getName() {return owner;};
    const Creature& getCreature() {return creature;};
    [[nodiscard]] unsigned short getATK() const {return attack;};
    [[nodiscard]] unsigned short getNumber() const {return number;};
    [[nodiscard]] unsigned short getDefense() const {return defense;};

    friend std::ostream& operator << (std::ostream& s, const Squad &sq);

    virtual unsigned short getHurt(unsigned short damage);

    unsigned short resurrect (unsigned short);
};


#endif //MOS_SQUAD_H
