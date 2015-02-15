// Version 1.0

#ifndef _INSTRUKCJA_PRZYPISANIA_H_
#define _INSTRUKCJA_PRZYPISANIA_H_

#include "exceptions.h"
#include "expression.h"

// Reprezentuje instrukcje przypisania
class InstrukcjaPrzypisania:public Instrukcja{
    public:
        // Konstruktor przyjmuje jako parametr nazwe zmiennej do kt�rej b�dziemy przypisywac,
        // wyra�enie kt�rego warto�c przypiszemy oraz numer linii, w kt�rej by�a instrukcja przypisania
        inline InstrukcjaPrzypisania( Identyfikator* __identyfikator, Wyrazenie* __wyrazenie, int __numerLinii);

        // Wykonuje instrukcj�
        virtual const Wartosc* execute(RunTimeData& __runTimeData);

        // Przechodzi przez drzewo skladniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencj� klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli
        // Sprawdza zgodno�c typ�w, zmiennej do ktorej przypisujemy
        // oraz wyrazenia.
        virtual void analise( AnalysisData& __analysisData);

    protected:
        // Wska�nik na identyfikator, zmienna do kt�rej przypisujemy
        Identyfikator* _identyfikator;

        // Wska�nik na wyra�enie, kt�rego warto�c b�dziemy przypisywac
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
