//
// Created by flamy on 24/11/21.
//

#ifndef MOS_MORALESQUAD_H
#define MOS_MORALESQUAD_H

#include "Squad.h"

/**
 *
 * Мораль увеличивается, если отряд победил какой-то другой отряд на то количество существ, которое было в побеждённом отряде.
 * Мораль уменьшается в зависимости от того, сколько существ было убито.
 **/


/// Отряд, имеющий динамическую характеристику - мораль.
class MoraleSquad: public Squad{
    int morale;
    static const unsigned int quota = 5;//< количество морали, на которое она увеличивается/уменьшается за одно побеждённое/убитое существо.

public:
    MoraleSquad(const std::string& s, const Creature& c, int n): Squad(s, c, n), morale(0) {};
    MoraleSquad(const std::string& s, const Creature& c, int def, int num, int dead, int mrl);

    int getMorale () {return morale;};
    void increaseMorale();
    void decreaseMorale();
    /**
     * Мораль каждый ход немного балансируется, на значение, равное quota.
     * Значение морали по умолчанию - 0. Максимальное значение - 100, минимальное - -100.
     **/
    void balanceMorale();
    int getHurt(int damage) override; //< получение урона отрядом
    friend std::ostream& operator << (std::ostream& s, const MoraleSquad& m);
};


#endif //MOS_MORALESQUAD_H
