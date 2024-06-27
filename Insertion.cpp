//
// Created by mikus on 06.04.2024.
//

#include "Insertion.h"
#include <chrono>
#include <iostream>

template <typename T>
int Insertion::insertionSort(T tablica[], int rozmiar) {
    auto start = std::chrono::steady_clock::now();
    T key;
    int i, j;
    for (i = 1; i < rozmiar; i++) {
        key = tablica[i];
        j = i - 1;

        while (j >= 0 && tablica[j] > key) {
            tablica[j + 1] = tablica[j];
            j = j - 1;
        }
        tablica[j + 1] = key;
    }
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Czas wykonania Insertion Sort: " << duration << " milisekund" << std::endl;

    return duration;
}

template int Insertion::insertionSort<int>(int tablica[], int rozmiar);
template int Insertion::insertionSort<float>(float tablica[], int rozmiar);