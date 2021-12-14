//
// Created by flamy on 14/12/21.
//

#include "Tile.h"

const std::list<struct Tile> &Tiles::operator[](int k) const {
    auto p = tiles.find(k);
    if (p == tiles.end())
        throw std::invalid_argument("There are no tiles.");
    return p->data.second;
}

std::list<struct Tile> &Tiles::operator[](int k) {
    auto p = tiles.find(k);
    if (p == tiles.end()) {
        std::list<struct Tile> list;
        auto pp = tiles.insert(std::make_pair(k,list));
        if (!pp.second)
            throw std::invalid_argument("Insertion is not completed.");
        else
            return pp.first->data.second;
    }
    return p->data.second;
}

const struct Tile &Tiles::operator[](const std::list<struct Tile> &) const {
    return <#initializer#>;
}
