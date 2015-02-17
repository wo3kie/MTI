// Version 1.0

#ifndef _INSTRUKCJE_IO_H_
#define _INSTRUKCJE_IO_H_

#include "instruction.h"

// Reprezentuje instrukcj� drukowania
class PrintInstruction : public Instruction {
public:
    // Konstruktor przyjmuje wyra�enie kt�re b�dzi drukowane oraz numer linii
    // w kt�rej wyst�pi�a instruction
    PrintInstruction(Expression* __expression, int __lineNumber)
        : Instruction(Void, __lineNumber)
        , _expression(__expression)
    {
    }

    // Wykonuje instrukcj�
    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        return _expression->execute(__runTimeData)->printf();
    }

    // Przechodzi przez drzewo sk�adniowe w gl�b
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // kt�ra przechowuje informacje o tablicach symboli.
    // Dodaje zadeklarowan� zmienna do tablicy symboli
    virtual void analise(AnalysisData& __analysisData)
    {
        _expression->analise(__analysisData);
    }

    // Zwraca type instrukcji
    virtual Type type() const {
        return Void; }

protected:
    // Wyra�enie kt�rego warto�c b�dzie wydrukowana
    Expression* _expression;
};

// Reprezentuje instrukcj� przej�cia do nowej linii
class EndlInstruction : public PrintInstruction {
public:
    // Konstruktor przyjmuje numer linii w kt�rej wyst�pi�a instruction
    inline EndlInstruction(int __lineNumber)
        : PrintInstruction(0x00, __lineNumber)
    {
    }

    // Wykonuje instrukcj�
    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        std::cout << std::endl;
        return 0x00;
    }

    // Przechodzi przez drzewo sk�adniowe w gl�b
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // kt�ra przechowuje informacje o tablicach symboli.
    // Dodaje zadeklarowan� zmienna do tablicy symboli
    virtual void analise(AnalysisData& __analysisData) {}
};

// Reprezentuje instrukcj� wczytywania
class ScanInstruction : public Instruction {
public:
    ScanInstruction(Identifier* __identifier, int __lineNumber)
        : Instruction(Void, __lineNumber)
        , _identifier(__identifier)
    {
    }

    // Wykonuje instrukcj�
    const Value* execute(RunTimeData& __runTimeData)
    {
        return _identifier->assign(__runTimeData)->scanf();
    }

    // Przechodzi przez drzewo sk�adniowe w gl�b
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // kt�ra przechowuje informacje o tablicach symboli.
    // Dodaje zadeklarowan� zmienna do tablicy symboli
    virtual void analise(AnalysisData& __analysisData)
    {
        _identifier->analise(__analysisData);
    }

    // Zwraca type instrukcji
    virtual Type type() const {
        return Void; }

protected:
    // Identifier do kt�rego b�dziemy wpisywac wczytan� warto�c
    Identifier* _identifier;
};

#endif
