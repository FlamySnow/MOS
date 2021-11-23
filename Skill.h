//
// Created by flamy on 23/11/21.
//

#ifndef MOS_SKILL_H
#define MOS_SKILL_H
#include "Creature.h"

class Skill {
    std::string name;
    Creature creature;
    unsigned short min_knowledge;
    unsigned short energy;
    unsigned short coefficient;
};


#endif //MOS_SKILL_H
