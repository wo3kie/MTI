// Version 1.0

#ifndef _WYWOLANIE_FUNKCJI_H_
#define _WYWOLANIE_FUNKCJI_H_

#include "definicjaFunkcji.h"

/// Reprezentuje wywolanie funkcji
class WywolanieFunkcji:public Czynnik{
    public:
        /// Konstruktor przyjmuje identyfikator wywo�ywanej funkcji, list� wyra�e� oraz numer linii
        WywolanieFunkcji( std::string __identyfikator, ListaWyrazen* __listaWyrazen, int __numerLinii)
        :Czynnik( Void, __numerLinii),
        _listaWyrazen( __listaWyrazen),
        _identyfikator( __identyfikator){
        }

        /// Sprawdza czy ilo�c oraz typy argument�w funkcji i parametr�w wywo�ania s� zgodne
        virtual void analise( AnalysisData& __analysisData);

        /// Wywo�uje funkcj�
        virtual const Wartosc* execute( RunTimeData& _runTimeData);

    private:
        /// Wyra�enia w wywo�aniu funkcji
        ListaWyrazen* _listaWyrazen;

        std::string _identyfikator;
        unsigned _pozycja;
};

#endif
