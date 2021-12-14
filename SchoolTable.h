//
// Created by flamy on 24/11/21.
//

#ifndef MOS_SCHOOLTABLE_H
#define MOS_SCHOOLTABLE_H
#include "Skill.h"
#include "../template/Map.h"
#include <list>

class ConstISchoolTable {
    Map<std::string, std::list<Skill>>::iterator cur;
public:
    ConstISchoolTable() = default;;
    explicit ConstISchoolTable(MapIterator<std::string, std::list<Skill>> it): cur(it) {};

    bool operator !=(const ConstISchoolTable &) const;
    bool operator ==(const ConstISchoolTable &) const;

    std::pair<std::string, std::list<Skill>> & operator *();
    std::pair<std::string, std::list<Skill>>* operator ->();

    ConstISchoolTable & operator ++();
    const ConstISchoolTable operator ++(int);
};

class SchoolTable {
    Map<std::string, std::list<Skill>> schools;

public:
    SchoolTable() = default;
    SchoolTable(const SchoolTable&);

    SchoolTable& operator = (const SchoolTable &);
    const std::list<Skill> & operator [] (const std::string&);
    const std::list<Skill>& operator [] (const std::string&) const;
    friend std::ostream & operator << (std::ostream&, const SchoolTable&);

    friend class ConstISchoolTable;

    ConstISchoolTable begin();
    ConstISchoolTable end();

    void insertSchool(const std::string &);
    void insertSkill(const std::string &school, const Skill& sk);
    const Creature& operator () (const std::string &, const std::string&) const;
    Creature& operator () (const std::string &, const std::string&);
    int getSchoolNumber() {return schools.size();};
    int getCreatureNumber(const std::string&);

private:
    ConstISchoolTable find(const std::string&);
};






#endif //MOS_SCHOOLTABLE_H
