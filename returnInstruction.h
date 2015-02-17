// Version 1.0

#ifndef _INSTRUKCJA_SKOKU_RETURN_H_
#define _INSTRUKCJA_SKOKU_RETURN_H_

#include "expression.h"

// Instruction ta nie konczy dzialania funkcji. Okresla jaka wartosc zwroci funkcja.
// Je¿eli w funkcji u¿yjemy instrukcji return wielokrotnie, funkcja zwroci wartosc
// wyliczona w ostatniej instrukcji return.
//   Przyklad:
//      double funkcja(){
//         return 1;
//         return 2;
//     }
//
//     Funkcja zwroci wartosc 2
class ReturnInstruction : public Instruction {
public:
    // Konstruktor przyjmuje wyra¿enie ktorego wartosc zwroci,
    // oraz numer linii w ktorej wystapila instruction
    ReturnInstruction(Expression* __expression, int __lineNumber)
        // Zmienna 'return' jest pierwszym wpisem w lokalnej tablicy zmiennych
        // i przechowuje zwracana wartosc
        : Instruction(Void, __lineNumber),
          _expression(__expression)
    {
    }

    // Kopiuje do pierwszej pozycji lokalnej tablicy symboli wartosc wyrazenia
    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        // '::copy' obiekt klasy 'AssignmentOperator' - plik operators.h

        // Value zwracana jest zawsze w pierwszym zasiegu funkcji na samym poczatku
        // _position( 1, 0)  -   scope 0 jest zarezerwowany dla zasiegu globalnego
        Operators::copy(__runTimeData.localVariableTable->value(
                            Scope::parameterScope, Scope::returnPosition),
                        _expression->execute(__runTimeData));

        return 0x00;
    }

    // Przechodzi przez drzewo skladniowe w glab
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // ktora przechowuje informacje o tablicach symboli.
    // Dodaje zadeklarowana zmienna do tablicy symboli
    virtual void analise(AnalysisData& __analysisData)
    {
        _expression->analise(__analysisData);
    }

protected:
    // Wyra¿enie po slowie kluczowym 'return'
    Expression* _expression;
};

#endif
