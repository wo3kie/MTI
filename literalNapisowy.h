// Version 1.0

#ifndef _LITERAL_NAPISOWY_H_
#define _LITERAL_NAPISOWY_H_

#include "czynnik.h"

// Reprezentuje litera³ napisowy
// Litera³ napisowy jest ci¹giem znaków zawartych pomiêdzy cudzys³owami
// Litera³ napisowy nie mo¿e byc dlu¿szy ni¿ jedna linia
class LiteralNapisowy: public Czynnik{
    public:
        // Konstruktor przyjmuje wartoœc litera³u napisowego
        // oraz numer linii w której on wyst¹pi³
        // Usuwa cudzys³ów z napisów.: "kasia" -> kasia
        inline LiteralNapisowy(const std::string& __napis, int __numerLinii)
        :Czynnik( String, __numerLinii),
        _wartosc(__napis.substr( 1, __napis.size()- 2)){
        }

        // Zwraca litera³ napisowy
        virtual const Wartosc* execute(RunTimeData& _runTimeData){ return &_wartosc;}

        // Analizuje litera³ napisowy
        virtual void analise(AnalysisData&){
            // Ta klasa jest liœciem drzewa sk³adniowego. Metoda 'analise' nie robi nic.
            // Na niej koñczy siê przechodzenie drzewa sk³adniowego 'w gl¹b'.
        }

        // Zwraca typ litera³u. Zawsze jest to string
        virtual Typ typ()const{ return String;}

    protected:
        // Przechowuje litera³ napisowy
        WartoscString _wartosc;
};

#endif
