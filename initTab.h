//
// Created by mikus on 05.04.2024.
//

#ifndef PROJEKTAIZO_INITTAB_H
#define PROJEKTAIZO_INITTAB_H
#include <iostream>
#include <vector>
using namespace std;

class initTab {
public:
    void pushInt(int tablica[], int rozmiar, int t);
    void pushFloat(float tablica[], int rozmiar,int t);
    template <typename T>
    void wyswietlTab(T tablica[], int rozmiar);
    template <typename T>
    void wyczyscTab(T tablica[], int rozmiar);
    template <typename T>
    void copyArray(T* source, T* destination, int size);
    template <typename T>
    void openFile(string nazwaPliku, vector<T>& tablica);
};


#endif //PROJEKTAIZO_INITTAB_H
