//
// Created by flamy on 24/11/21.
//

#include "Summoner.h"

Summoner::Summoner(const std::string &n, int health, int ex, int energy) {
    if (n.empty())
        throw std::invalid_argument("Empty string!");
    if (health < 0 || health > max_health || ex < 0 || energy < 0 || energy > max_energy)
        throw std::invalid_argument("Incorrect parameters!");
    name = n;
    cur_health = health;
    cur_exp = ex;
    cur_energy = energy;
}

void Summoner::accumulate() {
    if (accumulation + cur_energy > max_energy)
        cur_energy = max_energy;
    cur_exp += accumulation;
}

void Summoner::enhance(const std::string& school, int exp) {
    auto p = knowledge.find(school);
    if (p == knowledge.end()) {
        auto pp = knowledge.insert(std::make_pair(school, exp));
        if (!pp.second)
            throw std::invalid_argument("Can't add more schools!");
    }
    else
        p->data.second += exp;
}

void Summoner::getHurt(int damage) {
    if (cur_health - damage < 0)
        cur_health = 0;
    else
        cur_health -=damage;
}

std::ostream& operator<<(std::ostream& s, const Summoner & sum) {
    s << "Name: " << sum.name << std::endl;
    s << "Max Health: " << Summoner::max_health << std::endl;
    s << "Max energy: " << Summoner::max_energy << std::endl;
    s << "Current health: " << sum.cur_health << std::endl;
    s << "Current experience: " << sum.cur_exp << std::endl;
    s << "Current energy: " << sum.cur_energy << std::endl;
    s << "Attack: " << Summoner::attack << std::endl;
    s << "Accumulation: " << Summoner::accumulation << std::endl;
    return s;
}

void Summoner::receiveEXP(int exp) {
    if (exp < 0)
        throw std::invalid_argument("Enter positive number.");
    cur_exp += exp;
}

int Summoner::getKD(const std::string &school) const {
    auto p = knowledge.find(school);
    if (p == knowledge.end())
        return 0;
    return p->data.second;
}
