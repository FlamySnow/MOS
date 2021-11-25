//
// Created by flamy on 24/11/21.
//

#include "../MoraleSquad.h"
#include "../Input.h"
#include "../Summoner.h"

int main() {
    int a = 0, b;
    SchoolTable table;
    std::string s, t, r;
    Creature c;
    do {
        std::cout << "0. Quit;" << std::endl;
        std::cout << "1. Print school table" << std::endl;
        std::cout << "2. Insert school" << std::endl;
        std::cout << "3. Get creature" << std::endl;
        std::cout << "4. Set creature" << std::endl;
        std::cout << "5. Get vector of skills" << std::endl;
        std::cout << "6. Add skill in school" << std::endl;
        std::cout << "7. Get number of schools" << std::endl;
        std::cout << "8. Get number of creatures in school" << std::endl;
        std::cout << "Make your choice: --> ";
        checkInput(a);
        std::cout << std::endl;
        try {
            switch (a) {
                case 1: {
                    std::cout << table;
                }
                    break;
                case 2: {
                    std::cout << "Enter school: ";
                    std::cin >> s;
                    table.insertSchool(s);
                }
                    break;
                case 3: {
                    std::cout << "Enter school: --> ";
                    std::cin >> s;
                    std::cout << "Enter skill: --> ";
                    std::cin >> t;
                    std::cout << table(s,t);
                }
                    break;
                case 4: {
                    std::cout << "Enter name of creature: ";
                    std::cin >> s;
                    c = Creature(s);
                    std::cout << "Enter school: --> ";
                    std::cin >> t;
                    std::cout << "Enter skill: --> ";
                    std::cin >> r;
                    table(t, r) = c;
                }
                    break;
                case 5: {
                    std::cout << "Enter school: ";
                    std::cin >> s;
                    for (const auto& skill: table[s])
                        std::cout << skill;
                }
                    break;
                case 6: {
                    std::cout << "Enter skill: ";
                    std:: cin >> s;
                    Skill skill(s);
                    std::cout << "Enter school: ";
                    std::cin >> t;
                    table[t].push_back(skill);
                }
                    break;
                case 7: {
                    std::cout << table.getSchoolNumber();
                }
                    break;
                case 8: {
                    std::cout << "Enter school: ";
                    std::cin >> s;
                    std::cout << table.getCreatureNumber(s);
                }
                case 0: {
                    break;
                }
                default: {
                    std::cout << "Enter only numbers from 0 to 8!" << std::endl;
                }
                    break;
            }
        }
        catch (std::exception &e) {
            std::cout << e.what();
        }
    std::cout << std::endl;
    } while (a != 0);
    Creature cat1 {"Murka", 50, 5, 50, 100, 25, true, false};
    Creature cat2 {"Silence", 50, 5, 40, 200, 25, false, true};
    MoraleSquad s1 ("Nastenka", cat1, 5);
    Squad s2 ("Andrey", cat2, 5);
    do {
        std::cout << "0. Quit;" << std::endl;
        std::cout << "1. Print squad" << std::endl;
        std::cout << "2. Attack squad" << std::endl;
        std::cout << "3. Resurrect creatures" << std::endl;
        std::cout << "4. Balance morale" << std::endl;
        std::cout << "5. Decrease morale" << std::endl;
        std::cout << "6. Increase morale" << std::endl;
        std::cout << "Make your choice: --> ";
        checkInput(a);
        std::cout << std::endl;
        try {
            switch (a) {
                case 1: {
                    std::cout << s1;
                }
                    break;
                case 2: {
                    std::cout << "Enter damage: ";
                    checkInput(b);
                    s1.getHurt(b);
                }
                    break;
                case 3: {
                    std::cout << "Enter number: ";
                    checkInput(b);
                    s1.resurrect(b);
                }
                    break;
                case 4: {
                    s1.balanceMorale();
                }
                    break;
                case 5: {
                    s1.decreaseMorale();
                }
                    break;
                case 6: {
                    s1.increaseMorale();
                }
                    break;
                case 0: {
                    break;
                }
                default: {
                    std::cout << "Enter only numbers from 0 to 8!" << std::endl;
                }
                    break;
            }
        }
        catch (std::exception &e) {
            std::cout << e.what();
        }
        std::cout << std::endl;
    } while (a != 0);

    do {
        std::cout << "0. Quit;" << std::endl;
        std::cout << "1. Print squad" << std::endl;
        std::cout << "2. Attack squad" << std::endl;
        std::cout << "3. Resurrect creatures" << std::endl;
        std::cout << "Make your choice: --> ";
        checkInput(a);
        std::cout << std::endl;
        try {
            switch (a) {
                case 1: {
                    std::cout << s2;
                }
                    break;
                case 2: {
                    std::cout << "Enter damage: ";
                    checkInput(b);
                    s2.getHurt(b);
                }
                    break;
                case 3: {
                    std::cout << "Enter number: ";
                    checkInput(b);
                    s2.resurrect(b);
                }
                    break;
                case 0: {
                    break;
                }
                default: {
                    std::cout << "Enter only numbers from 0 to 3!" << std::endl;
                }
                    break;
            }
        }
        catch (std::exception &e) {
            std::cout << e.what();
        }
        std::cout << std::endl;
    } while (a != 0);

    Summoner summoner;

    do {
        std::cout << "0. Quit;" << std::endl;
        std::cout << "1. Print information" << std::endl;
        std::cout << "2. Accumulate energy" << std::endl;
        std::cout << "3. Receive experience" << std::endl;
        std::cout << "4. Take damage" << std::endl;
        std::cout << "Make your choice: --> ";
        checkInput(a);
        std::cout << std::endl;
        try {
            switch (a) {
                case 1: {
                    std::cout << summoner;
                }
                    break;
                case 2: {
                    std::cout << "Enter energy: ";
                    checkInput(b);
                    summoner.accumulate(b);
                }
                    break;
                case 3: {
                    std::cout << "Enter number: ";
                    checkInput(b);
                    summoner.receiveEXP(b);
                }
                break;
                case 4: {
                    std::cout << "Enter damage: ";
                    checkInput(b);
                    summoner.getHurt(b);
                }
                    break;
                case 0: {
                    break;
                }
                default: {
                    std::cout << "Enter only numbers from 0 to 3!" << std::endl;
                }
                    break;
            }
        }
        catch (std::exception &e) {
            std::cout << e.what();
        }
        std::cout << std::endl;
    } while (a != 0);

    return 0;
}