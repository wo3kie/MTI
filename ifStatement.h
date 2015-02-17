// Version 1.0

#ifndef _INSTRUKCJA_WARUNKOWA_IF_
#define _INSTRUKCJA_WARUNKOWA_IF_

#include "complexInstruction.h"
#include "expression.h"

// Reprezentuje instrukcje warunkowa w programie u¿ytkowanika
class IfStatement : public Instruction {
public:
    // Konstruktor przyjmuje wyra¿enie, dwie instrukcje zlo¿one oraz numer linii
    // w ktorej wystapila ta instruction
    IfStatement(Expression* __expression, Instruction* __instrukcja1,
                Instruction* __instrukcja2, int __lineNumber)
        : Instruction(Void, __lineNumber)
        , _expression(__expression)
        , _instruction1(__instrukcja1)
        , _instruction2(__instrukcja2)
    {
    }

    // Konstruktor przyjmuje wyra¿enie, instrukcje zlo¿ona oraz numer linii
    // w ktorej wystapila ta instruction
    IfStatement(Expression* __expression, Instruction* __instruction, int __lineNumber)
        : Instruction(Void, __lineNumber)
        , _expression(__expression)
        , _instruction1(__instruction)
        , _instruction2(0x00)
    {
    }

    // Wykonuje instrukcje warunkowa
    virtual const Value* execute(RunTimeData& __runTimeData);

    // Przechodzi przez drzewo skladniowe w glab
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // ktora przechowuje informacje o tablicach symboli.
    // Dodaje zadeklarowana zmienna do tablicy symboli
    virtual void analise(AnalysisData& __analysisData);

private:
    // Wyra¿enie logiczne
    Expression* _expression;

    // Je¿eli wyra¿enie logiczne bylo prawdziwe wykona sie ta instruction
    Instruction* _instruction1;

    // Je¿eli wyra¿enie logiczne bylo falszywe wykona sie ta instruction
    Instruction* _instruction2;
};

#endif
