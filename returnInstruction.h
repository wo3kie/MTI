// Version 1.0

#ifndef _INSTRUKCJA_SKOKU_RETURN_H_
#define _INSTRUKCJA_SKOKU_RETURN_H_

#include "expression.h"

// Instrukcja ta nie koñczy dzia³ania funkcji. Okreœla jak¹ wartoœc zwróci funkcja.
// Je¿eli w funkcji u¿yjemy instrukcji return wielokrotnie, funkcja zwróci wartoœc
// wyliczon¹ w ostatniej instrukcji return.
//   Przyk³ad:
//      double funkcja(){
//         return 1;
//         return 2;
//     }
//
//     Funkcja zwróci wartoœc 2
class InstrukcjaSkokuReturn: public Instrukcja{
    public:
        // Konstruktor przyjmuje wyra¿enie którego wartoœc zwróci,
        // oraz numer linii w której wyst¹pi³a instrukcja
        InstrukcjaSkokuReturn( Wyrazenie* __wyrazenie, int __numerLinii)
        // Zmienna 'return' jest pierwszym wpisem w lokalnej tablicy zmiennych
        // i przechowuje zwracan¹ wartoœc
        :Instrukcja( Void, __numerLinii),
        _wyrazenie(__wyrazenie){
        }

        // Kopiuje do pierwszej pozycji lokalnej tablicy symboli wartoœc wyrazenia
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

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // która przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan¹ zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){
            _wyrazenie->analise( __analysisData);
        }

    protected:
        // Wyra¿enie po s³owie kluczowym 'return'
        Wyrazenie* _wyrazenie;
};

#endif
