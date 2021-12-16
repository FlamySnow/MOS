//
// Created by flamy on 24/11/21.
//

#include "../Skill.h"
#include "gtest/gtest.h"

TEST (SkillConstructors, EmptyConstructor) {
    Skill skill;
    ASSERT_EQ("Nameless", skill.getName());
    ASSERT_EQ(1, skill.getKD());
    ASSERT_EQ(1, skill.getEG());
    ASSERT_EQ(1, skill.getCFF());
}

TEST (SkillConstructors, InitialConstructor) {
    std::string s = "Ks-ks-ks";
    unsigned short a = 50;
    Skill skill {s, a, a, a};
    ASSERT_EQ(s, skill.getName());
    ASSERT_EQ(a, skill.getKD());
    ASSERT_EQ(a, skill.getEG());
    ASSERT_EQ(a, skill.getCFF());
}

TEST (SkillConstructors, InitialConstructorExceptions) {
    std::string s;
    ASSERT_ANY_THROW(Skill skill (s));
    unsigned short a = 0;
    s = "Ks-ks-ks";
    ASSERT_ANY_THROW(Skill skill(s, a, a, a));
    a = 101;
    ASSERT_ANY_THROW(Skill skill(s, a, a, a));
}

TEST (SkillSetters, NameSetter) {
    std::string s = "Ks-ks-ks";
    Skill skill;
    skill.setName(s);
    ASSERT_EQ(s, skill.getName());
}

TEST (SkillSetters, NameSetterException) {
    std::string s;
    Skill skill;
    ASSERT_ANY_THROW(skill.setName(s));
}

TEST (SkillSetters, KDSetter) {
    Skill skill;
    unsigned short a = 34;
    skill.setKD(a);
    ASSERT_EQ(a, skill.getKD());
}

TEST (SkillSetters, KDSetterExceptions) {
    Skill skill;
    unsigned short a = 0;
    ASSERT_ANY_THROW(skill.setKD(a));
    a = 101;
    ASSERT_ANY_THROW(skill.setKD(a));
}

TEST (SkillSetters, EGSetter) {
    Skill skill;
    unsigned short a = 25;
    skill.setEG(a);
    ASSERT_EQ(a, skill.getEG());
}

TEST (SkillSetters, EGSetterExceptions) {
    Skill skill;
    unsigned short a = 0;
    ASSERT_ANY_THROW(skill.setEG(a));
    a = 101;
    ASSERT_ANY_THROW(skill.setEG(a));
}

TEST (SkillSetters, CFFSetter) {
    Skill skill;
    unsigned short a = 10;
    skill.setCFF(a);
    ASSERT_EQ(a, skill.getCFF());
}

TEST (SkillSetters, CFFSetterExceptions) {
    Skill skill;
    unsigned short a = 0;
    ASSERT_ANY_THROW(skill.setCFF(a));
    a = 101;
    ASSERT_ANY_THROW(skill.setCFF(a));
}