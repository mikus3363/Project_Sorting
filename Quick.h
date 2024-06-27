//
// Created by mikus on 15.04.2024.
//

#ifndef PROJEKTAIZO_QUICK_H
#define PROJEKTAIZO_QUICK_H


class Quick {
    template <typename T>
    int partition(T *tablica, int start, int end, int pivotChoice);

    template <typename T>
    int partitionRev(T *tablica, int start, int end, int pivotChoice);

    template <typename T>
    int choosePivot(T *tablica, int start, int end, int pivotChoice);

    template <typename T>
    void swap(T *a, T *b);


public:
    template <typename T>
    int quickSorting(T *tablica, int start, int end, int pivotChoice);
    template <typename T>
    void quickSort(T *tablica, int start, int end, int pivotChoice, int i);
};


#endif //PROJEKTAIZO_QUICK_H
