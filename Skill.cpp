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
    s << sk.name << std::endl;
    s << sk.min_knowledge << std::endl;
    s << sk.energy << std::endl;
    s << sk.coefficient << std::endl;
    s << sk.creature;
    return s;
}

bool Skill::operator==(const Skill &sk) const {
    if (sk.getName() != name)
        return false;
    if (sk.getKD() != min_knowledge)
        return false;
    if (sk.getEG() != energy)
        return false;
    if (sk.getCFF() != coefficient)
        return false;
    if (sk.creature.getName() != creature.getName())
        return false;
    return true;
}

std::istream &operator>>(std::istream &s, Skill & skill) {
    s >> skill.name;
    s >> skill.min_knowledge;
    s >> skill.energy;
    s >> skill.coefficient;
    s >> skill.creature;
    return s;
}
