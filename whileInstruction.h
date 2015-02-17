// Version 1.0

#ifndef _INSTRUKCJA_ITERACYJNA_WHILE_H_
#define _INSTRUKCJA_ITERACYJNA_WHILE_H_

#include "complexInstruction.h"
#include "expression.h"

// Reprezentuje instrukcje 'while'
class WhileInstruction : public Instruction {
public:
    // Konstruktor przyjmuje jako argumenty wyra¿enie ktore bedzie sprawdzane
    // przed ka¿da iteracja petli, instrukcje zlo¿ona ktora jest trescia petli,
    // oraz numer linii gdzie instruction warunkowa sie rozpoczyna
    inline WhileInstruction(
        Expression* __expression, Instruction* __instruction, int __lineNumber);

    // Wykonuje instrukcje
    virtual Value* execute(RunTimeData& __runTimeData);

    // Przechodzi przez drzewo skladniowe w glab
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // ktora przechowuje informacje o tablicach symboli
    virtual void analise(AnalysisData& __analysisData);

private:
    // Wyra¿enie testowane przy ka¿dym wykonaniu petli
    Expression* _expression;

    // Instruction zlo¿ona ktora wykona sie je¿eli warunek bedzie spelniony
    Instruction* _instruction;
};

/* ================================================ WhileInstruction */
inline WhileInstruction::WhileInstruction(
    Expression* __expression, Instruction* __instruction, int __lineNumber)
    : Instruction(Void, __lineNumber)
    , _expression(__expression)
    , _instruction(__instruction)
{
}

#endif
