// Version 1.0

#ifndef _PROGRAM_H_
#define _PROGRAM_H_

#include "functionList.h"

namespace NSInterpreter {
const std::string funkcjaGlowna = "main";
};

// Reprezentuje program
class Program {
public:
    // Konstruktor przyjmuje listê deklaracji oraz listê funkcji
    Program(DeclarationList* __listaDeklaracji, FunctionList* __listaFunkcji)
        : _analizowany(false)
        , _funkcjaGlowna(NSInterpreter::funkcjaGlowna)
        , _listaDeklaracji(__listaDeklaracji)
        , _listaFunkcji(__listaFunkcji)
    {
    }

    // Konstruktor przyjmuje listê funkcji
    Program(FunctionList* __listaFunkcji)
        : _analizowany(false)
        , _funkcjaGlowna(NSInterpreter::funkcjaGlowna)
        , _listaDeklaracji(0x00)
        , _listaFunkcji(__listaFunkcji)
    {
    }

    // Analizuje program
    void analise();

    // Analizuje i wykonuje program
    const Value* execute();

    // Dodaje funkcje biblioteczne do tablicy symboli
    void dodajFunkcjeBiblioteczne();

protected:
    // czy analizowalismy juz program
    bool _analizowany;

    // Nazwa funkcji g³ównej.
    std::string _funkcjaGlowna;

    // Tablica zmiennych globalnych
    VariableTable _tablicaZmiennychGlobalnych;

    // Tablica funkcji
    FunctionTable _tablicaFunkcji;

    // List deklaracji zmiennych globalnych
    DeclarationList* _listaDeklaracji;

    // List funkcji
    FunctionList* _listaFunkcji;
};

#endif
