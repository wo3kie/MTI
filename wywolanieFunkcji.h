// Version 1.0

#ifndef _WYWOLANIE_FUNKCJI_H_
#define _WYWOLANIE_FUNKCJI_H_

#include "definicjaFunkcji.h"

/// Reprezentuje wywolanie funkcji
class WywolanieFunkcji:public Czynnik{
    public:
        /// Konstruktor przyjmuje identyfikator wywo³ywanej funkcji, listê wyra¿eñ oraz numer linii
        WywolanieFunkcji( std::string __identyfikator, ListaWyrazen* __listaWyrazen, int __numerLinii)
        :Czynnik( Void, __numerLinii),
        _listaWyrazen( __listaWyrazen),
        _identyfikator( __identyfikator){
        }

        /// Sprawdza czy iloœc oraz typy argumentów funkcji i parametrów wywo³ania s¹ zgodne
        virtual void analise( AnalysisData& __analysisData);

        /// Wywo³uje funkcjê
        virtual const Wartosc* execute( RunTimeData& _runTimeData);

    private:
        /// Wyra¿enia w wywo³aniu funkcji
        ListaWyrazen* _listaWyrazen;

        std::string _identyfikator;
        unsigned _pozycja;
};

#endif
