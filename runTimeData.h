// Version 1.0

#ifndef _RUN_TIME_DATA_H_
#define _RUN_TIME_DATA_H_

#include "tablicaSymboli.h"

// 'RekordAktywacji' - definicja w pliku definicjaFunkcji.h
struct RekordAktywacji;


// Przechowuje dane potrzebne w czasie wykonywania drzewa
struct RunTimeData{
    // mozna wrzucic parametry wywolania dla funkcji 'main'

    // Tablica zmiennych lokalnych
    TablicaZmiennych* tablicaZmiennychLokalnych;

    // Tablica zmiennych globalnych
    TablicaZmiennych* tablicaZmiennychGlobalnych;

    // WskaŸœnik do globalnej tablicy funkcji
    TablicaFunkcji* tablicaFunkcji;

    // Rekord aktywacji jest interfejsem funkcji. Klasa 'WywolanieFunkcji' wpisuje wartosci
    // parametrow do rekordu aktywacji, funkcja sie wykonuje i w rekordzie aktywacji
    // czeka zwracana przez funkcje wartosc
    RekordAktywacji* rekordAktywacji;
};


#endif
