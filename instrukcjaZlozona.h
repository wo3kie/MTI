// Version 1.0

#ifndef _INSTRUKCJA_ZLOZONA_H_
#define _INSTRUKCJA_ZLOZONA_H_

#include "listaInstrukcji.h"

// Reprezentuje instrukcje zlo¿ona. Instrukcja zlo¿¿ona jest to instrukcja zawarta w klamrach '{' i '}'
class InstrukcjaZlozona:public Instrukcja{
    public:
        // Konstruktor przyjmuje liste instrukcji oraz numer linii w której zaczynaj¹ siê
        // instrukcje
        InstrukcjaZlozona(ListaInstrukcji* __instrukcje, int __numerLinii)
        :Instrukcja( Void, __numerLinii),
        _listaInstrukcji(__instrukcje){
        }

        // Wykonuje instrukcje zlozona
        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            _listaInstrukcji->execute( __runTimeData);
            return 0x00;
        }

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // która przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan¹ zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){
            __analysisData.stosWidocznosci->push( ++__analysisData.numerBloku);
            /*
            Wchodzac do zasiegu inkrementujemy wartosc __analysisData.numerBloku,
            wychodzac dekrementujemy

            {   // ++__analysisData.numerBloku

            }   // --__analysisData.numerBloku

            */

            /*
            // zasieg globalny ma wartosc 0          Stos: 0 <- wierzcholek

            { // poczatek zasiegu 1                  Stos : 0 1 <- wierzcholek

            } // koniec zasiegu 1                    Stos: 0 <- wierzcholek
            { // poczatek zasiegu 2                  Stos: 0 2 <- wierzcholek
                { // poczatek zasiegu 3              Stos: 0 2 3 <- wierzcholek

                } // koniec zasiegu 3                Stos: 0 2 <- wierzcholek
            } // koniec zasiegu 2                    Stos: 0 <- wierzcholek

            */

            _listaInstrukcji->analise( __analysisData);

            __analysisData.stosWidocznosci->pop();
        }

    private:
        int _numerBloku;

        // Lista instrukcji
        ListaInstrukcji* _listaInstrukcji;
};

#endif
