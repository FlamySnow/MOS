//
// Created by flamy on 14/12/21.
//

#ifndef MOS_TILE_H
#define MOS_TILE_H

#include <list>
#include <utility>
#include "../template/Map.h"
#include "STile.h"

enum tileType {
    block,
    squad
};

struct Tile {
    int x;
    int y;
    tileType type;
    STile* squad;
} Tile;

class Tiles {
    Map<std::pair<int, int>, struct Tile> tiles;
public:

};


#endif //MOS_TILE_H
