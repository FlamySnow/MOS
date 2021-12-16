//
// Created by flamy on 23/11/21.
//

#include "../Creature.h"
#include "gtest/gtest.h"

 TEST (CreatureConstructors, EmptyConstructor) {
    Creature c;
    const std::string& s = c.getName();
    unsigned short a;
    ASSERT_EQ("Nameless", s);
    a = c.getATK();
    ASSERT_EQ(0, a);
    a = c.getEXP();
    ASSERT_EQ(1, a);
    a = c.getHP();
    ASSERT_EQ(10, a);
    a = c.getINTV();
    ASSERT_EQ(0, a);
    a = c.getSPD();
    ASSERT_EQ(0, a);
    ASSERT_EQ(true, c.isMorale());
    ASSERT_EQ(false, c.isRevival());
}

TEST (Constructors, InitialConstructor) {
    std::string s = "Murka";
    unsigned short a = 50, b = 1;
    bool d = true;
    Creature c {s, a, b, a, a, a, d, d};
    ASSERT_EQ(s, c.getName());
    ASSERT_EQ(a, c.getATK());
    ASSERT_EQ(a, c.getINTV());
    ASSERT_EQ(a, c.getHP());
    ASSERT_EQ(a, c.getEXP());
    ASSERT_EQ(d, c.isMorale());
    ASSERT_EQ(d, c.isRevival());
}

TEST (Constructors, InitialConstructorException1) {
    std::string s;
    unsigned short a = 50, b = 5;
    ASSERT_ANY_THROW(Creature c(s, a, b, a, a, a));
}

TEST (Constructors, InitialConstructorException2) {
    std::string s = "Murka";
    unsigned short a = 5;
    ASSERT_ANY_THROW (Creature c(s, a, a, a, a, a));
}

TEST (Constructors, InitialConstructorException3) {
    std::string s = "Murka";
    unsigned short a = 0;
    ASSERT_ANY_THROW (Creature c(s, a, a, a, a, a));
}

TEST (Constructors, InitialConstructorException4) {
    std::string s = "Murka";
    short a = -5;
    ASSERT_ANY_THROW (Creature c(s, a, a, a, a, a));
}

TEST (Setters, NameSetter) {
    std::string s = "Murka";
    Creature c;
    c.setName(s);
    ASSERT_EQ(s, c.getName());
}

TEST (Setters, NameSetterException) {
    std::string s;
    Creature c;
    ASSERT_ANY_THROW(c.setName(s));
}

TEST (Setters, ATKSetter) {
    Creature c;
    unsigned short a = 500;
    c.setATK(a);
    ASSERT_EQ(a, c.getATK());
}

TEST (Setters, ATKSetterException1) {
    Creature c;
    short a = -6;
    ASSERT_ANY_THROW(c.setATK(a));
}

TEST (Setters, ATKSetterException2) {
    Creature c;
    unsigned short a = 20000;
    ASSERT_ANY_THROW(c.setATK(a));
}

TEST (Setters, SPDSetter) {
    Creature c;
    unsigned short a = 5;
    c.setSPD(a);
    ASSERT_EQ(a, c.getSPD());
}

TEST (Setters, SPDSetterException1) {
    Creature c;
    short a = -1;
    ASSERT_ANY_THROW(c.setSPD(a));
}

TEST (Setters, SPDSetterException2) {
    Creature c;
    unsigned short a = 11;
    ASSERT_ANY_THROW(c.setSPD(a));
}

TEST (Setters, INTVSetter) {
    Creature c;
    unsigned short a = 50;
    c.setINTV(50);
    ASSERT_EQ(a, c.getINTV());
}

TEST (Setters, INTVSetterException) {
    Creature c;
    unsigned short a = 101;
    ASSERT_ANY_THROW(c.setINTV(a));
    short b = -5;
    ASSERT_ANY_THROW(c.setINTV(b));
}

TEST (Setters, HPSetter) {
    Creature c;
    unsigned short a = 10;
    c.setHP(a);
    ASSERT_EQ(a, c.getHP());
    a = 10000;
    c.setHP(a);
    ASSERT_EQ(a, c.getHP());
}

TEST (Setters, HPSetterExceptions) {
    Creature c;
    unsigned short a = 9;
    ASSERT_ANY_THROW(c.setHP(a));
    a = 10001;
    ASSERT_ANY_THROW(c.setHP(a));
}

TEST (Setters, EXPSetter) {
    Creature c;
    unsigned short a = 525;
    c.setEXP(a);
    ASSERT_EQ(a, c.getEXP());
    a = 1;
    c.setEXP(a);
    ASSERT_EQ(a, c.getEXP());
    a = 1000;
    c.setEXP(a);
    ASSERT_EQ(a, c.getEXP());
}

TEST (Setters, EXPSetterExceptions) {
    Creature c;
    unsigned short a = 0;
    ASSERT_ANY_THROW(c.setEXP(a));
    a = 1001;
    ASSERT_ANY_THROW(c.setEXP(a));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}