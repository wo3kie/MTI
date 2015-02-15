// Version 1.0

#ifndef _INSTRUKCJE_IO_H_
#define _INSTRUKCJE_IO_H_

#include "instruction.h"

// Reprezentuje instrukcj� drukowania
class InstrukcjaDrukowania:public Instrukcja {
    public:
        // Konstruktor przyjmuje wyra�enie kt�re b�dzi drukowane oraz numer linii
        // w kt�rej wyst�pi�a instrukcja
        InstrukcjaDrukowania(Wyrazenie* __wyrazenie, int __numerLinii)
        :Instrukcja( Void, __numerLinii),
        _wyrazenie( __wyrazenie) {
        }

        // Wykonuje instrukcj�
        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            return _wyrazenie->execute( __runTimeData)->printf();
        }

        // Przechodzi przez drzewo sk�adniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan� zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){
            _wyrazenie->analise( __analysisData);
        }

        // Zwraca typ instrukcji
        virtual Typ typ()const{ return Void;}

    protected:
        // Wyra�enie kt�rego warto�c b�dzie wydrukowana
        Wyrazenie* _wyrazenie;
};

// Reprezentuje instrukcj� przej�cia do nowej linii
class InstrukcjaEndl:public InstrukcjaDrukowania {
    public:
        // Konstruktor przyjmuje numer linii w kt�rej wyst�pi�a instrukcja
        inline InstrukcjaEndl(int __numerLinii):InstrukcjaDrukowania( 0x00, __numerLinii) {}

        // Wykonuje instrukcj�
        virtual const Wartosc* execute( RunTimeData& __runTimeData) {
            std::cout<< std::endl;
            return 0x00;
        }

        // Przechodzi przez drzewo sk�adniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan� zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData) {}
};

// Reprezentuje instrukcj� wczytywania
class InstrukcjaWczytywania:public Instrukcja {
    public:
        InstrukcjaWczytywania( Identyfikator* __identyfikator, int __numerLinii)
        :Instrukcja( Void, __numerLinii),
        _identyfikator( __identyfikator) {
        }

        // Wykonuje instrukcj�
        const Wartosc* execute( RunTimeData& __runTimeData){
            return _identyfikator->assign( __runTimeData)->scanf();
        }

        // Przechodzi przez drzewo sk�adniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan� zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData) {
            _identyfikator->analise( __analysisData);
        }

        // Zwraca typ instrukcji
        virtual Typ typ()const{ return Void;}

    protected:
        // Identyfikator do kt�rego b�dziemy wpisywac wczytan� warto�c
        Identyfikator* _identyfikator;
};

#endif
