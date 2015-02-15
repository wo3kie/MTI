// Version 1.0

#ifndef _INSTRUKCJA_PRZYPISANIA_H_
#define _INSTRUKCJA_PRZYPISANIA_H_

#include "exceptions.h"
#include "expression.h"

// Reprezentuje instrukcje przypisania
class InstrukcjaPrzypisania:public Instrukcja{
    public:
        // Konstruktor przyjmuje jako parametr nazwe zmiennej do której bêdziemy przypisywac,
        // wyra¿enie którego wartoœc przypiszemy oraz numer linii, w której by³a instrukcja przypisania
        inline InstrukcjaPrzypisania( Identyfikator* __identyfikator, Wyrazenie* __wyrazenie, int __numerLinii);

        // Wykonuje instrukcjê
        virtual const Wartosc* execute(RunTimeData& __runTimeData);

        // Przechodzi przez drzewo skladniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencjê klasy 'AnalysisData'
        // która przechowuje informacje o tablicach symboli
        // Sprawdza zgodnoœc typów, zmiennej do ktorej przypisujemy
        // oraz wyrazenia.
        virtual void analise( AnalysisData& __analysisData);

    protected:
        // WskaŸnik na identyfikator, zmienna do której przypisujemy
        Identyfikator* _identyfikator;

        // WskaŸnik na wyra¿enie, którego wartoœc bê¿dziemy przypisywac
        Wyrazenie* _wyrazenie;
};

/* ==================================================== InstrukcjaPrzypisania */
inline InstrukcjaPrzypisania::InstrukcjaPrzypisania(
    Identyfikator* __identyfikator, Wyrazenie* __wyrazenie,int __numerLinii)
:Instrukcja( Void, __numerLinii),
_identyfikator( __identyfikator),
_wyrazenie( __wyrazenie){
}

#endif
