// Version 1.0

#ifndef _LITERAL_NAPISOWY_H_
#define _LITERAL_NAPISOWY_H_

#include "czynnik.h"

// Reprezentuje litera� napisowy
// Litera� napisowy jest ci�giem znak�w zawartych pomi�dzy cudzys�owami
// Litera� napisowy nie mo�e byc dlu�szy ni� jedna linia
class LiteralNapisowy: public Czynnik{
    public:
        // Konstruktor przyjmuje warto�c litera�u napisowego
        // oraz numer linii w kt�rej on wyst�pi�
        // Usuwa cudzys��w z napis�w.: "kasia" -> kasia
        inline LiteralNapisowy(const std::string& __napis, int __numerLinii)
        :Czynnik( String, __numerLinii),
        _wartosc(__napis.substr( 1, __napis.size()- 2)){
        }

        // Zwraca litera� napisowy
        virtual const Wartosc* execute(RunTimeData& _runTimeData){ return &_wartosc;}

        // Analizuje litera� napisowy
        virtual void analise(AnalysisData&){
            // Ta klasa jest li�ciem drzewa sk�adniowego. Metoda 'analise' nie robi nic.
            // Na niej ko�czy si� przechodzenie drzewa sk�adniowego 'w gl�b'.
        }

        // Zwraca typ litera�u. Zawsze jest to string
        virtual Typ typ()const{ return String;}

    protected:
        // Przechowuje litera� napisowy
        WartoscString _wartosc;
};

#endif
