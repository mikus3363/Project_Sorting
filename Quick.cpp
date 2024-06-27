//
// Created by mikus on 15.04.2024.
//

#include "Quick.h"
#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;

template <typename T>
int Quick::quickSorting(T *tablica, int begin, int ending, int pivotChoice) {

    auto start = std::chrono::steady_clock::now();

    quickSort(tablica, begin, ending, pivotChoice,0);

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Czas wykonania Quick Sort: " << duration << " milisekund" << std::endl;

    return duration;
}
template int Quick::quickSorting<int>(int tablica[], int start, int end, int pivotChoice);
template int Quick::quickSorting<float>(float tablica[], int start, int end, int pivotChoice);


template <typename T>
void Quick::quickSort(T *tablica, int begin, int ending, int pivotChoice, int i) {

    if (begin < ending && i == 0) {
        T pivotIndex = partition(tablica, begin, ending, pivotChoice);
        quickSort(tablica, begin, pivotIndex - 1, pivotChoice, 0);
        quickSort(tablica, pivotIndex + 1, ending, pivotChoice, 0);
    }
    else if (begin < ending && i == 1) {
        T pivotIndex = partitionRev(tablica, begin, ending, pivotChoice);
        quickSort(tablica, begin, pivotIndex - 1, pivotChoice, 1);
        quickSort(tablica, pivotIndex + 1, ending, pivotChoice, 1);
    }
}
template void Quick::quickSort<int>(int tablica[], int begin, int ending, int pivotChoice, int i);
template void Quick::quickSort<float>(float tablica[], int begin, int ending, int pivotChoice, int i);

template <typename T>
int Quick::partition(T *tablica, int start, int end, int pivotChoice) {
    int pivotIndex = choosePivot(tablica, start, end, pivotChoice);
    T pivotValue = tablica[pivotIndex];
    swap(&tablica[pivotIndex], &tablica[end]); // Przenoszenie piwota na koniec tablicy
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (tablica[j] < pivotValue) { //zależność malejąco/rosnąco
            i++;
            swap(&tablica[i], &tablica[j]);
        }
    }
    swap(&tablica[i + 1], &tablica[end]); // Umieszczanie piwota na właściwej pozycji
    return i + 1;
}

template <typename T>
int Quick::partitionRev(T *tablica, int start, int end, int pivotChoice) {
    int pivotIndex;
    pivotIndex = choosePivot(tablica, start, end, pivotChoice);
    T pivotValue = tablica[pivotIndex];
    swap(&tablica[pivotIndex], &tablica[end]); // Przenoszenie piwota na koniec tablicy
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (tablica[j] > pivotValue) { //zależność malejąco/rosnąco
            i++;
            swap(&tablica[i], &tablica[j]);
        }
    }
    swap(&tablica[i + 1], &tablica[end]); // Umieszczanie piwota na właściwej pozycji
    return i + 1;
}

template <typename T>
int Quick::choosePivot(T *tablica, int start, int end, int pivotChoice) {
    srand(time(0));
    if (pivotChoice == 1) // Wybór pierwszego elementu jako piwota
        return start;
    else if (pivotChoice == 2) // Wybór ostatniego elementu jako piwota
        return end;
    else if (pivotChoice == 4) // Wybór losowego elementu jako piwota
        return (rand() %end-start) + start ;
    else // Wybór środkowego elementu jako piwota
        return start + (end - start) / 2;
}

template <typename T>
void Quick::swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}