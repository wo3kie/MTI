// Version 1.0

#ifndef _INSTRUKCJA_PRZYPISANIA_H_
#define _INSTRUKCJA_PRZYPISANIA_H_

#include "exceptions.h"
#include "expression.h"

// Reprezentuje instrukcje przypisania
class AssignmentInstruction : public Instruction {
public:
    // Konstruktor przyjmuje jako parameter nazwe zmiennej do której bêdziemy przypisywac,
    // wyra¿enie którego wartoœc przypiszemy oraz numer linii, w której by³a instruction przypisania
    inline AssignmentInstruction(Identifier* __identifier, Expression* __expression, int __lineNumber);

    // Wykonuje instrukcjê
    virtual const Value* execute(RunTimeData& __runTimeData);

    // Przechodzi przez drzewo skladniowe w gl¹b
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencjê klasy 'AnalysisData'
    // która przechowuje informacje o tablicach symboli
    // Sprawdza zgodnoœc typów, zmiennej do ktorej przypisujemy
    // oraz wyrazenia.
    virtual void analise(AnalysisData& __analysisData);

protected:
    // WskaŸnik na identifier, zmienna do której przypisujemy
    Identifier* _identifier;

    // WskaŸnik na wyra¿enie, którego wartoœc bê¿dziemy przypisywac
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
