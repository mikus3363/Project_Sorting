//
// Created by mikus on 15.04.2024.
//

#ifndef PROJEKTAIZO_HEAP_H
#define PROJEKTAIZO_HEAP_H


class Heap {
    template <typename T>
    void createHeap(T tablica[], int rozmiar, int indeks);
    template <typename T>
    void swap(T *a, T *b);
public:
    template <typename T>
    int heapSort(T tablica[], int rozmiar);
};


#endif //PROJEKTAIZO_HEAP_H
