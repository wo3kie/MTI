// Version 1.0

#ifndef _INSTRUKCJA_ITERACYJNA_WHILE_H_
#define _INSTRUKCJA_ITERACYJNA_WHILE_H_

#include "complexInstruction.h"
#include "expression.h"

// Reprezentuje instrukcje 'while'
class InstrukcjaIteracyjnaWhile: public Instrukcja{
    public:
        // Konstruktor przyjmuje jako argumenty wyra¿enie które bêdzie sprawdzane
        // przed ka¿d¹ iteracj¹ pêtli, instrukcje z³o¿on¹ która jest treœci¹ pêtli,
        // oraz numer linii gdzie instrukcja warunkowa siê rozpoczyna
        inline InstrukcjaIteracyjnaWhile(
            Wyrazenie* __wyrazenie,Instrukcja* __instrukcja,int __numerLinii);

        // Wykonuje instrukcjê
        virtual Wartosc* execute( RunTimeData& __runTimeData);

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // która przechowuje informacje o tablicach symboli
        virtual void analise( AnalysisData& __analysisData);

    private:
        // Wyra¿enie testowane przy ka¿dym wykonaniu pêtli
        Wyrazenie* _wyrazenie;

        // Instrukcja zlo¿ona która wykona siê je¿eli warunek bêdzie spe³niony
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
