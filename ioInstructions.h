// Version 1.0

#ifndef _INSTRUKCJE_IO_H_
#define _INSTRUKCJE_IO_H_

#include "instruction.h"

// Reprezentuje instrukcjê drukowania
class PrintInstruction : public Instruction {
public:
    // Konstruktor przyjmuje wyra¿enie które bêdzi drukowane oraz numer linii
    // w której wyst¹pi³a instruction
    PrintInstruction(Expression* __expression, int __lineNumber)
        : Instruction(Void, __lineNumber)
        , _expression(__expression)
    {
    }

    // Wykonuje instrukcjê
    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        return _expression->execute(__runTimeData)->printf();
    }

    // Przechodzi przez drzewo sk³adniowe w gl¹b
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // która przechowuje informacje o tablicach symboli.
    // Dodaje zadeklarowan¹ zmienna do tablicy symboli
    virtual void analise(AnalysisData& __analysisData)
    {
        _expression->analise(__analysisData);
    }

    // Zwraca type instrukcji
    virtual Type type() const {
        return Void; }

protected:
    // Wyra¿enie którego wartoœc bêdzie wydrukowana
    Expression* _expression;
};

// Reprezentuje instrukcjê przejœcia do nowej linii
class EndlInstruction : public PrintInstruction {
public:
    // Konstruktor przyjmuje numer linii w której wyst¹pi³a instruction
    inline EndlInstruction(int __lineNumber)
        : PrintInstruction(0x00, __lineNumber)
    {
    }

    // Wykonuje instrukcjê
    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        std::cout << std::endl;
        return 0x00;
    }

    // Przechodzi przez drzewo sk³adniowe w gl¹b
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // która przechowuje informacje o tablicach symboli.
    // Dodaje zadeklarowan¹ zmienna do tablicy symboli
    virtual void analise(AnalysisData& __analysisData) {}
};

// Reprezentuje instrukcjê wczytywania
class ScanInstruction : public Instruction {
public:
    ScanInstruction(Identifier* __identifier, int __lineNumber)
        : Instruction(Void, __lineNumber)
        , _identifier(__identifier)
    {
    }

    // Wykonuje instrukcjê
    const Value* execute(RunTimeData& __runTimeData)
    {
        return _identifier->assign(__runTimeData)->scanf();
    }

    // Przechodzi przez drzewo sk³adniowe w gl¹b
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // która przechowuje informacje o tablicach symboli.
    // Dodaje zadeklarowan¹ zmienna do tablicy symboli
    virtual void analise(AnalysisData& __analysisData)
    {
        _identifier->analise(__analysisData);
    }

    // Zwraca type instrukcji
    virtual Type type() const {
        return Void; }

protected:
    // Identifier do którego bêdziemy wpisywac wczytan¹ wartoœc
    Identifier* _identifier;
};

#endif
