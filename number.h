// Version 1.0

#ifndef _LICZBA_H_
#define _LICZBA_H_

#include "factor.h"

// Reprezentuje liczb�
class Number:public Factor{
    public:
        // Konstruktor przyjmuje warto�c liczby,
        // oraz numer linii w kt�rej wyst�pi�a number
        Number(double __value, int __lineNumber)
        :Factor( Double, __lineNumber),
        _value(__value,ReadOnly){}

        // Zwraca value liczby
        virtual const Value* execute( RunTimeData& __runTimeData){
            return &_value;
        }

        // Analizuje liczb�
        void analise(AnalysisData& __analysisData){
            // Klasa 'Number' jest li�ciem w drzewie sk�adniowym programu u�ytkowanika
        }

    private:
        // Przechowuje warto�c liczbow�
        DoubleValue _value;
};

#endif
