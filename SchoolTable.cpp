//
// Created by flamy on 24/11/21.
//

#include "SchoolTable.h"

SchoolTable::SchoolTable(const SchoolTable &a) {
    std::map<const std::string, std::vector<Skill>>::const_iterator  p;
    for (p = a.schools.begin(); p != a.schools.end(); ++p) {
        schools.insert(std::make_pair(p->first, p->second));
    }
}

SchoolTable &SchoolTable::operator=(const SchoolTable &a) {
    std::map<const std::string, std::vector<Skill>>::const_iterator p;
    if (this != &a) {
        schools.clear();
        for (p = a.schools.begin(); p != a.schools.end(); ++p)
            schools.insert(std::make_pair(p->first, p->second));
    }
    return *this;
}

std::vector<Skill> &SchoolTable::operator[](const std::string & school) {
    auto p = schools.find(school);
    if (p == schools.end()) {
        std::vector<Skill> skills;
        auto pp = schools.insert(std::make_pair(school, skills));
        if(!pp.second)
            throw std::invalid_argument("Can't insert new item into map!");
        p = pp.first;
    }
    return p->second;
}

const std::vector<Skill> &SchoolTable::operator[](const std::string &s) const {
    auto p = schools.find(s);
    if (p == schools.end())
        throw std::invalid_argument("Incorrect index!");
    return p->second;
}

std::ostream &operator<<(std::ostream &s, const SchoolTable &t) {
    s << "School Table" << std::endl;
    for (const auto & school : t.schools) {
        s << school.first << ":" << std::endl;
        for (const auto & skill : school.second)
            s << skill;
    }
    return s;
}

void SchoolTable::insertSchool(const std::string & school) {
    auto p = schools.find(school);
    if (p == schools.end()) {
        std::vector<Skill> skills;
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


std::pair<const std::string, std::vector<Skill>> &ConstISchoolTable::operator*() {
    return *cur;
}


std::pair<const std::string, std::vector<Skill>> *ConstISchoolTable::operator->() {
    return &(*cur);
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
    for (const auto& skill : p->second) {
        if (skill.getName() == sk)
            return skill.creature;
    }
    throw std::invalid_argument("There is no such creature!");
}

Creature &SchoolTable::operator()(const std::string & school, const std::string & sk) {
    auto p = schools.find(school);
    if (p == schools.end())
        throw std::invalid_argument("There is no such school!");
    for (auto& skill : p->second) {
        if (skill.getName() == sk)
            return skill.creature;
    }
    std::vector<Skill> skills;
    auto pp = schools.insert(std::make_pair(school, skills));
    if(!pp.second)
        throw std::invalid_argument("Can't insert new item into map!");
    p = pp.first;
    return p->second[0].creature;
}

unsigned short SchoolTable::getCreatureNumber(const std::string& school) {
    auto p = schools.find(school);
    if (p == schools.end())
        throw std::invalid_argument("There is no such school!");
    unsigned short n = p->second.size();
    return n;
}
