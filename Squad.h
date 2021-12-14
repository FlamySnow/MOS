//
// Created by flamy on 24/11/21.
//

#ifndef MOS_SQUAD_H
#define MOS_SQUAD_H

#include "Creature.h"
#include "STile.h"

class Squad: STile {
protected:
    std::string owner;
    const Creature& creature;
    int attack;
    int defense;
    int number;
    int dead;
public:
    Squad(const std::string&, const Creature&, int);
    Squad(const std::string &ow, const Creature &cr, int def, int num, int d);

    const std::string& getName() {return owner;};
    const Creature& getCreature() {return creature;};
    [[nodiscard]] int getATK() const {return attack;};
    [[nodiscard]] int getNumber() const {return number;};
    [[nodiscard]] int getDefense() const {return defense;};

    friend std::ostream& operator << (std::ostream& s, const Squad &sq);

    virtual int getHurt(int damage);

    int resurrect (int n);
};


#endif //MOS_SQUAD_H
