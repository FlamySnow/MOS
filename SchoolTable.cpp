//
// Created by flamy on 24/11/21.
//

#include "SchoolTable.h"

SchoolTable::SchoolTable(const SchoolTable &a) {
    Map<std::string, std::list<Skill>>::iterator  p;
    for (p = a.schools.begin(); p != a.schools.end(); ++p) {
        schools.insert(std::make_pair(p->data.first, p->data.second));
    }
}

SchoolTable &SchoolTable::operator=(const SchoolTable &a) {
    Map<std::string, std::list<Skill>>::iterator p;
    if (this != &a) {
        schools.clear();
        for (p = a.schools.begin(); p != a.schools.end(); ++p)
            schools.insert(std::make_pair(p->data.first, p->data.second));
    }
    return *this;
}

const std::list<Skill> &SchoolTable::operator[](const std::string & school) {
    auto p = schools.find(school);
    if (p == schools.end()) {
        std::list<Skill> skills;
        auto pp = schools.insert(std::make_pair(school, skills));
        if(!pp.second)
            throw std::invalid_argument("Can't insert new item into map!");
        p = pp.first;
    }
    return p->data.second;
}

const std::list<Skill> &SchoolTable::operator[](const std::string &s) const {
    auto p = schools.find(s);
    if (p == schools.end())
        throw std::invalid_argument("Incorrect index!");
    return p->data.second;
}

std::ostream &operator<<(std::ostream &s, const SchoolTable &t) {
    for (const auto & school : t.schools) {
        s << school.data.first << ":" << std::endl;
        for (const auto & skill : school.data.second)
            s << skill;
    }
    return s;
}

void SchoolTable::insertSchool(const std::string & school) {
    auto p = schools.find(school);
    if (p == schools.end()) {
        std::list<Skill> skills;
        auto pp = schools.insert(std::make_pair(school, skills));
        if(!pp.second)
            throw std::invalid_argument("Can't insert new item into map!");
    }
    else
        throw std::invalid_argument("This school is already in table!");
}

bool ConstISchoolTable::operator!=(const ConstISchoolTable &it) const {
    return cur != it.cur;
}

bool ConstISchoolTable::operator==(const ConstISchoolTable &it) const {
    return cur == it.cur;
}


std::pair<std::string, std::list<Skill>> &ConstISchoolTable::operator*() {
    return cur->data;
}


std::pair<std::string, std::list<Skill>> *ConstISchoolTable::operator->() {
    return &(cur->data);
}

ConstISchoolTable &ConstISchoolTable::operator++() {
    ++cur;
    return *this;
}


const ConstISchoolTable ConstISchoolTable::operator++(int) {
    ConstISchoolTable res(*this);
    ++cur;
    return res;
}

ConstISchoolTable SchoolTable::begin() {
    return ConstISchoolTable(schools.begin());
}

ConstISchoolTable SchoolTable::end() {
    return ConstISchoolTable(schools.end());
}

ConstISchoolTable SchoolTable::find(const std::string &s) {
    auto p = schools.find(s);
    return ConstISchoolTable(p);
}

const Creature &SchoolTable::operator ()(const std::string &school, const std::string &sk) const {
    auto p = schools.find(school);
    if (p == schools.end())
        throw std::invalid_argument("There is no such school!");
    for (const auto& skill : p->data.second) {
        if (skill.getName() == sk)
            return skill.creature;
    }
    throw std::invalid_argument("There is no such creature!");
}

Creature &SchoolTable::operator()(const std::string & school, const std::string & sk) {
    auto p = schools.find(school);
    if (p == schools.end())
        throw std::invalid_argument("There is no such school!");
    for (auto& skill : p->data.second) {
        if (skill.getName() == sk)
            return skill.creature;
    }
    std::list<Skill> skills;
    auto pp = schools.insert(std::make_pair(school, skills));
    if(!pp.second)
        throw std::invalid_argument("Can't insert new item into map!");
    p = pp.first;
    return p->data.second.front().creature;
}

int SchoolTable::getCreatureNumber(const std::string& school) {
    auto p = schools.find(school);
    if (p == schools.end())
        throw std::invalid_argument("There is no such school!");
    int n = p->data.second.size();
    return n;
}

void SchoolTable::insertSkill(const std::string &school, const Skill& sk) {
    auto p = schools.find(school);
    if (p == schools.end())
        throw std::invalid_argument("There is no such school!");
    for (const auto &skill : p->data.second) {
        if (skill == sk)
            throw std::invalid_argument("There is this skill already!");
    }
    schools[school].push_back(sk);
}
