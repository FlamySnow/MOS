//
// Created by flamy on 23/11/21.
//

#ifndef MOS_CREATURE_H
#define MOS_CREATURE_H

#include <string>
#include <utility>
#include <stdexcept>
#include <iostream>
/// Класс, описывающий существо, которое может состоять в отряде и его основные свойства.
class Creature {
    std::string name; //< имя существа
    unsigned short attack; //< базовая атака
    unsigned short speed; //< скорость перемещения по полю
    unsigned short initiative; //< инициатива определяет скорость хода отряда, состоящего из данного существа
    unsigned short health; //< базовое здоровье
    unsigned short exp; //< опыт за убийство существа
    bool morale; //< является ли существо моральным, в соответствии с этим создаётся либо моральный класс, либо аморальный
    bool revival; //< могут ли данные существа быть воскрешены

    static bool isCorrectATK(unsigned short a) {return  a <= 10000;};
    static bool isCorrectINTV(unsigned short a) {return a <= 100; }
    static bool isCorrectHP(unsigned short a) {return a >= 10 && a <= 10000;}
    static bool isCorrectEXP(unsigned short a) {return a >= 1 && a <= 1000;}
    static bool isCorrectSPD(unsigned short a) {return a <= 10;};
public:
    ///конструктор, принимет все параметры-поля класса
    explicit Creature(const std::string& s = "Nameless", unsigned short atk = 0, unsigned short spd = 0, unsigned short intv = 0, unsigned short hp = 10, unsigned short exp = 1, bool mrl = true, bool rvl = false);

    [[nodiscard]] const std::string& getName () const;
    [[nodiscard]] unsigned short getATK() const {return attack;};
    [[nodiscard]] unsigned short getINTV() const {return initiative;};
    [[nodiscard]] unsigned short getHP() const {return health;};
    [[nodiscard]] unsigned short getEXP() const {return exp;};
    [[nodiscard]] unsigned short getSPD() const {return speed;};
    [[nodiscard]] bool isRevival() const {return revival;};
    [[nodiscard]] bool isMorale() const {return morale;};

    void setName(const std::string&);
    void setATK(unsigned short);
    void setSPD(unsigned short);
    void setINTV(unsigned short);
    void setHP(unsigned short);
    void setEXP(unsigned short);
    void setRVL(bool a) {revival = a;};
    void setMRL(bool a) {morale = a;};
///перегрузка оператора вывода
    friend std::ostream& operator << (std::ostream&, const Creature&);
};


#endif //MOS_CREATURE_H
