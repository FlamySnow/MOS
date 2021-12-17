//
// Created by flamy on 14/12/21.
//

#ifndef MOS_LANDSCAPE_H
#define MOS_LANDSCAPE_H

#include "SchoolTable.h"
#include "Summoner.h"
#include "MoraleSquad.h"
#include "Tile.h"
#include <set>
#include <map>
#include <fstream>
#include <random>

/// Класс, отвечающий за описание уровня и его состояние.
class Landscape {
    /// клетки поля, обечпечивают быструю проверку занятых клеток и доступ к объектам на клетках
    std::map<std::pair<int, int>, struct Tile> tiles;
    /// сортированное список отрядов/призывателей по инициативе
    std::set<STile*> moves;
    int N; //< текущий размер поля по ширине
    int M; //< текущий размер поля по высоте
    int move; //< номер хода

    std::pair<int, int> findPoint(STile* t) const;

public:
    /// таблица школ
    SchoolTable table;

    Landscape();
    Landscape(int n, int m, int move);
/// Adds new squad, throws an exception if squad already exists
/// Coordinates of s must be set
    bool addSquad(Tile s);
    /// Moves squad in (x, y) and changes coordinates of s
    void moveSquad(int x, int y, Tile s);
    [[nodiscard]] std::pair<int, int> getSize() const {return {N, M};};
    void setSize(std::pair<int, int>);
    //void loadTable();
    /// получение отряда/призывателя по координате
    [[nodiscard]] const Tile& getUnit(std::pair<int, int> p) const;
    /// Получение указателя той единицы, которая будет ходить следующей
    STile * getNext();
    bool setType(std::pair<int, int> point);
    [[nodiscard]] tileType getType (std::pair<int, int> point) const;
    friend std::ofstream& operator << (std::ofstream& s, const Landscape & l);
};


#endif //MOS_LANDSCAPE_H
