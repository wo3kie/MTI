// Version 1.0

#ifndef _NAWIAS_H_
#define _NAWIAS_H_

#include "expression.h"

// Reprezentuje bracket
class Bracket : public Factor {
public:
    // Konstruktor przyjmuje wyra¿enie oraz numer linii w której wyst¹pi³
    // bracket
    Bracket(Expression* __expression, int __lineNumber)
        : Factor(Void, __lineNumber)
        , _left(__expression)
    {
    }
    virtual ~Bracket() {}

    // Zwraca value wyrazenia w nawiasach
    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        return _left->execute(__runTimeData);
    }

    // Analizuje expression zawarte w nawiasie
    virtual void analise(AnalysisData& __analysisData);

private:
    // Expression w nawiasie
    Expression* _left;
};

/* ================================================================== analise */
inline void Bracket::analise(AnalysisData& __analysisData)
{
    _left->analise(__analysisData);
    _type = _left->type();
}

#endif
