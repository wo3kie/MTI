// Version 1.0

#ifndef _INSTRUKCJA_WARUNKOWA_IF_
#define _INSTRUKCJA_WARUNKOWA_IF_

#include "instrukcjaZlozona.h"
#include "wyrazenie.h"

// Reprezentuje instrukcje warunkow¹ w programie u¿ytkowanika
class InstrukcjaWarunkowaIf:public Instrukcja{
    public:
        // Konstruktor przyjmuje wyra¿enie, dwie instrukcje z³o¿one oraz numer linii
        // w której wyst¹pi³a ta instrukcja
        InstrukcjaWarunkowaIf(Wyrazenie* __wyrazenie,Instrukcja* __instrukcja1,
        Instrukcja* __instrukcja2, int __numerLinii)
        :Instrukcja( Void, __numerLinii),
        _wyrazenie(__wyrazenie),
        _instrukcja1(__instrukcja1),
        _instrukcja2(__instrukcja2){
        }

        // Konstruktor przyjmuje wyra¿enie, instrukcje z³o¿on¹ oraz numer linii
        // w której wyst¹pi³a ta instrukcja
        InstrukcjaWarunkowaIf(Wyrazenie* __wyrazenie,Instrukcja* __instrukcja, int __numerLinii)
        :Instrukcja( Void, __numerLinii),
        _wyrazenie(__wyrazenie),
        _instrukcja1(__instrukcja),
        _instrukcja2(0x00){
        }

        // Wykonuje instrukcjê warunkow¹
        virtual const Wartosc* execute( RunTimeData& __runTimeData);

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // która przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan¹ zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData);

    private:
        // Wyra¿enie logiczne
        Wyrazenie* _wyrazenie;

        // Je¿eli wyra¿enie logiczne bylo prawdziwe wykona siê ta instrukcja
        Instrukcja* _instrukcja1;

        // Je¿eli wyra¿enie logiczne bylo fa³szywe wykona siê ta instrukcja
        Instrukcja* _instrukcja2;
};

#endif
