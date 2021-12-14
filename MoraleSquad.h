//
// Created by flamy on 24/11/21.
//

#ifndef MOS_MORALESQUAD_H
#define MOS_MORALESQUAD_H

#include "Squad.h"

class MoraleSquad: public Squad{
    int morale;
    static const unsigned int quota = 5;

public:
    MoraleSquad(const std::string& s, const Creature& c, int n): Squad(s, c, n), morale(0) {};
    MoraleSquad(const std::string& s, const Creature& c, int def, int num, int dead, int mrl);

    int getMorale () {return morale;};
    void increaseMorale();
    void decreaseMorale();
    void balanceMorale();
    int getHurt(int damage) override;
    friend std::ostream& operator << (std::ostream& s, const MoraleSquad& m);
};


#endif //MOS_MORALESQUAD_H
