//
// Created by mikus on 05.04.2024.
//

#include "initTab.h"
#include <iostream>
#include <cstdlib>
#include "Quick.h"
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;
Quick quickrev;

void initTab::pushInt(int *tablica, int rozmiar, int t) {
    if (t == 1) {
        srand(time(0));
        for (int i = 0; i < rozmiar; ++i) {
            tablica[i] = rand();
        }

        quickrev.quickSort(tablica,0,rozmiar-1,1,0);

        srand(time(0));
        int j;
        int start = (rozmiar*0.66);
        for (int i = start; i < rozmiar-1; ++i) {
            j = rand()%(rozmiar-start+1)+start-1;; //random miejsce
            swap(tablica[i],tablica[j]);
        }
    }
    else if (t == 2) {
        for (int i = 0; i < rozmiar; ++i) {
            tablica[i] = rand();
        }
        quickrev.quickSort(tablica,0,rozmiar,1,0);

        srand(time(0));
        int j;
        int start = (rozmiar*0.33);
        for (int i = start; i < rozmiar-1; ++i) {
            j = rand()%(rozmiar-start+1)+start-1;; //random miejsce
            swap(tablica[i],tablica[j]);
        }
    }
    else if (t == 3){
        for (int i = 0; i < rozmiar; ++i) {
            tablica[i] = rand();
        }
        quickrev.quickSort(tablica,0,rozmiar,1,1);
    }
    else if (t == 4){
        for (int i = 0; i < rozmiar; ++i) {
            tablica[i] = rand();
        }
        quickrev.quickSort(tablica,0,rozmiar,1,0);
    }
    else {
        for (int i = 0; i < rozmiar; ++i) {
            tablica[i] = rand();
        }
    }
}

void initTab::pushFloat(float *tablica, int rozmiar, int t) {
    if (t == 1) {
        for (int i = 0; i < rozmiar; ++i) {
            tablica[i] = static_cast<float>(rand()) / RAND_MAX;
        }
        quickrev.quickSort(tablica,0,rozmiar,1,0);

        srand(time(0));
        int j;
        int start = (rozmiar*0.66);
        for (int i = start; i < rozmiar-1; ++i) {
            j = rand()%(rozmiar-start+1)+start-1;; //random miejsce
            swap(tablica[i],tablica[j]);
        }
    }
    else if (t == 2) {
        for (int i = 0; i < rozmiar; ++i) {
            tablica[i] = static_cast<float>(rand()) / RAND_MAX;
        }
        quickrev.quickSort(tablica,0,rozmiar,1,0);

        srand(time(0));
        int j;
        int start = (rozmiar*0.33);
        for (int i = start; i < rozmiar-1; ++i) {
            j = rand()%(rozmiar-start+1)+start-1;; //random miejsce
            swap(tablica[i],tablica[j]);
        }
    }
    else if (t == 3){
        for (int i = 0; i < rozmiar; ++i) {
            tablica[i] = static_cast<float>(rand()) / RAND_MAX;
        }
        quickrev.quickSort(tablica,0,rozmiar,1,1);
    }
    else if (t == 4){
        for (int i = 0; i < rozmiar; ++i) {
            tablica[i] = static_cast<float>(rand()) / RAND_MAX;
        }
        quickrev.quickSort(tablica,0,rozmiar,1,0);
    }
    else {
        for (int i = 0; i < rozmiar; ++i) {
            tablica[i] = static_cast<float>(rand()) / RAND_MAX;
        }
    }
}

template <typename T>
void initTab::wyswietlTab(T *tablica, int rozmiar) {
    for (int i = 0; i < rozmiar; ++i) {
        cout << tablica[i] << " ";
    }
    cout << std::endl;
}
template void initTab::wyswietlTab<int>(int tablica[], int rozmiar);
template void initTab::wyswietlTab<float>(float tablica[], int rozmiar);


template <typename T>
void initTab::wyczyscTab(T *tablica, int rozmiar) {
    for (int i = 0; i < rozmiar; ++i) {
        tablica[i] = 0;
    }
}
template void initTab::wyczyscTab<int>(int tablica[], int rozmiar);
template void initTab::wyczyscTab<float>(float tablica[], int rozmiar);

template <typename T>
void initTab::copyArray(T* source, T* destination, int size) {
    for (int i = 0; i < size; ++i) {
        destination[i] = source[i];
    }
}
template void initTab::copyArray<int>(int tablica1[],int tablica2[], int size);
template void initTab::copyArray<float>(float tablica1[],float tablica2[],int size);

template <typename T>
void initTab::openFile(string nazwaPliku, vector<T>& tablica) {
    ifstream plik(nazwaPliku); // Tworzymy obiekt pliku

    if (!plik.is_open()) { // Sprawdzamy, czy plik został otwarty poprawnie
        cerr << "Blad otwierania pliku." << endl;
        return;
    }

    int rozmiar; // Zmienna przechowująca rozmiar tablicy

    // Odczytujemy rozmiar tablicy z pierwszej linii
    if (!(plik >> rozmiar)) {
        cerr << "Nie mozna odczytac rozmiaru tablicy z pliku." << endl;
        return;
    }

    // Zaalokuj pamięć dla tablicy dynamicznej
    tablica.resize(rozmiar);

    // Odczytujemy i zapisujemy liczby do tablicy
    for (int i = 0; i < rozmiar; ++i) {
        if (!(plik >> tablica[i])) {
            cerr << "Nie mozna odczytac danych z pliku." << endl;
            return;
        }
    }

    plik.close(); // Zamykamy plik
}
template void initTab::openFile<int>(string nazwaPliku, vector<int> &tablica);
template void initTab::openFile<float>(string nazwaPliku, vector<float> &tablica);