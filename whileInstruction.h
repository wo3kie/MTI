// Version 1.0

#ifndef _INSTRUKCJA_ITERACYJNA_WHILE_H_
#define _INSTRUKCJA_ITERACYJNA_WHILE_H_

#include "complexInstruction.h"
#include "expression.h"

// Reprezentuje instrukcje 'while'
class InstrukcjaIteracyjnaWhile: public Instrukcja{
    public:
        // Konstruktor przyjmuje jako argumenty wyra�enie kt�re b�dzie sprawdzane
        // przed ka�d� iteracj� p�tli, instrukcje z�o�on� kt�ra jest tre�ci� p�tli,
        // oraz numer linii gdzie instrukcja warunkowa si� rozpoczyna
        inline InstrukcjaIteracyjnaWhile(
            Wyrazenie* __wyrazenie,Instrukcja* __instrukcja,int __numerLinii);

        // Wykonuje instrukcj�
        virtual Wartosc* execute( RunTimeData& __runTimeData);

        // Przechodzi przez drzewo sk�adniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli
        virtual void analise( AnalysisData& __analysisData);

    private:
        // Wyra�enie testowane przy ka�dym wykonaniu p�tli
        Wyrazenie* _wyrazenie;

        // Instrukcja zlo�ona kt�ra wykona si� je�eli warunek b�dzie spe�niony
        Instrukcja* _instrukcja;
};

/* ================================================ InstrukcjaIteracyjnaWhile */
inline InstrukcjaIteracyjnaWhile::InstrukcjaIteracyjnaWhile(
    Wyrazenie* __wyrazenie,Instrukcja* __instrukcja,int __numerLinii)
:Instrukcja( Void, __numerLinii),
_wyrazenie(__wyrazenie),
_instrukcja(__instrukcja){
}

#endif
