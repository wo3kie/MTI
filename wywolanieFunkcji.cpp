// Version 1.0

#include "wywolanieFunkcji.h"

/* ================================================================== execute */
const Wartosc* WywolanieFunkcji::execute(RunTimeData& __runTimeData){
    // kopiuje wartosci parametrow do rekordu aktywacji
    RekordAktywacji& rekordAktywacji=
        __runTimeData.tablicaFunkcji->value( Zasieg::zasiegGlobalny, _pozycja)->rekordAktywacji();

    for( unsigned parametr= 0; parametr< _listaWyrazen->size(); ++parametr){
        Operatory::kopiuj( rekordAktywacji.listaWartosci[ parametr],
            (*_listaWyrazen)[ parametr]->execute( __runTimeData)
        );
    }

    TablicaZmiennych* tymczasowa= __runTimeData.tablicaZmiennychLokalnych;

    // uruchamia funkcje
    __runTimeData.tablicaFunkcji->value( Zasieg::zasiegGlobalny, _pozycja)->execute( __runTimeData);

    __runTimeData.tablicaZmiennychLokalnych= tymczasowa;

    return rekordAktywacji.wartoscZwracana;
}

/* ================================================================== analise */
void WywolanieFunkcji::analise( AnalysisData& __analysisData){
    // znajduje funkcje w tablicy funkcji
    try{
        _pozycja= __analysisData.tablicaFunkcji->find( _identyfikator, Zasieg::zasiegGlobalny);   // 0 bo zasieg globalny
    }
    catch( const UndefinedSymbol& __error){
        throw UndefinedSymbol( std::string("Cannot find function: '")+ _identyfikator+ std::string("'"));
    }

    // pobieramy rekord aktywacji
    RekordAktywacji& rekordAktywacji= __analysisData.tablicaFunkcji->value( 0, _pozycja)->rekordAktywacji();

    // sprawdzam czy zgadza sie ilosc parametrow oraz ich typy
    if( _listaWyrazen->size()!= rekordAktywacji.listaWartosci.size()){

        std::cout<<"LW: "<<_listaWyrazen->size()<<std::endl
            <<"RA: "<<rekordAktywacji.listaWartosci.size()<<std::endl;

        throw CannotCallFunction( _identyfikator);
    }

    for( unsigned parametr=0; parametr< _listaWyrazen->size(); ++parametr){
        // Analizujemy wyrazenia
        _listaWyrazen->analise( __analysisData);

        if( (*_listaWyrazen)[ parametr]->typ()!= rekordAktywacji.listaWartosci[ parametr]->typ()){
            throw CannotCallFunction( _identyfikator);
        }
    }

    // obliczam jaki typ zwroci funkcja
    _typ= rekordAktywacji.wartoscZwracana->typ();
}
