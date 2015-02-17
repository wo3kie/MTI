// Version 1.0

#ifndef _RUN_TIME_DATA_H_
#define _RUN_TIME_DATA_H_

#include "symbolTable.h"

// 'ActivationRecord' - definicja w pliku functionDefinition.h
struct ActivationRecord;

// Przechowuje dane potrzebne w czasie wykonywania drzewa
struct RunTimeData {
    // mozna wrzucic parameters wywolania dla funkcji 'main'

    // Tablica zmiennych lokalnych
    VariableTable* localVariableTable;

    // Tablica zmiennych globalnych
    VariableTable* globalVariableTable;

    // Wskazsnik do globalnej tablicy funkcji
    FunctionTable* functionTable;

    // Rekord aktywacji jest interfejsem funkcji. Klasa 'FunctionCall' wpisuje wartosci
    // parametrow do rekordu aktywacji, funkcja sie wykonuje i w rekordzie aktywacji
    // czeka zwracana przez funkcje value
    ActivationRecord* activationRecord;
};

#endif
