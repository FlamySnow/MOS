//
// Created by flamy on 24/11/21.
//

#ifndef SCHOOLTABLE_INPUT_H
#define SCHOOLTABLE_INPUT_H

#include <iostream>

enum errorType {
    ok,
    incorrectInput,
    eof
};

template <class T>
errorType input (T &a){
    std::cin >> a;
    if (!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return incorrectInput;
    }
    if (std::cin.eof())
        return eof;
    return ok;
}

template <class T>
void checkInput (T &a) {
    errorType error;
    do {
        error = input(a);
        if (error == eof || error == incorrectInput)
            std::cout << "Enter only numbers, please!" << std::endl;
    } while (error != ok);
}

#endif //SCHOOLTABLE_INPUT_H
