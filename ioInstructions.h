// Version 1.0

#ifndef _INSTRUKCJE_IO_H_
#define _INSTRUKCJE_IO_H_

#include "instruction.h"

// Reprezentuje instrukcjê drukowania
class InstrukcjaDrukowania:public Instrukcja {
    public:
        // Konstruktor przyjmuje wyra¿enie które bêdzi drukowane oraz numer linii
        // w której wyst¹pi³a instrukcja
        InstrukcjaDrukowania(Wyrazenie* __wyrazenie, int __numerLinii)
        :Instrukcja( Void, __numerLinii),
        _wyrazenie( __wyrazenie) {
        }

        // Wykonuje instrukcjê
        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            return _wyrazenie->execute( __runTimeData)->printf();
        }

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // która przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan¹ zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){
            _wyrazenie->analise( __analysisData);
        }

        // Zwraca typ instrukcji
        virtual Typ typ()const{ return Void;}

    protected:
        // Wyra¿enie którego wartoœc bêdzie wydrukowana
        Wyrazenie* _wyrazenie;
};

// Reprezentuje instrukcjê przejœcia do nowej linii
class InstrukcjaEndl:public InstrukcjaDrukowania {
    public:
        // Konstruktor przyjmuje numer linii w której wyst¹pi³a instrukcja
        inline InstrukcjaEndl(int __numerLinii):InstrukcjaDrukowania( 0x00, __numerLinii) {}

        // Wykonuje instrukcjê
        virtual const Wartosc* execute( RunTimeData& __runTimeData) {
            std::cout<< std::endl;
            return 0x00;
        }

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // która przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan¹ zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData) {}
};

// Reprezentuje instrukcjê wczytywania
class InstrukcjaWczytywania:public Instrukcja {
    public:
        InstrukcjaWczytywania( Identyfikator* __identyfikator, int __numerLinii)
        :Instrukcja( Void, __numerLinii),
        _identyfikator( __identyfikator) {
        }

        // Wykonuje instrukcjê
        const Wartosc* execute( RunTimeData& __runTimeData){
            return _identyfikator->assign( __runTimeData)->scanf();
        }

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // która przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan¹ zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData) {
            _identyfikator->analise( __analysisData);
        }

        // Zwraca typ instrukcji
        virtual Typ typ()const{ return Void;}

    protected:
        // Identyfikator do którego bêdziemy wpisywac wczytan¹ wartoœc
        Identyfikator* _identyfikator;
};

#endif
