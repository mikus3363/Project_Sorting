//
// Created by mikus on 04.04.2024.
//

#include "Menu.h"
#include "initTab.h"
#include "Insertion.h"
#include "Quick.h"
#include "Shell.h"
#include "Heap.h"
#include <iostream>
#include <vector>
using namespace std;

void Menu::wyswietlMenu() {
    inicjujMenu();
}

initTab initab;
Insertion insertion;
Quick quick;
Shell shell;
Heap heap;

//zdefiniowanie tablic dynamicznych potrzebnych do badania (int i float)
int* tablicaIntow1 = new int[10000]();
int* tablicaIntow2 = new int[20000]();
int* tablicaIntow3 = new int[40000]();
int* tablicaIntow4 = new int[80000]();
int* tablicaIntow5 = new int[160000]();
int* tablicaIntow6 = new int[320000]();
int* tablicaIntow7 = new int[640000]();

float* tablicaFloatow1 = new float[10000]();
float* tablicaFloatow2 = new float[20000]();
float* tablicaFloatow3 = new float[40000]();
float* tablicaFloatow4 = new float[80000]();
float* tablicaFloatow5 = new float[160000]();
float* tablicaFloatow6 = new float[320000]();
float* tablicaFloatow7 = new float[640000]();

vector<int> vectorinputInt;
vector<float> vectorinputFloat;

int sizeInt;
int sizeFloat;

int* tabinputInt;
float* tabinputFloat;
int* tmpinputInt = new int[sizeInt];
float* tmpinputFloat = new float[sizeFloat];

//zdefiniowanie sumy która będzie potrzebna do średniego czasu wykonania sortowań
int duration1 = 0;
int duration2 = 0;
int duration3 = 0;
int duration4 = 0;
int duration5 = 0;
int duration6 = 0;
int duration7 = 0;
int durationInput = 0;

//zdefiniowanie ilości wykonania sortowań podczas testu
int index = 0;


int p ; //określa wybrany piwot podczas szybkiego sortowania
int t ; //określa sposób mieszania tablicy

void Menu::inicjujMenu() { //inicjowanie menu głównego które zobaczymy jako pierwsze przy odpaleniu programu
    cout << "Autor : Mikolaj Lipinski \n" << endl;
    int x = 0, kon = 1;
    do
    {
        cout << "MENU Glowne" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1.Inicjalizuj tablice int" << endl;
        cout << "2.Inicjalizuj tablice float" << endl;
        cout << "3.Wyjdz z programu" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> x;
        switch (x)
        {
            case 1:
                cout << endl;
                inicjujMenuInt(); //przejście do Menu odpowiedzialnego za wykonywanie operacji na zmiennych typu int
                enter();
                break;
            case 2:
                cout << endl;
                inicjujMenuFloat(); //przejście do Menu odpowiedzialnego za wykonywanie operacji na zmiennych typu float
                enter();
                break;
            case 3:
                cout << endl;
                kon = 0;
                break;
            default:
                cout << endl;
                cout << "Podano zla wartosc" << endl << endl;
                enter();
                break;
        }
    } while (kon == 1);
}

void Menu::inicjujMenuInt() { //zainicjowanie Menu odpowiedzialnego za wykonywanie operacji na zmiennych typu int
    int x = 0, kon = 1;
    do
    {
        cout << "MENU (Int)" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1.Uzupelnij wszystkie tablice liczbami losowymi" << endl;
        cout << "2.Uzupelnij wszystkie tablice liczbami losowymi w 66%, reszta posortowana" << endl;
        cout << "3.Uzupelnij wszystkie tablice liczbami losowymi w 33%, reszta posortowana" << endl;
        cout << "4.Uzupelnij wszystkie tablice liczbami malejaco" << endl;
        cout << "5.Uzupelnij wszystkie tablice liczbami rosnaco" << endl;
        cout << "6.Wczytaj tablice z pliku" << endl;
        cout << "7.Przejdz do sortowania tablic int" << endl;
        cout << "8.Wyczysc tablice" << endl;
        cout << "9.Wroc" << endl;
        cout << "10.Wyjdz z programu" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> x;
        switch (x)
        {
            case 1:
                cout << endl;
                vectorinputInt.clear();
                t = 0;
                pushIntTab();
                enter();
                break;
            case 2:
                cout << endl;
                vectorinputInt.clear();
                t = 2;
                pushIntTab();
                enter();
                break;
            case 3:
                cout << endl;
                vectorinputInt.clear();
                t = 1;
                pushIntTab();
                enter();
                break;
            case 4:
                cout << endl;
                vectorinputInt.clear();
                t = 3;
                pushIntTab();
                enter();
                break;
            case 5:
                cout << endl;
                vectorinputInt.clear();
                t = 4;
                pushIntTab();
                enter();
                break;
            case 6:
                cout << endl;
                initab.openFile("C:\\Users\\mikus\\OneDrive\\Pulpit\\Projekty\\ProjektAIZO\\daneInt.txt",vectorinputInt);
                tabinputInt = vectorinputInt.data();
                sizeInt = vectorinputInt.size();
                initab.copyArray(tabinputInt,tmpinputInt,sizeInt);
                initab.wyswietlTab(tabinputInt,sizeInt);
                break;
            case 7:
                kon = 0;
                inicjujSortInt(); //przejście do funkcji odpowiedzialnej za sortowanie liczb w tablicach typu int
                break;
            case 8:
                kon = 0;
                initab.wyczyscTab(tablicaIntow1,10000);
                initab.wyczyscTab(tablicaIntow2,20000);
                initab.wyczyscTab(tablicaIntow3,40000);
                initab.wyczyscTab(tablicaIntow4,80000);
                initab.wyczyscTab(tablicaIntow5,160000);
                initab.wyczyscTab(tablicaIntow6,320000);
                initab.wyczyscTab(tablicaIntow7,640000);
                break;
            case 9:
                cout << endl;
                inicjujMenu();
                break;
            case 10:
                cout << endl;
                kon = 0;
                delete [] tablicaIntow1;
                delete [] tablicaIntow2;
                delete [] tablicaIntow3;
                delete [] tablicaIntow4;
                delete [] tablicaIntow5;
                delete [] tablicaIntow6;
                delete [] tablicaIntow7;
                break;
            default:
                cout << endl;
                cout << "Podano zla wartosc" << endl << endl;
                enter();
                break;
        }
    } while (kon == 1);
}

void Menu::inicjujMenuFloat() { //zainicjowanie Menu odpowiedzialnego za wykonywanie operacji na zmiennych typu float
    int x = 0, kon = 1;
    do
    {
        cout << "MENU (Float)" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1.Uzupelnij wszystkie tablice liczbami losowymi" << endl;
        cout << "2.Uzupelnij wszystkie tablice liczbami losowymi w 66%, reszta posortowana" << endl;
        cout << "3.Uzupelnij wszystkie tablice liczbami losowymi w 33%, reszta posortowana" << endl;
        cout << "4.Uzupelnij wszystkie tablice liczbami malejaco" << endl;
        cout << "5.Uzupelnij wszystkie tablice liczbami rosnaco" << endl;
        cout << "6.Wczytaj tablice z pliku" << endl;
        cout << "7.Przejdz do sortowania tablic float" << endl;
        cout << "8.Wyczysc tablice" << endl;
        cout << "9.Wroc" << endl;
        cout << "10.Wyjdz z programu" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> x;
        switch (x)
        {
            case 1:
                cout << endl;
                vectorinputFloat.clear();
                t = 0;
                pushFloatTab();
                enter();
                break;
            case 2:
                cout << endl;
                vectorinputFloat.clear();
                t = 2;
                pushFloatTab();
                enter();
                break;
            case 3:
                cout << endl;
                vectorinputFloat.clear();
                t = 1;
                pushFloatTab();
                enter();
                break;
            case 4:
                cout << endl;
                vectorinputFloat.clear();
                t = 3;
                pushFloatTab();
                enter();
                break;
            case 5:
                cout << endl;
                vectorinputFloat.clear();
                t = 4;
                pushFloatTab();
                enter();
                break;
            case 6:
                cout << endl;
                initab.openFile("C:\\Users\\mikus\\OneDrive\\Pulpit\\Projekty\\ProjektAIZO\\daneFloat.txt",vectorinputFloat);
                tabinputFloat = vectorinputFloat.data();
                sizeFloat = vectorinputFloat.size();
                initab.copyArray(tabinputFloat,tmpinputFloat,sizeFloat);
                initab.wyswietlTab(tabinputFloat,sizeFloat);
                break;
            case 7:
                kon = 0;
                inicjujSortFloat(); //przejście do funkcji odpowiedzialnej za sortowanie liczb w tablicach typu float
                break;
            case 8:
                kon = 0;
                initab.wyczyscTab(tablicaFloatow1,10000);
                initab.wyczyscTab(tablicaFloatow2,20000);
                initab.wyczyscTab(tablicaFloatow3,40000);
                initab.wyczyscTab(tablicaFloatow4,80000);
                initab.wyczyscTab(tablicaFloatow5,160000);
                initab.wyczyscTab(tablicaFloatow6,320000);
                initab.wyczyscTab(tablicaFloatow7,640000);
                break;
            case 9:
                cout << endl;
                inicjujMenu();
                break;
            case 10:
                cout << endl;
                kon = 0;
                delete [] tablicaFloatow1;
                delete [] tablicaFloatow2;
                delete [] tablicaFloatow3;
                delete [] tablicaFloatow4;
                delete [] tablicaFloatow5;
                delete [] tablicaFloatow6;
                delete [] tablicaFloatow7;
                break;
            default:
                cout << endl;
                cout << "Podano zla wartosc" << endl << endl;
                enter();
                break;
        }
    } while (kon == 1);
}

void Menu::inicjujSortInt() { //funkcja odpowiedzialna za sortowanie liczb w tablicach typu int
    int x = 0, kon = 1;
    do
    {
        cout << "Sortowanie (Int)" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1.Przez wstawianie" << endl;
        cout << "2.Przez kopcowanie" << endl;
        cout << "3.Shella" << endl;
        cout << "4.Szybkie" << endl;
        cout << "5.Wyswietl tablice z pliku" << endl;
        cout << "6.Wroc" << endl;
        cout << "7.Wyjdz z programu" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> x;
        switch (x)
        {
            case 1:
                cout << endl;
                if(vectorinputInt.empty()){
                    for(int i=0;i<10;i++){
                        duration1 += insertion.insertionSort(tablicaIntow1,10000);
                        duration2 += insertion.insertionSort(tablicaIntow2,20000);
                        duration3 += insertion.insertionSort(tablicaIntow3,40000);
                        duration4 += insertion.insertionSort(tablicaIntow4,80000);
                        duration5 += insertion.insertionSort(tablicaIntow5,160000);
                        duration6 += insertion.insertionSort(tablicaIntow6,320000);
                        duration7 += insertion.insertionSort(tablicaIntow7,640000);
                        pushIntTab();
                        incIndex();
                        cout<<endl;
                    }
                    avgprint();
                    clear();
                    enter();
                    break;
                }
                durationInput += insertion.insertionSort(tmpinputInt,sizeInt);
                incIndex();
                cout<<endl;
                cout<<"Sredni czas dla wczytanej tablicy: "<<durationInput/index<<" ms"<<endl;
                clear();
                enter();
                break;
            case 2:
                cout << endl;
                if(vectorinputInt.empty()) {
                    for (int i = 0; i < 100; i++) {
                        duration1 += heap.heapSort(tablicaIntow1, 10000);
                        duration2 += heap.heapSort(tablicaIntow2, 20000);
                        duration3 += heap.heapSort(tablicaIntow3, 40000);
                        duration4 += heap.heapSort(tablicaIntow4, 80000);
                        duration5 += heap.heapSort(tablicaIntow5, 160000);
                        duration6 += heap.heapSort(tablicaIntow6, 320000);
                        duration7 += heap.heapSort(tablicaIntow7, 640000);
                        pushIntTab();
                        incIndex();
                        cout << endl;
                    }
                    avgprint();
                    clear();
                    enter();
                    break;
                }
                durationInput += heap.heapSort(tmpinputInt, sizeInt);
                incIndex();
                cout << endl;
                cout<<"Sredni czas dla wczytanej tablicy: "<<durationInput/index<<" ms"<<endl;
                clear();
                enter();
                break;
            case 3:
                cout << endl;
                wyborShellInt(); //wybranie wariantu sortowania Shella
                enter();
                break;
            case 4:
                cout << endl;
                p = wyborPiwot();
                if(vectorinputInt.empty()) {
                    for (int i = 0; i < 100; i++) {
                        duration1 += quick.quickSorting(tablicaIntow1, 0, 9999, p);
                        duration2 += quick.quickSorting(tablicaIntow2, 0, 19999, p);
                        duration3 += quick.quickSorting(tablicaIntow3, 0, 39999, p);
                        duration4 += quick.quickSorting(tablicaIntow4, 0, 79999, p);
                        duration5 += quick.quickSorting(tablicaIntow5, 0, 159999, p);
                        duration6 += quick.quickSorting(tablicaIntow6, 0, 319999, p);
                        duration7 += quick.quickSorting(tablicaIntow7, 0, 639999, p);
                        pushIntTab();
                        incIndex();
                        cout << endl;
                    }
                    avgprint();
                    clear();
                    enter();
                    break;
                }
                durationInput += quick.quickSorting(tmpinputInt, 0, sizeInt-1, p);
                incIndex();
                cout << endl;
                cout<<"Sredni czas dla wczytanej tablicy: "<<durationInput/index<<" ms"<<endl;
                clear();
                enter();
                break;
            case 5:
                cout << endl;
                if(vectorinputInt.empty()) {
                    cout<<"Tablica jest pusta"<<endl;
                    break;
                }
                initab.wyswietlTab(tmpinputInt,sizeInt);
                break;
            case 6:
                kon = 0;
                inicjujMenuInt();
                break;
            case 7:
                cout << endl;
                kon = 0;
                delete [] tablicaIntow1;
                delete [] tablicaIntow2;
                delete [] tablicaIntow3;
                delete [] tablicaIntow4;
                delete [] tablicaIntow5;
                delete [] tablicaIntow6;
                delete [] tablicaIntow7;
                break;
            default:
                cout << endl;
                cout << "Podano zla wartosc" << endl << endl;
                enter();
                break;
        }
    } while (kon == 1);
}

void Menu::inicjujSortFloat() { //funkcja odpowiedzialna za sortowanie liczb w tablicach typu float
    int x = 0, kon = 1;
    do
    {
        cout << "Sortowanie (Float)" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1.Przez wstawianie" << endl;
        cout << "2.Przez kopcowanie" << endl;
        cout << "3.Shella" << endl;
        cout << "4.Szybkie" << endl;
        cout << "5.Wyswietl tablice z pliku" << endl;
        cout << "6.Wroc" << endl;
        cout << "7.Wyjdz z programu" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> x;
        switch (x)
        {
            case 1:
                cout << endl;
                if(vectorinputFloat.empty()) {
                    for (int i = 0; i < 10; i++) {
                        duration1 += insertion.insertionSort(tablicaFloatow1, 10000);
                        duration2 += insertion.insertionSort(tablicaFloatow2, 20000);
                        duration3 += insertion.insertionSort(tablicaFloatow3, 40000);
                        duration4 += insertion.insertionSort(tablicaFloatow4, 80000);
                        duration5 += insertion.insertionSort(tablicaFloatow5, 160000);
                        duration6 += insertion.insertionSort(tablicaFloatow6, 320000);
                        duration7 += insertion.insertionSort(tablicaFloatow7, 640000);
                        pushFloatTab();
                        incIndex();
                        cout << endl;
                    }
                    avgprint();
                    clear();
                    enter();
                    break;
                }
                durationInput += insertion.insertionSort(tmpinputFloat,sizeFloat);
                incIndex();
                cout<<endl;
                cout<<"Sredni czas dla wczytanej tablicy: "<<durationInput/index<<" ms"<<endl;
                clear();
                enter();
                break;
            case 2:
                cout << endl;
                if(vectorinputFloat.empty()) {
                    for (int i = 0; i < 100; i++) {
                        duration1 += heap.heapSort(tablicaFloatow1, 10000);
                        duration2 += heap.heapSort(tablicaFloatow2, 20000);
                        duration3 += heap.heapSort(tablicaFloatow3, 40000);
                        duration4 += heap.heapSort(tablicaFloatow4, 80000);
                        duration5 += heap.heapSort(tablicaFloatow5, 160000);
                        duration6 += heap.heapSort(tablicaFloatow6, 320000);
                        duration7 += heap.heapSort(tablicaFloatow7, 640000);
                        pushFloatTab();
                        incIndex();
                        cout << endl;
                    }
                    avgprint();
                    clear();
                    enter();
                    break;
                }
                durationInput += heap.heapSort(tmpinputFloat, sizeFloat);
                incIndex();
                cout << endl;
                cout<<"Sredni czas dla wczytanej tablicy: "<<durationInput/index<<" ms"<<endl;
                clear();
                enter();
                break;
            case 3:
                cout << endl;
                wyborShellFloat();
                enter();
                break;
            case 4:
                cout << endl;
                if(vectorinputFloat.empty()) {
                    p = wyborPiwot();
                    for (int i = 0; i < 100; i++) {
                        duration1 += quick.quickSorting(tablicaFloatow1, 0, 9999, p);
                        duration2 += quick.quickSorting(tablicaFloatow2, 0, 19999, p);
                        duration3 += quick.quickSorting(tablicaFloatow3, 0, 39999, p);
                        duration4 += quick.quickSorting(tablicaFloatow4, 0, 79999, p);
                        duration5 += quick.quickSorting(tablicaFloatow5, 0, 159999, p);
                        duration6 += quick.quickSorting(tablicaFloatow6, 0, 319999, p);
                        duration7 += quick.quickSorting(tablicaFloatow7, 0, 639999, p);
                        pushFloatTab();
                        incIndex();
                        cout << endl;
                    }
                    avgprint();
                    clear();
                    enter();
                    break;
                }
                durationInput += quick.quickSorting(tmpinputFloat, 0, sizeFloat-1, p);
                incIndex();
                cout << endl;
                cout<<"Sredni czas dla wczytanej tablicy: "<<durationInput/index<<" ms"<<endl;
                clear();
                enter();
                break;
            case 5:
                cout << endl;
                if(vectorinputFloat.empty()) {
                    cout<<"Tablica jest pusta"<<endl;
                    break;
                }
                initab.wyswietlTab(tabinputFloat,sizeFloat);
                break;
            case 6:
                kon = 0;
                inicjujMenuFloat();
                break;
            case 7:
                cout << endl;
                kon = 0;
                delete [] tablicaFloatow1;
                delete [] tablicaFloatow2;
                delete [] tablicaFloatow3;
                delete [] tablicaFloatow4;
                delete [] tablicaFloatow5;
                delete [] tablicaFloatow6;
                delete [] tablicaFloatow7;
                break;
            default:
                cout << endl;
                cout << "Podano zla wartosc" << endl << endl;
                enter();
                break;
        }
    } while (kon == 1);
}

int Menu::wyborPiwot() { //funkcja odpowiedzialna za wybór piwota do szybkiego sortowania
    int p;
    cout<<"Wybierz w ktorym miejscu chcesz miec piwot:"<<endl;
    cout<<"1.Lewo"<<endl;
    cout<<"2.Prawo"<<endl;
    cout<<"3.Srodek"<<endl;
    cout<<"4.Losowy"<<endl;
    cin>>p;

    return p;
}

void Menu::wyborShellInt() { //funkcja wyboru wariantu algorytmu sortowania Shella dla zmiennych typu int
    int x;
    cout<<"Wybierz ilosc odstepow dla algorytmu Shella:"<<endl;
    cout<<"1.Domyslny algorytm Shella (|_p/2_|)"<<endl;
    cout<<"2.Algorytm D.Knutha ((3^k-1)/2 <= |`n/3`|)"<<endl;
    cin>>x;
    switch (x) {
        case 1:
            cout << endl;
            if(vectorinputInt.empty()) {
                for (int i = 0; i < 100; i++) {
                    duration1 += shell.shellSortDef(tablicaIntow1, 10000);
                    duration2 += shell.shellSortDef(tablicaIntow2, 20000);
                    duration3 += shell.shellSortDef(tablicaIntow3, 40000);
                    duration4 += shell.shellSortDef(tablicaIntow4, 80000);
                    duration5 += shell.shellSortDef(tablicaIntow5, 160000);
                    duration6 += shell.shellSortDef(tablicaIntow6, 320000);
                    duration7 += shell.shellSortDef(tablicaIntow7, 640000);
                    pushIntTab();
                    incIndex();
                    cout << endl;
                }
                avgprint();
                clear();
                break;
            }
            durationInput += shell.shellSortDef(tmpinputInt, sizeInt);
            incIndex();
            cout << endl;
            cout<<"Sredni czas dla wczytanej tablicy: "<<durationInput/index<<" ms"<<endl;
            clear();
            enter();
            break;
        default:
            cout << endl;
            if(vectorinputInt.empty()) {
                for (int i = 0; i < 100; i++) {
                    duration1 += shell.shellSortKnuth(tablicaIntow1, 10000);
                    duration2 += shell.shellSortKnuth(tablicaIntow2, 20000);
                    duration3 += shell.shellSortKnuth(tablicaIntow3, 40000);
                    duration4 += shell.shellSortKnuth(tablicaIntow4, 80000);
                    duration5 += shell.shellSortKnuth(tablicaIntow5, 160000);
                    duration6 += shell.shellSortKnuth(tablicaIntow6, 320000);
                    duration7 += shell.shellSortKnuth(tablicaIntow7, 640000);
                    pushIntTab();
                    incIndex();
                    cout << endl;
                }
                avgprint();
                clear();
                break;
            }
            durationInput += shell.shellSortKnuth(tmpinputInt, sizeInt);
            incIndex();
            cout << endl;
            cout<<"Sredni czas dla wczytanej tablicy: "<<durationInput/index<<" ms"<<endl;
            clear();
            enter();
            break;
    }
}

void Menu::wyborShellFloat() { //funkcja wyboru wariantu algorytmu sortowania Shella dla zmiennych typu float
    int x;
    cout<<"Wybierz ilosc odstepow dla algorytmu Shella:"<<endl;
    cout<<"1.Domyslny algorytm Shella (|_p/2_|)"<<endl;
    cout<<"2.Algorytm D.Knutha ((3^k-1)/2 <= |`n/3`|)"<<endl;
    cin>>x;
    switch (x) {
        case 1:
            cout << endl;
            if(vectorinputInt.empty()) {
                for (int i = 0; i < 100; i++) {
                    duration1 += shell.shellSortDef(tablicaFloatow1, 10000);
                    duration2 += shell.shellSortDef(tablicaFloatow2, 20000);
                    duration3 += shell.shellSortDef(tablicaFloatow3, 40000);
                    duration4 += shell.shellSortDef(tablicaFloatow4, 80000);
                    duration5 += shell.shellSortDef(tablicaFloatow5, 160000);
                    duration6 += shell.shellSortDef(tablicaFloatow6, 320000);
                    duration7 += shell.shellSortDef(tablicaFloatow7, 640000);
                    pushFloatTab();
                    incIndex();
                    cout << endl;
                }
                avgprint();
                clear();
                break;
            }
            durationInput += shell.shellSortDef(tmpinputFloat, sizeFloat);
            incIndex();
            cout << endl;
            cout<<"Sredni czas dla wczytanej tablicy: "<<durationInput/index<<" ms"<<endl;
            clear();
            enter();
            break;
        default:
            cout << endl;
            if(vectorinputInt.empty()) {
                for (int i = 0; i < 100; i++) {
                    duration1 += shell.shellSortKnuth(tablicaFloatow1, 10000);
                    duration2 += shell.shellSortKnuth(tablicaFloatow2, 20000);
                    duration3 += shell.shellSortKnuth(tablicaFloatow3, 40000);
                    duration4 += shell.shellSortKnuth(tablicaFloatow4, 80000);
                    duration5 += shell.shellSortKnuth(tablicaFloatow5, 160000);
                    duration6 += shell.shellSortKnuth(tablicaFloatow6, 320000);
                    duration7 += shell.shellSortKnuth(tablicaFloatow7, 640000);
                    pushFloatTab();
                    incIndex();
                    cout << endl;
                }
                avgprint();
                clear();
                break;
            }
            durationInput += shell.shellSortKnuth(tmpinputFloat, sizeFloat);
            incIndex();
            cout << endl;
            cout<<"Sredni czas dla wczytanej tablicy: "<<durationInput/index<<" ms"<<endl;
            clear();
            enter();
            break;
    }
}

void Menu::pushIntTab() { //zmienne int są wkładane do tablic w zależności od wariantu jaki wybierzemy (t)
    initab.pushInt(tablicaIntow1,10000,t);
    initab.pushInt(tablicaIntow2,20000,t);
    initab.pushInt(tablicaIntow3,40000,t);
    initab.pushInt(tablicaIntow4,80000,t);
    initab.pushInt(tablicaIntow5,160000,t);
    initab.pushInt(tablicaIntow6,320000,t);
    initab.pushInt(tablicaIntow7,640000,t);
}

void Menu::pushFloatTab() { //zmienne float są wkładane do tablic w zależności od wariantu jaki wybierzemy (t)
    initab.pushFloat(tablicaFloatow1,10000,t);
    initab.pushFloat(tablicaFloatow2,20000,t);
    initab.pushFloat(tablicaFloatow3,40000,t);
    initab.pushFloat(tablicaFloatow4,80000,t);
    initab.pushFloat(tablicaFloatow5,160000,t);
    initab.pushFloat(tablicaFloatow6,320000,t);
    initab.pushFloat(tablicaFloatow7,640000,t);
}

void Menu::clear() { //reset wyniku testu
    index = 0;
    duration1 = 0;
    duration2 = 0;
    duration3 = 0;
    duration4 = 0;
    duration5 = 0;
    duration6 = 0;
    duration7 = 0;
}

void Menu::avgprint() { //wyświetlenie wyników testu
    cout<<"Sredni czas dla 10000 elementow: "<<duration1/index<<" ms"<<endl;
    cout<<"Sredni czas dla 20000 elementow: "<<duration2/index<<" ms"<<endl;
    cout<<"Sredni czas dla 40000 elementow: "<<duration3/index<<" ms"<<endl;
    cout<<"Sredni czas dla 80000 elementow: "<<duration4/index<<" ms"<<endl;
    cout<<"Sredni czas dla 160000 elementow: "<<duration5/index<<" ms"<<endl;
    cout<<"Sredni czas dla 320000 elementow: "<<duration6/index<<" ms"<<endl;
    cout<<"Sredni czas dla 640000 elementow: "<<duration7/index<<" ms"<<endl;
}

void Menu::incIndex() {
    index += 1;
}

void Menu::enter() {
    cout << "Nacisnij przycisk ENTER aby wrocic do Menu" << endl;
    getchar();
    getchar();
}