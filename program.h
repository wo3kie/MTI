// Version 1.0

#ifndef _PROGRAM_H_
#define _PROGRAM_H_

#include "functionList.h"

namespace NSInterpreter{
    const std::string funkcjaGlowna= "main";
};

// Reprezentuje program
class Program{
    public:
        // Konstruktor przyjmuje listê deklaracji oraz listê funkcji
        Program( ListaDeklaracji* __listaDeklaracji, ListaFunkcji* __listaFunkcji)
        :_analizowany( false),
        _funkcjaGlowna( NSInterpreter::funkcjaGlowna),
        _listaDeklaracji( __listaDeklaracji),
        _listaFunkcji( __listaFunkcji)
        {
        }

        // Konstruktor przyjmuje listê funkcji
        Program( ListaFunkcji* __listaFunkcji)
        :_analizowany( false),
        _funkcjaGlowna( NSInterpreter::funkcjaGlowna),
        _listaDeklaracji( 0x00),
        _listaFunkcji( __listaFunkcji)
        {
        }

        // Analizuje program
        void analise();

        // Analizuje i wykonuje program
        const Wartosc* execute();

        // Dodaje funkcje biblioteczne do tablicy symboli
        void dodajFunkcjeBiblioteczne();

    protected:
        // czy analizowalismy juz program
        bool _analizowany;

        // Nazwa funkcji g³ównej.
        std::string _funkcjaGlowna;

        // Tablica zmiennych globalnych
        TablicaZmiennych _tablicaZmiennychGlobalnych;

        // Tablica funkcji
        TablicaFunkcji _tablicaFunkcji;

        // Lista deklaracji zmiennych globalnych
        ListaDeklaracji* _listaDeklaracji;

        // Lista funkcji
        ListaFunkcji* _listaFunkcji;
};

#endif
