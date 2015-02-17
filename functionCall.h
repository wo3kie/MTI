// Version 1.0

#ifndef _WYWOLANIE_FUNKCJI_H_
#define _WYWOLANIE_FUNKCJI_H_

#include "functionDefinition.h"

// Reprezentuje wywolanie funkcji
class FunctionCall : public Factor {
public:
    // Konstruktor przyjmuje identifier wywo³ywanej funkcji, listê wyra¿eñ oraz numer linii
    FunctionCall(std::string __identifier, ExpressionList* __expressionList, int __lineNumber)
        : Factor(Void, __lineNumber)
        , _expressionList(__expressionList)
        , _identifier(__identifier)
    {
    }

    // Sprawdza czy iloœc oraz typy argumentów funkcji i parametrów wywo³ania s¹ zgodne
    virtual void analise(AnalysisData& __analysisData);

    // Wywo³uje funkcjê
    virtual const Value* execute(RunTimeData& _runTimeData);

private:
    // Wyra¿enia w wywo³aniu funkcji
    ExpressionList* _expressionList;

    std::string _identifier;
    unsigned _position;
};

#endif
