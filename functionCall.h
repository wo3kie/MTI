// Version 1.0

#ifndef _WYWOLANIE_FUNKCJI_H_
#define _WYWOLANIE_FUNKCJI_H_

#include "functionDefinition.h"

// Reprezentuje wywolanie funkcji
class FunctionCall : public Factor {
public:
    // Konstruktor przyjmuje identifier wywolywanej funkcji, liste wyra¿en oraz numer linii
    FunctionCall(std::string __identifier, ExpressionList* __expressionList, int __lineNumber)
        : Factor(Void, __lineNumber)
        , _expressionList(__expressionList)
        , _identifier(__identifier)
    {
    }

    // Sprawdza czy ilosc oraz typy argumentow funkcji i parametrow wywolania sa zgodne
    virtual void analise(AnalysisData& __analysisData);

    // Wywoluje funkcje
    virtual const Value* execute(RunTimeData& _runTimeData);

private:
    // Wyra¿enia w wywolaniu funkcji
    ExpressionList* _expressionList;

    std::string _identifier;
    unsigned _position;
};

#endif
