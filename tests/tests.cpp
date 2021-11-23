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
}

TEST (Constructors, InitialConstructor) {
    std::string s = "Murka";
    unsigned short a = 50, b = 1;
    Creature c {s, a, b, a, a, a};
    ASSERT_EQ(s, c.getName());
    ASSERT_EQ(a, c.getATK());
    ASSERT_EQ(a, c.getINTV());
    ASSERT_EQ(a, c.getHP());
    ASSERT_EQ(a, c.getEXP());
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

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}