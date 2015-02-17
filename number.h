// Version 1.0

#ifndef _LICZBA_H_
#define _LICZBA_H_

#include "factor.h"

// Reprezentuje liczbe
class Number : public Factor {
public:
    // Konstruktor przyjmuje wartosc liczby,
    // oraz numer linii w ktorej wystapila number
    Number(double __value, int __lineNumber)
        : Factor(Double, __lineNumber)
        , _value(__value, ReadOnly)
    {
    }

    // Zwraca value liczby
    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        return &_value;
    }

    // Analizuje liczbe
    void analise(AnalysisData& __analysisData)
    {
        // Klasa 'Number' jest lisciem w drzewie skladniowym programu u¿ytkowanika
    }

private:
    // Przechowuje wartosc liczbowa
    DoubleValue _value;
};

#endif
