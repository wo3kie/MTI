// Version 1.0

#ifndef _INSTRUKCJA_ITERACYJNA_FOR_H_
#define _INSTRUKCJA_ITERACYJNA_FOR_H_

#include "deklaracja.h"
#include "instrukcjaPrzypisania.h"
#include "instrukcjaZlozona.h"
#include "wyrazenie.h"

// Reprezentuje instrukcje 'while'
class InstrukcjaIteracyjnaFor: public Instrukcja{
    public:
        // Konstruktor przyjmuje jako argumenty wyra�enie kt�re b�dzie sprawdzane
        // przed ka�d� iteracj� p�tli, instrukcje z�o�on� kt�ra jest tre�ci� p�tli,
        // oraz numer linii gdzie instrukcja warunkowa si� rozpoczyna
        inline InstrukcjaIteracyjnaFor(
            Deklaracja* __deklaracja, Wyrazenie* __warunek, InstrukcjaPrzypisania* __przypisanie,
            Instrukcja* __instrukcja,int __numerLinii);

        // Wykonuje instrukcj�
        virtual Wartosc* execute( RunTimeData& __runTimeData);

        // Przechodzi przez drzewo sk�adniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli
        virtual void analise( AnalysisData& __analysisData);

    private:
        Deklaracja* _deklaracja;//deklaracja
        Wyrazenie* _warunek;// warunek konca petli
        InstrukcjaPrzypisania* _przypisanie;// inkrementacja

        // Instrukcja zlo�ona kt�ra wykona si� je�eli warunek b�dzie spe�niony
        Instrukcja* _instrukcja;
};

/* ================================================ InstrukcjaIteracyjnaWhile */
inline InstrukcjaIteracyjnaFor::InstrukcjaIteracyjnaFor(
    Deklaracja* __deklaracja,Wyrazenie*__warunek,InstrukcjaPrzypisania* __przypisanie,Instrukcja* __instrukcja,int __numerLinii)
:Instrukcja( Void, __numerLinii),
_deklaracja( __deklaracja),
_warunek( __warunek),
_przypisanie( __przypisanie),
_instrukcja( __instrukcja){
}

#endif
