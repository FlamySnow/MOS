//
// Created by flamy on 23/11/21.
//

#ifndef MOS_SKILL_H
#define MOS_SKILL_H
#include "Creature.h"

class Skill {
    std::string name;
    unsigned short min_knowledge;
    unsigned short energy;//затрачиваемая энергия
    unsigned short coefficient;

    static bool isCorrectKD(unsigned short a) {return a >= 1 && a <= 100;};
    static bool isCorrectEG(unsigned short a) {return a >= 1 && a <= 100;};
    static bool isCorrectCFF(unsigned short a) {return a > 0 && a <= 100;};
public:
    Creature creature;

    explicit Skill(const std::string& n = "Nameless", unsigned short min = 1, unsigned short enrg = 1, unsigned short cff = 1);

    [[nodiscard]] const std::string& getName() const {return name;};
    [[nodiscard]] unsigned short getKD() const {return min_knowledge;};
    [[nodiscard]] unsigned short getEG() const {return energy;};
    [[nodiscard]] unsigned short getCFF() const {return coefficient;};

    void setName(const std::string&);
    void setKD(unsigned short);
    void setEG(unsigned short);
    void setCFF(unsigned short);

    friend std::ostream& operator << (std::ostream&, const Skill&);
};


#endif //MOS_SKILL_H
