//
// Created by mikus on 15.04.2024.
//

#ifndef PROJEKTAIZO_SHELL_H
#define PROJEKTAIZO_SHELL_H


class Shell {
public:
    template <typename T>
    int shellSortDef(T *tablica, int rozmiar);
    template <typename T>
    int shellSortKnuth(T *tablica, int rozmiar);
};


#endif //PROJEKTAIZO_SHELL_H
