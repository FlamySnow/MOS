//
// Created by flamy on 14/12/21.
//

#ifndef MOS_TILE_H
#define MOS_TILE_H

#include <utility>
#include "../template/Map.h"
#include "STile.h"

enum tileType {
    block, //< преграда
    some_squad //< призыватель или отряд
};

/// структура клетки с координатами и отрядом/призывателем - указателем.
typedef struct Tile {
    std::pair<int, int> point; //< точка
    tileType type; //< тип клетки
    STile* squad; //< указатель на отряд или призывателя
} Tile;

#endif //MOS_TILE_H
