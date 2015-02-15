// Version 1.0

#ifndef _INSTRUKCJA_WARUNKOWA_IF_
#define _INSTRUKCJA_WARUNKOWA_IF_

#include "instrukcjaZlozona.h"
#include "wyrazenie.h"

// Reprezentuje instrukcje warunkow� w programie u�ytkowanika
class InstrukcjaWarunkowaIf:public Instrukcja{
    public:
        // Konstruktor przyjmuje wyra�enie, dwie instrukcje z�o�one oraz numer linii
        // w kt�rej wyst�pi�a ta instrukcja
        InstrukcjaWarunkowaIf(Wyrazenie* __wyrazenie,Instrukcja* __instrukcja1,
        Instrukcja* __instrukcja2, int __numerLinii)
        :Instrukcja( Void, __numerLinii),
        _wyrazenie(__wyrazenie),
        _instrukcja1(__instrukcja1),
        _instrukcja2(__instrukcja2){
        }

        // Konstruktor przyjmuje wyra�enie, instrukcje z�o�on� oraz numer linii
        // w kt�rej wyst�pi�a ta instrukcja
        InstrukcjaWarunkowaIf(Wyrazenie* __wyrazenie,Instrukcja* __instrukcja, int __numerLinii)
        :Instrukcja( Void, __numerLinii),
        _wyrazenie(__wyrazenie),
        _instrukcja1(__instrukcja),
        _instrukcja2(0x00){
        }

        // Wykonuje instrukcj� warunkow�
        virtual const Wartosc* execute( RunTimeData& __runTimeData);

        // Przechodzi przez drzewo sk�adniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan� zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData);

    private:
        // Wyra�enie logiczne
        Wyrazenie* _wyrazenie;

        // Je�eli wyra�enie logiczne bylo prawdziwe wykona si� ta instrukcja
        Instrukcja* _instrukcja1;

        // Je�eli wyra�enie logiczne bylo fa�szywe wykona si� ta instrukcja
        Instrukcja* _instrukcja2;
};

#endif
