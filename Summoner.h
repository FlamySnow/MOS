//
// Created by flamy on 24/11/21.
//

#ifndef MOS_SUMMONER_H
#define MOS_SUMMONER_H

#include "SchoolTable.h"
#include "STile.h"


/// описатель призывателя

/**
 * Имеет текущие максимальные здоровье, энергию.
 * Имеет текущее значение опыта
 * По идее, чтобы напасть на призывателя, нужно убить все его отряды.
 * Также существует коэффициент аккумуляции энергии - значение, на которое энергия увеличивается за ход.
 */
class Summoner : public STile {
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
    /// Получение знания какой-либо школы по её названию
    [[nodiscard]] int getKD(const std::string& school) const;
    [[nodiscard]] int getHP() const {return cur_health;};
    [[nodiscard]] int getEXP() const {return cur_exp;};
    [[nodiscard]] int getEN() const {return cur_energy;};
    [[nodiscard]] const std::string& getName() const {return name;};
    int getINTV() override {return initiative;};

    friend std::ostream& operator << (std::ostream&, const Summoner&);
};


#endif //MOS_SUMMONER_H
