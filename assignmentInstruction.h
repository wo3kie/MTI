// Version 1.0

#ifndef _INSTRUKCJA_PRZYPISANIA_H_
#define _INSTRUKCJA_PRZYPISANIA_H_

#include "exceptions.h"
#include "expression.h"

// Reprezentuje instrukcje przypisania
class AssignmentInstruction : public Instruction {
public:
    // Konstruktor przyjmuje jako parameter nazwe zmiennej do ktorej bedziemy przypisywac,
    // wyra¿enie ktorego wartosc przypiszemy oraz numer linii, w ktorej byla instruction przypisania
    inline AssignmentInstruction(Identifier* __identifier, Expression* __expression, int __lineNumber);

    // Wykonuje instrukcje
    virtual const Value* execute(RunTimeData& __runTimeData);

    // Przechodzi przez drzewo skladniowe w glab
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // ktora przechowuje informacje o tablicach symboli
    // Sprawdza zgodnosc typow, zmiennej do ktorej przypisujemy
    // oraz wyrazenia.
    virtual void analise(AnalysisData& __analysisData);

protected:
    // Wskaznik na identifier, zmienna do ktorej przypisujemy
    Identifier* _identifier;

    // Wskaznik na wyra¿enie, ktorego wartosc be¿dziemy przypisywac
    Expression* _expression;
};

/* ==================================================== AssignmentInstruction */
inline AssignmentInstruction::AssignmentInstruction(
    Identifier* __identifier, Expression* __expression, int __lineNumber)
    : Instruction(Void, __lineNumber)
    , _identifier(__identifier)
    , _expression(__expression)
{
}

#endif
