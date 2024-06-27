//
// Created by mikus on 15.04.2024.
//

#include <valarray>
#include <iostream>
#include <chrono>
#include "Shell.h"

template <typename T>
int Shell::shellSortDef(T *tablica, int rozmiar) {
    auto start = std::chrono::steady_clock::now();
    int przerwa = rozmiar / 2;
    while(przerwa >= 1) {
        for (int i = przerwa; i < rozmiar; i += 1) {
            T temp = tablica[i];
            int j;
            for (j = i; j >= przerwa && tablica[j - przerwa] > temp; j -= przerwa)
                tablica[j] = tablica[j - przerwa];
            tablica[j] = temp;
        }
        przerwa /= 2;
    }
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Czas wykonania Shell Sort: " << duration << " milisekund" << std::endl;

    return duration;
}

template int Shell::shellSortDef<int>(int tablica[], int rozmiar);
template int Shell::shellSortDef<float>(float tablica[], int rozmiar);

template <typename T>
int Shell::shellSortKnuth(T *tablica, int rozmiar) {
    auto start = std::chrono::steady_clock::now();
    int k = 1;
    while ((pow(3, k) - 1) / 2 <= ceil(rozmiar / 3))
        k++;
    int przerwa = (pow(3, k) - 1) / 2;
    while (przerwa >= 1) {
        for (int i = przerwa; i < rozmiar; i += 1) {
            T temp = tablica[i];
            int j;
            for (j = i; j >= przerwa && tablica[j - przerwa] > temp; j -= przerwa)
                tablica[j] = tablica[j - przerwa];
            tablica[j] = temp;
        }
        przerwa = (przerwa - 1) / 3;
    }
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Czas wykonania Shell Sort: " << duration << " milisekund" << std::endl;

    return duration;
}

template int Shell::shellSortKnuth<int>(int tablica[], int rozmiar);
template int Shell::shellSortKnuth<float>(float tablica[], int rozmiar);