// Version 1.0

#ifndef _LICZBA_H_
#define _LICZBA_H_

#include "factor.h"

// Reprezentuje liczbê
class Liczba:public Czynnik{
    public:
        // Konstruktor przyjmuje wartoœc liczby,
        // oraz numer linii w której wyst¹pi³a liczba
        Liczba(double __wartosc, int __numerLinii)
        :Czynnik( Double, __numerLinii),
        _wartosc(__wartosc,ReadOnly){}

        // Zwraca wartosc liczby
        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            return &_wartosc;
        }

        // Analizuje liczbê
        void analise(AnalysisData& __analysisData){
            // Klasa 'Liczba' jest liœciem w drzewie sk³adniowym programu u¿ytkowanika
        }

    private:
        // Przechowuje wartoœc liczbow¹
        WartoscDouble _wartosc;
};

#endif
