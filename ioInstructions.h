// Version 1.0

#ifndef _INSTRUKCJE_IO_H_
#define _INSTRUKCJE_IO_H_

#include "instruction.h"

// Reprezentuje instrukcje drukowania
class PrintInstruction : public Instruction {
public:
    // Konstruktor przyjmuje wyra¿enie ktore bedzi drukowane oraz numer linii
    // w ktorej wystapila instruction
    PrintInstruction(Expression* __expression, int __lineNumber)
        : Instruction(Void, __lineNumber)
        , _expression(__expression)
    {
    }

    // Wykonuje instrukcje
    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        return _expression->execute(__runTimeData)->printf();
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

    // Zwraca type instrukcji
    virtual Type type() const {
        return Void; }

protected:
    // Wyra¿enie ktorego wartosc bedzie wydrukowana
    Expression* _expression;
};

// Reprezentuje instrukcje przejscia do nowej linii
class EndlInstruction : public PrintInstruction {
public:
    // Konstruktor przyjmuje numer linii w ktorej wystapila instruction
    inline EndlInstruction(int __lineNumber)
        : PrintInstruction(0x00, __lineNumber)
    {
    }

    // Wykonuje instrukcje
    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        std::cout << std::endl;
        return 0x00;
    }

    // Przechodzi przez drzewo skladniowe w glab
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // ktora przechowuje informacje o tablicach symboli.
    // Dodaje zadeklarowana zmienna do tablicy symboli
    virtual void analise(AnalysisData& __analysisData) {}
};

// Reprezentuje instrukcje wczytywania
class ScanInstruction : public Instruction {
public:
    ScanInstruction(Identifier* __identifier, int __lineNumber)
        : Instruction(Void, __lineNumber)
        , _identifier(__identifier)
    {
    }

    // Wykonuje instrukcje
    const Value* execute(RunTimeData& __runTimeData)
    {
        return _identifier->assign(__runTimeData)->scanf();
    }

    // Przechodzi przez drzewo skladniowe w glab
    // w celu analizy semantycznej drzewa.
    // Jako parameter przyjmuje referencje klasy 'AnalysisData'
    // ktora przechowuje informacje o tablicach symboli.
    // Dodaje zadeklarowana zmienna do tablicy symboli
    virtual void analise(AnalysisData& __analysisData)
    {
        _identifier->analise(__analysisData);
    }

    // Zwraca type instrukcji
    virtual Type type() const {
        return Void; }

protected:
    // Identifier do ktorego bedziemy wpisywac wczytana wartosc
    Identifier* _identifier;
};

#endif
