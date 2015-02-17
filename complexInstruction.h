// Version 1.0

#ifndef _INSTRUKCJA_ZLOZONA_H_
#define _INSTRUKCJA_ZLOZONA_H_

#include "instrunctionList.h"

// Reprezentuje instrukcje zlo¿ona. Instruction zlo¿¿ona jest to instruction zawarta w klamrach '{' i '}'
class ComplexInstrukction : public Instruction {
public:
    // Konstruktor przyjmuje liste instrukcji oraz numer linii w ktorej zaczynaja sie
    // instrukcje
    ComplexInstrukction(InstructionList* __instructions, int __lineNumber)
        : Instruction(Void, __lineNumber)
        , _instructionList(__instructions)
    {
    }

    // Wykonuje instrukcje zlozona
    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        _instructionList->execute(__runTimeData);
        return 0x00;
    }

    // Przechodzi przez drzewo skladniowe w glab
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // ktora przechowuje informacje o tablicach symboli.
    // Dodaje zadeklarowana zmienna do tablicy symboli
    virtual void analise(AnalysisData& __analysisData)
    {
        __analysisData.visibilityStack->push(++__analysisData.blockNumber);
        /*
            Wchodzac do zasiegu inkrementujemy value __analysisData.blockNumber,
            wychodzac dekrementujemy

            {   // ++__analysisData.blockNumber

            }   // --__analysisData.blockNumber

            */

        /*
            // scope globalny ma value 0          Stos: 0 <- wierzcholek

            { // poczatek zasiegu 1                  Stos : 0 1 <- wierzcholek

            } // koniec zasiegu 1                    Stos: 0 <- wierzcholek
            { // poczatek zasiegu 2                  Stos: 0 2 <- wierzcholek
                { // poczatek zasiegu 3              Stos: 0 2 3 <- wierzcholek

                } // koniec zasiegu 3                Stos: 0 2 <- wierzcholek
            } // koniec zasiegu 2                    Stos: 0 <- wierzcholek

            */

        _instructionList->analise(__analysisData);

        __analysisData.visibilityStack->pop();
    }

private:
    int _numerBloku;

    // List instrukcji
    InstructionList* _instructionList;
};

#endif
