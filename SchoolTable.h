//
// Created by flamy on 24/11/21.
//

#ifndef MOS_SCHOOLTABLE_H
#define MOS_SCHOOLTABLE_H
#include "Skill.h"
#include <map>
#include <vector>

class ConstISchoolTable {
    std::map<const std::string, std::vector<Skill>>::iterator cur;
public:
    ConstISchoolTable() = default;;
    explicit ConstISchoolTable(std::map<const std::string, std::vector<Skill>>::iterator it): cur(it) {};

    bool operator !=(const ConstISchoolTable &) const;
    bool operator ==(const ConstISchoolTable &) const;

    std::pair<const std::string, std::vector<Skill>> & operator *();
    std::pair<const std::string, std::vector<Skill>>* operator ->();

    ConstISchoolTable & operator ++();
    const ConstISchoolTable operator ++(int);
};

class SchoolTable {
    std::map<std::string, std::vector<Skill>> schools;

public:
    SchoolTable() = default;
    SchoolTable(const SchoolTable&);

    SchoolTable& operator = (const SchoolTable &);
    std::vector<Skill> & operator [] (const std::string&);
    const std::vector<Skill>& operator [] (const std::string&) const;
    friend std::ostream & operator << (std::ostream&, const SchoolTable&);

    friend class ConstISchoolTable;

    ConstISchoolTable begin();
    ConstISchoolTable end();

    void insertSchool(const std::string &);
    const Creature& operator () (const std::string &, const std::string&) const;
    Creature& operator () (const std::string &, const std::string&);
    unsigned short getSchoolNumber() {return schools.size();};
    unsigned short getCreatureNumber(const std::string&);

private:
    ConstISchoolTable find(const std::string&);
};






#endif //MOS_SCHOOLTABLE_H
