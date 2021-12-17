//
// Created by flamy on 14/12/21.
//

#include "Landscape.h"

Landscape::Landscape(int n, int m, int move) {
    if (n < 0 || m < 0 || move <= 0)
        throw std::invalid_argument("Incorrect size of field.");
    N = n;
    M = m;
}

bool Landscape::addSquad(Tile s) {
    if (moves.count(s.squad) == 1)
        throw std::invalid_argument("Cannot add existing squad.");
    if (tiles.find(s.point) != tiles.end())
        return false;
    tiles[s.point] = s;
    moves.insert(s.squad);
    return true;
}

void Landscape::moveSquad(int x, int y, Tile s) {
    if (x < 0 || y < 0 || x > N || y > M)
        throw std::invalid_argument("Incorrect coordinates.");
    auto p = tiles.find({x, y});
    if (p != tiles.end())
        throw std::invalid_argument("This tile is already busy.");
    tiles.erase(s.point);
    s.point = {x, y};
    tiles[{x, y}] = s;
}

std::pair<int, int> Landscape::findPoint(STile *t) const {
    for (auto & tile : tiles) {
        if (tile.second.squad == t)
            return tile.first;
    }
    return {-1, -1};
}

void Landscape::setSize(std::pair<int, int> n) {
    if (n.first < N || n.second < M)
        throw std::invalid_argument("Field can't become less.");
    N = n.first;
    M = n.second;
}

const Tile & Landscape::getUnit(std::pair<int, int> p) const {
    auto res = tiles.find(p);
    if (res == tiles.end())
        throw std::invalid_argument("there is no one on this tile");
    return res->second;
}

STile* Landscape::getNext() {
    if (moves.empty())
        return nullptr;
    auto p = moves.begin();
    move++;
    move %= moves.size();
    for (int i = 0; i < move; i++)
        ++p;
    return *p;
}

bool Landscape::setType(std::pair<int, int> point) {
    if (tiles.find(point) == tiles.end()) {
        tiles[point].type = block;
        tiles[point].squad = nullptr;
        tiles[point].point = point;
        return true;
    }
    else
        return false;
}

Landscape::Landscape(): N(10), M(10), move(0) {
    unsigned short number_of_blocks = N*M/2;
    unsigned short x, y;
    for (int i = 0; i < number_of_blocks; ++i) {
        x = rand() % N;
        y = rand() % M;
        setType({x,y});
    }
}

std::ofstream &operator<<(std::ofstream &s, const Landscape &l) {
    tileType type;
    for (int i = 0; i < l.N; ++i) {
        for (int j = 0; j < l.M; ++j) {
            type = l.getType({i, j});
            if (type == block)
                s << "  #   ";
            if (type == some_squad)
                s << "  S   ";
            if (type == nothing)
                s << "  0   ";
        }
        s << std::endl;
    }
    return s;
}

tileType Landscape::getType(std::pair<int, int> point) const {
    auto p = tiles.find(point);
    if (p == tiles.end())
        return nothing;
    if (p->second.type == some_squad)
        return some_squad;
    return block;
}
