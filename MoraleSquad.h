//
// Created by flamy on 24/11/21.
//

#ifndef MOS_MORALESQUAD_H
#define MOS_MORALESQUAD_H

#include "Squad.h"

class MoraleSquad: public Squad{
    short morale;
    static const unsigned short quota = 5;

public:
    MoraleSquad(const std::string& s, const Creature& c, unsigned short n): Squad(s, c, n), morale(0) {};
    MoraleSquad(const std::string& s, const Creature& c, unsigned short def, unsigned short num, unsigned short dead, short mrl);

    short getMorale () {return morale;};
    void increaseMorale();
    void decreaseMorale();
    void balanceMorale();
    unsigned short getHurt(unsigned short damage) override;
    friend std::ostream& operator << (std::ostream& s, const MoraleSquad& m);
};


#endif //MOS_MORALESQUAD_H
