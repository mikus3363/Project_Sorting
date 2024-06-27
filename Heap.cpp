//
// Created by mikus on 15.04.2024.
//

#include "Heap.h"
#include <iostream>
#include <chrono>

template <typename T>
int Heap::heapSort(T *tablica, int rozmiar) {
    auto start = std::chrono::steady_clock::now();
    for (int i = rozmiar / 2 - 1; i >= 0; i--)
        createHeap(tablica, rozmiar, i);

    // Wyodrębniamy elementy z kopca
    for (int i = rozmiar - 1; i > 0; i--) {
        // Przesuwamy korzeń na koniec tablicy
        swap(&tablica[0], &tablica[i]);

        // Ponownie budujemy kopiec na zmniejszonej tablicy
        createHeap(tablica, i, 0);
    }
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Czas wykonania Heap Sort: " << duration << " milisekund" << std::endl;

    return duration;
}
template int Heap::heapSort<int>(int tablica[], int rozmiar);
template int Heap::heapSort<float>(float tablica[], int rozmiar);

template <typename T>
void Heap::createHeap(T *tablica, int rozmiar, int indeks) {
    int largest = indeks;    // Inicjalizujemy największy element jako korzeń
    int left = 2 * indeks + 1;    // Indeks lewego dziecka w tablicy
    int right = 2 * indeks + 2;   // Indeks prawego dziecka w tablicy

    // Jeśli lewe dziecko jest większe od korzenia
    if (left < rozmiar && tablica[left] > tablica[largest])
        largest = left;

    // Jeśli prawe dziecko jest większe od największego elementu do tej pory
    if (right < rozmiar && tablica[right] > tablica[largest])
        largest = right;

    // Jeśli największy element nie jest korzeniem
    if (largest != indeks) {
        swap(&tablica[indeks], &tablica[largest]);

        // Rekurencyjnie kopjuj poddrzewo
        createHeap(tablica, rozmiar, largest);
    }
}

template <typename T>
void Heap::swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

