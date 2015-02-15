// Version 1.0

#ifndef _INSTRUKCJA_SKOKU_RETURN_H_
#define _INSTRUKCJA_SKOKU_RETURN_H_

#include "expression.h"

// Instrukcja ta nie ko�czy dzia�ania funkcji. Okre�la jak� warto�c zwr�ci funkcja.
// Je�eli w funkcji u�yjemy instrukcji return wielokrotnie, funkcja zwr�ci warto�c
// wyliczon� w ostatniej instrukcji return.
//   Przyk�ad:
//      double funkcja(){
//         return 1;
//         return 2;
//     }
//
//     Funkcja zwr�ci warto�c 2
class InstrukcjaSkokuReturn: public Instrukcja{
    public:
        // Konstruktor przyjmuje wyra�enie kt�rego warto�c zwr�ci,
        // oraz numer linii w kt�rej wyst�pi�a instrukcja
        InstrukcjaSkokuReturn( Wyrazenie* __wyrazenie, int __numerLinii)
        // Zmienna 'return' jest pierwszym wpisem w lokalnej tablicy zmiennych
        // i przechowuje zwracan� warto�c
        :Instrukcja( Void, __numerLinii),
        _wyrazenie(__wyrazenie){
        }

        // Kopiuje do pierwszej pozycji lokalnej tablicy symboli warto�c wyrazenia
        virtual const Wartosc* execute(RunTimeData& __runTimeData){
            // '::kopiuj' obiekt klasy 'OperatorPrzypisania' - plik operators.h

            // Wartosc zwracana jest zawsze w pierwszym zasiegu funkcji na samym poczatku
            // _pozycja( 1, 0)  -   zasieg 0 jest zarezerwowany dla zasiegu globalnego
            Operatory::kopiuj( __runTimeData.tablicaZmiennychLokalnych->value(
                    Zasieg::zasiegParametrow, Zasieg::pozycjaReturn
                ),
                _wyrazenie->execute( __runTimeData)
            );

            return 0x00;
        }

        // Przechodzi przez drzewo sk�adniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan� zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){
            _wyrazenie->analise( __analysisData);
        }

    protected:
        // Wyra�enie po s�owie kluczowym 'return'
        Wyrazenie* _wyrazenie;
};

#endif
