// Version 1.0

#ifndef _INSTRUKCJA_ITERACYJNA_WHILE_H_
#define _INSTRUKCJA_ITERACYJNA_WHILE_H_

#include "complexInstruction.h"
#include "expression.h"

// Reprezentuje instrukcje 'while'
class WhileInstruction : public Instruction {
public:
    // Konstruktor przyjmuje jako argumenty wyra¿enie które bêdzie sprawdzane
    // przed ka¿d¹ iteracj¹ pêtli, instrukcje z³o¿on¹ która jest treœci¹ pêtli,
    // oraz numer linii gdzie instruction warunkowa siê rozpoczyna
    inline WhileInstruction(
        Expression* __expression, Instruction* __instruction, int __lineNumber);

    // Wykonuje instrukcjê
    virtual Value* execute(RunTimeData& __runTimeData);

    // Przechodzi przez drzewo sk³adniowe w gl¹b
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // która przechowuje informacje o tablicach symboli
    virtual void analise(AnalysisData& __analysisData);

private:
    // Wyra¿enie testowane przy ka¿dym wykonaniu pêtli
    Expression* _expression;

    // Instruction zlo¿ona która wykona siê je¿eli warunek bêdzie spe³niony
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
