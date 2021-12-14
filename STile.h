//
// Created by flamy on 14/12/21.
//

#ifndef MOS_STILE_H
#define MOS_STILE_H


class STile {
    int initiative;

public:
    bool operator < (const STile& t) const {return initiative < t.initiative;};
};


#endif //MOS_STILE_H
