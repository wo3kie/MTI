// Version 1.0

#ifndef _LICZBA_H_
#define _LICZBA_H_

#include "factor.h"

// Reprezentuje liczbê
class Number:public Factor{
    public:
        // Konstruktor przyjmuje wartoœc liczby,
        // oraz numer linii w której wyst¹pi³a number
        Number(double __value, int __lineNumber)
        :Factor( Double, __lineNumber),
        _value(__value,ReadOnly){}

        // Zwraca value liczby
        virtual const Value* execute( RunTimeData& __runTimeData){
            return &_value;
        }

        // Analizuje liczbê
        void analise(AnalysisData& __analysisData){
            // Klasa 'Number' jest liœciem w drzewie sk³adniowym programu u¿ytkowanika
        }

    private:
        // Przechowuje wartoœc liczbow¹
        DoubleValue _value;
};

#endif
