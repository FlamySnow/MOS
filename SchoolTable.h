//
// Created by flamy on 24/11/21.
//

#ifndef MOS_SCHOOLTABLE_H
#define MOS_SCHOOLTABLE_H
#include "Skill.h"
#include "../template/Map.h"
#include <list>


/// итератор таблицы
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

/// Таблица со школами и соответствующими ей навыками, создаётся в начале игры и постоянна для всех её состояний.

class SchoolTable {
    Map<std::string, std::list<Skill>> schools;

public:
    SchoolTable() = default;
    SchoolTable(const SchoolTable&);

    SchoolTable& operator = (const SchoolTable &);
    const std::list<Skill> & operator [] (const std::string&); //< получение списка навыков, список нельзя изменять
    const std::list<Skill>& operator [] (const std::string&) const;//< почти то же самое
    friend std::ostream & operator << (std::ostream&, const SchoolTable&); //< перегруженный оператор вывода

    friend class ConstISchoolTable;

    ConstISchoolTable begin();
    ConstISchoolTable end();

    void insertSchool(const std::string &);//< вставка школы, фактически появление новой строки в таблице
    void insertSkill(const std::string &school, const Skill& sk); //< вставка навыка в школу, если школы нет, то вставка не удастся
    const Creature& operator () (const std::string &, const std::string&) const;//< получение константной ссылки на существо по названиям школы и навыка
    Creature& operator () (const std::string &, const std::string&);//< то же самое, но ссылка позволяет изменить состояние описателя существа
    int getSchoolNumber() {return schools.size();}; //< получение количества школ
    int getCreatureNumber(const std::string&); //< получение количества существ в школе, равно количеству навыков школы

private:
    ConstISchoolTable find(const std::string&);
};






#endif //MOS_SCHOOLTABLE_H
