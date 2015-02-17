// Version 1.0

#ifndef _INSTRUKCJA_ITERACYJNA_WHILE_H_
#define _INSTRUKCJA_ITERACYJNA_WHILE_H_

#include "complexInstruction.h"
#include "expression.h"

// Reprezentuje instrukcje 'while'
class WhileInstruction : public Instruction {
public:
    // Konstruktor przyjmuje jako argumenty wyra�enie kt�re b�dzie sprawdzane
    // przed ka�d� iteracj� p�tli, instrukcje z�o�on� kt�ra jest tre�ci� p�tli,
    // oraz numer linii gdzie instruction warunkowa si� rozpoczyna
    inline WhileInstruction(
        Expression* __expression, Instruction* __instruction, int __lineNumber);

    // Wykonuje instrukcj�
    virtual Value* execute(RunTimeData& __runTimeData);

    // Przechodzi przez drzewo sk�adniowe w gl�b
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // kt�ra przechowuje informacje o tablicach symboli
    virtual void analise(AnalysisData& __analysisData);

private:
    // Wyra�enie testowane przy ka�dym wykonaniu p�tli
    Expression* _expression;

    // Instruction zlo�ona kt�ra wykona si� je�eli warunek b�dzie spe�niony
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
