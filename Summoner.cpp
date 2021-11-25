//
// Created by flamy on 24/11/21.
//

#include "Summoner.h"

Summoner::Summoner(const std::string &n, unsigned short health, unsigned short ex, unsigned short energy) {
    if (n.empty())
        throw std::invalid_argument("Empty string!");
    if (health < 0 || health > max_health || ex < 0 || energy < 0 || energy > max_energy)
        throw std::invalid_argument("Incorrect parameters!");
    name = n;
    cur_health = health;
    cur_exp = ex;
    cur_energy = energy;
}

void Summoner::accumulate(unsigned short energy) {
    if (energy > cur_energy)
        throw std::invalid_argument("Incorrect parameter!");
    cur_exp += accumulation*energy;
}

void Summoner::enhance(const std::string& school, unsigned short exp) {
    auto p = knowledge.find(school);
    if (p == knowledge.end()) {
        auto pp = knowledge.insert(std::make_pair(school, exp));
        if (!pp.second)
            throw std::invalid_argument("Can't add more schools!");
    }
    else
        p->second += exp;
}

void Summoner::getHurt(unsigned short damage) {
    if (cur_health - damage < 0)
        cur_health = 0;
    else
        cur_health -=damage;
}

std::ostream& operator<<(std::ostream& s, const Summoner & sum) {
    s << "Name: " << sum.name << std::endl;
    s << "Max Health: " << sum.max_health << std::endl;
    s << "Max energy: " << sum.max_energy << std::endl;
    s << "Current health: " << sum.cur_health << std::endl;
    s << "Current experience: " << sum.cur_exp << std::endl;
    s << "Current energy: " << sum.cur_energy << std::endl;
    s << "Attack: " << sum.attack << std::endl;
    s << "Accumulation: " << sum.accumulation << std::endl;
    return s;
}
