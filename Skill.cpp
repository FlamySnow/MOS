//
// Created by flamy on 23/11/21.
//

#include "Skill.h"


Skill::Skill(const std::string& n, unsigned short min, unsigned short enrg, unsigned short cff) {
    if (n.empty())
        throw std::invalid_argument("Name of skill is empty!");
    if (!isCorrectKD(min) || !isCorrectEG(enrg) || !isCorrectCFF(cff))
        throw std::invalid_argument("Incorrect parameters for skill!");
    name = n;
    min_knowledge = min;
    energy = enrg;
    coefficient = cff;
}

void Skill::setName(const std::string& s) {
    if (s.empty())
        throw std::invalid_argument("Name of skill is empty!");
    name = s;
}

void Skill::setKD(unsigned short a) {
    if (!isCorrectKD(a))
        throw std::invalid_argument("Incorrect minimal knowledge!");
    min_knowledge = a;
}

void Skill::setEG(unsigned short a) {
    if (!isCorrectEG(a))
        throw std::invalid_argument("Incorrect energy!");
    energy = a;
}

void Skill::setCFF(unsigned short a) {
    if (!isCorrectCFF(a))
        throw std::invalid_argument("Incorrect coefficient!");
    coefficient = a;
}

std::ostream &operator<<(std::ostream &s, const Skill& sk) {
    s << "Skill: " << sk.name << std::endl;
    s << sk.creature << std::endl;
    s << "Minimal knowledge: " << sk.min_knowledge << std::endl;
    s << "Energy: " << sk.energy << std::endl;
    s << "Coefficient of quantity: " << sk.coefficient << std::endl;
    return s;
}
