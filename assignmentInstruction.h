// Version 1.0

#ifndef _INSTRUKCJA_PRZYPISANIA_H_
#define _INSTRUKCJA_PRZYPISANIA_H_

#include "exceptions.h"
#include "expression.h"

// Reprezentuje instrukcje przypisania
class AssignmentInstruction : public Instruction {
public:
    // Konstruktor przyjmuje jako parameter nazwe zmiennej do kt�rej b�dziemy przypisywac,
    // wyra�enie kt�rego warto�c przypiszemy oraz numer linii, w kt�rej by�a instruction przypisania
    inline AssignmentInstruction(Identifier* __identifier, Expression* __expression, int __lineNumber);

    // Wykonuje instrukcj�
    virtual const Value* execute(RunTimeData& __runTimeData);

    // Przechodzi przez drzewo skladniowe w gl�b
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencj� klasy 'AnalysisData'
    // kt�ra przechowuje informacje o tablicach symboli
    // Sprawdza zgodno�c typ�w, zmiennej do ktorej przypisujemy
    // oraz wyrazenia.
    virtual void analise(AnalysisData& __analysisData);

protected:
    // Wska�nik na identifier, zmienna do kt�rej przypisujemy
    Identifier* _identifier;

    // Wska�nik na wyra�enie, kt�rego warto�c b�dziemy przypisywac
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
