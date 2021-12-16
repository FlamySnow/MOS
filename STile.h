//
// Created by flamy on 14/12/21.
//

#ifndef MOS_STILE_H
#define MOS_STILE_H

enum SType {
    squad, //< отряд
    summoner, //< призыватель
    unknown //< что-то странное
};

/**
 * Это сделано в целях получения возможности создания сортированного списка (set) отрядов и существ по инициативе.
 **/

/// Это базовый абстрактный класс, от него наследуются классы-описатели отряда и призывателя.
class STile {
protected:
    int initiative;//< инициатива отряда или существа
    SType type; //< тип существа
public:
    STile(): initiative(50), type(unknown) {};
    STile(int intv, SType t): initiative(intv), type(t) {};
    bool operator < (const STile& t) const {return initiative < t.initiative;};
    /// перегруженная функция в целях обеспечения полиморфизма и работы dynamic_cast<>()
    virtual int getINTV() {return initiative;};
    [[nodiscard]] SType getType() const {return type;};//< получение типа существа - отряд или призыватель
};


#endif //MOS_STILE_H
