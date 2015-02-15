// Version 1.0

#ifndef _LICZBA_H_
#define _LICZBA_H_

#include "factor.h"

// Reprezentuje liczb�
class Liczba:public Czynnik{
    public:
        // Konstruktor przyjmuje warto�c liczby,
        // oraz numer linii w kt�rej wyst�pi�a liczba
        Liczba(double __wartosc, int __numerLinii)
        :Czynnik( Double, __numerLinii),
        _wartosc(__wartosc,ReadOnly){}

        // Zwraca wartosc liczby
        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            return &_wartosc;
        }

        // Analizuje liczb�
        void analise(AnalysisData& __analysisData){
            // Klasa 'Liczba' jest li�ciem w drzewie sk�adniowym programu u�ytkowanika
        }

    private:
        // Przechowuje warto�c liczbow�
        WartoscDouble _wartosc;
};

#endif
