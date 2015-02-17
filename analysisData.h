// Version 2.0

#ifndef _ANALIZATOR_H_
#define _ANALIZATOR_H_

#include "symbolTable.h"

#include <stack>

// AnalysisData przechowuje dane potrzebne w trakcie analizy drzewa skladniowego
struct AnalysisData {
    AnalysisData()
        : blockNumber(0)
        , errorCounter(0)
    {
    }

    // Tablica zmiennych lokalnych
    VariableTable* localVariableTable;

    // Tablica zmiennych globalnych
    VariableTable* globalVariableTable;

    // Stos widocznosci
    // Przechowuje w ktorych zasiegacj aktualnie jestesmy

    /* PRZYKLAD:

    // scope globalny ma value 0          Stos: 0 <- wierzcholek

    { // poczatek zasiegu 1                  Stos : 0 1 <- wierzcholek

    } // koniec zasiegu 1                    Stos: 0 <- wierzcholek
    { // poczatek zasiegu 2                  Stos: 0 2 <- wierzcholek
        { // poczatek zasiegu 3              Stos: 0 2 3 <- wierzcholek

        } // koniec zasiegu 3                Stos: 0 2 <- wierzcholek
    } // koniec zasiegu 2                    Stos: 0 <- wierzcholek

    */
    // Stos widocznosci
    std::stack<int>* visibilityStack;

    // Numer bloku ( scope widocznosci)
    int blockNumber;

    // Wskaznik do tablicy funkcji
    FunctionTable* functionTable;

    // Przechowuje liczbe bledow semantycznych napotkanych w drzewie
    // Jezeli po analizie ta zmienna ma value 0 oznacza, ze analiza odbyla sie bezblednie
    // i mozna wykonywac drzewo
    int errorCounter;
};

// Dolaczam plik ze struktura ktora przechowuje dane potrzebne w trakcie wykonywania drzewa
#include "runTimeData.h"

#endif
