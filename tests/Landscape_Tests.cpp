//
// Created by flamy on 15/12/21.
//

#include "Landscape.h"
#include "gtest/gtest.h"

TEST (Landscape, LandscapeConstructor1) {
    Landscape l;
    ASSERT_EQ(l.getSize(), std::make_pair(100, 100));
    auto p = l.getNext();
    ASSERT_EQ(nullptr, p);
}

TEST (Landscape, LandscapeConstructor2) {
    Landscape l (50, 50, 30);
    ASSERT_EQ(l.getSize(), std::make_pair(50, 50));
    ASSERT_EQ(nullptr, l.getNext());
}

TEST (Landscape, addSquad) {
    Landscape l;
    Tile s;
    s.point = {3, 4};
    s.type = some_squad;
    Creature c {"Murka", 10, 5, 3};
    auto squad = new Squad ("Player", c, 10);
    s.squad = squad;
    l.addSquad(s);
    auto p = l.getNext();
    auto unit = dynamic_cast<Squad*>(p);
    auto p2 = l.getUnit({3, 4});
    ASSERT_EQ(unit->getName(), "Player");
    ASSERT_EQ(p2.squad, squad);
}

TEST (Landscape, MoveSquad) {
    Landscape l;
    Tile s;
    s.point = {3, 4};
    s.type = some_squad;
    Creature c {"Murka", 10, 5, 3};
    auto squad = new Squad ("Player", c, 10);
    s.squad = squad;
    l.addSquad(s);
    l.moveSquad(1, 1, s);
    ASSERT_EQ(l.getUnit({1,1}).squad, squad);
}