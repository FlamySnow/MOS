//
// Created by flamy on 24/11/21.
//

#ifndef MOS_SUMMONER_H
#define MOS_SUMMONER_H

#include "SchoolTable.h"
#include "STile.h"

class Summoner : STile {
    std::string name;
    static const int max_health = 100;
    int cur_health;
    static const int accumulation = 5;
    static const int max_energy = 100;
    int cur_exp;
    int cur_energy;
    static const int attack = 420;

    Map<std::string, int> knowledge;

public:

    explicit Summoner (const std::string& n = "Nameless", int health = max_health, int ex = 0, int energy = 50);

    void accumulate();
    void receiveEXP(int exp);
    void enhance(const std::string& school, int exp);
    void getHurt(int damage);
    [[nodiscard]] int getKD(const std::string& school) const;
    [[nodiscard]] int getHP() const {return cur_health;};
    [[nodiscard]] int getEXP() const {return cur_exp;};
    [[nodiscard]] int getEN() const {return cur_energy;};
    [[nodiscard]] const std::string& getName() const {return name;};

    friend std::ostream& operator << (std::ostream&, const Summoner&);
};


#endif //MOS_SUMMONER_H
