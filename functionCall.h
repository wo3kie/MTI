// Version 1.0

#ifndef _WYWOLANIE_FUNKCJI_H_
#define _WYWOLANIE_FUNKCJI_H_

#include "functionDefinition.h"

// Reprezentuje wywolanie funkcji
class FunctionCall : public Factor {
public:
    // Konstruktor przyjmuje identifier wywo�ywanej funkcji, list� wyra�e� oraz numer linii
    FunctionCall(std::string __identifier, ExpressionList* __expressionList, int __lineNumber)
        : Factor(Void, __lineNumber)
        , _expressionList(__expressionList)
        , _identifier(__identifier)
    {
    }

    // Sprawdza czy ilo�c oraz typy argument�w funkcji i parametr�w wywo�ania s� zgodne
    virtual void analise(AnalysisData& __analysisData);

    // Wywo�uje funkcj�
    virtual const Value* execute(RunTimeData& _runTimeData);

private:
    // Wyra�enia w wywo�aniu funkcji
    ExpressionList* _expressionList;

    std::string _identifier;
    unsigned _position;
};

#endif
