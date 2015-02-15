// Version 2.0

#ifndef _ANALIZATOR_H_
#define _ANALIZATOR_H_

#include "symbolTable.h"

#include <stack>

// AnalysisData przechowuje dane potrzebne w trakcie analizy drzewa sk≥adniowego
struct AnalysisData{
	AnalysisData(): numerBloku(0),liczbaBledow( 0){}

    // Tablica zmiennych lokalnych
    TablicaZmiennych* tablicaZmiennychLokalnych;

    // Tablica zmiennych globalnych
    TablicaZmiennych* tablicaZmiennychGlobalnych;

    // Stos widocznosci
    // Przechowuje w ktorych zasiegacj aktualnie jestesmy

    /* PRZYKLAD:

    // zasieg globalny ma wartosc 0          Stos: 0 <- wierzcholek

    { // poczatek zasiegu 1                  Stos : 0 1 <- wierzcholek

    } // koniec zasiegu 1                    Stos: 0 <- wierzcholek
    { // poczatek zasiegu 2                  Stos: 0 2 <- wierzcholek
        { // poczatek zasiegu 3              Stos: 0 2 3 <- wierzcholek

        } // koniec zasiegu 3                Stos: 0 2 <- wierzcholek
    } // koniec zasiegu 2                    Stos: 0 <- wierzcholek

    */
    // Stos widocznosci
    std::stack<int>* stosWidocznosci;

    // Numer bloku ( zasieg widocznosci)
    int numerBloku;

	// Wskaünik do tablicy funkcji
	TablicaFunkcji* tablicaFunkcji;

	// Przechowuje liczbe b≥edow semantycznych napotkanych w drzewie
    // Jezeli po analizie ta zmienna ma wartosc 0 oznacza, ze analiza odbyla sie bezblednie
    // i mozna wykonywac drzewo
	int liczbaBledow;
};

// Do≥aczam plik ze struktura ktora przechowuje dane potrzebne w trakcie wykonywania drzewa
#include "runTimeData.h"

#endif
