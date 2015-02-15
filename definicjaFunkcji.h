// Version 2.0

#ifndef _DEFINICJA_FUNKCJI_H_
#define _DEFINICJA_FUNKCJI_H_

#include "instrukcjaZlozona.h"
#include "listaDeklaracji.h"
#include "listaParametrow.h"
#include "listaWyrazen.h"

#include <stack>

/// 'RekordAktywacji' jest interfejsem funkcji. Aby wywolac funkcj�, musimy
/// jako parametr przekazac jej rekord aktywacji.
/// 'Rekord aktywacji' zawiera informacje o typach zwracanych i przyjmowanych
/// przez funkcj�, oraz wartosci przyjmowane i zwracane przez funkcje.
/// Ka�da funkcja ma sw�j indywidualny rekord aktywacji.
/// Rekord aktywacji tworzy metoda DefinicjaFunkcji::rekordAktywacji.

struct RekordAktywacji {
    /// Konstruktor przyjmuje nazwe funkcji, wartosc zwracana oraz liste parametrow
    RekordAktywacji( const std::string __nazwaFunkcji, Wartosc* __wartoscZwracana)
    :nazwaFunkcji( __nazwaFunkcji),
    wartoscZwracana( __wartoscZwracana){}

    /// Nazwa funkcji
    const std::string nazwaFunkcji;

    /// Wartosc zwracana
    Wartosc* wartoscZwracana;

    /// Wartosci arguentow
    std::vector< Wartosc*> listaWartosci;
};

/// Reprezentuje funkcje ktora zaimplementowal uzytkownik
class DefinicjaFunkcji:public Wezel{
    public:
        /// Konstruktor przyjmuje wartosc zwracana, nazwe funkcji, lista parametrow,
        /// instrukcje (tresc funkcji) oraz numer linii w ktorej rozpoczela sie definicja funkcji
        DefinicjaFunkcji( Wartosc*__wartosc, std::string __identyfikator,
            ListaParametrow*__listaParametrow, Instrukcja*__instrukcja,int __numerLinii);

        /// Wykonuje funkcje
        virtual const Wartosc* execute( RunTimeData& __runTimeData);

        /// Analizuje funkcje
        virtual void analise( AnalysisData& __analysisData);

        /// Tworzy rekord aktywacji funkcji
        virtual RekordAktywacji& rekordAktywacji(){ return _rekordAktywacji;}

    protected:
        /// Rekord aktywacji funkcji
        RekordAktywacji _rekordAktywacji;

        /// Lista parametrow
        ListaParametrow* _listaParametrow;

        /// Instrukcja, tresc funkcji
        Instrukcja* _instrukcja;

        /// Tablica zmiennych lokalnych
        TablicaZmiennych _tablicaZmiennychLokalnych;

        /// Stos widocznosci, sluzy sledzeniu zasiegow
        std::stack<int> _stosWidocznosci;

        /// Stos wywolan funkcji
        // Kazde wywolanie funkcji jest osobnym obiektem. Zeby nie nadpisywac wartosci
        // zmiennych z poprzedniego wywolania, musza byc one zapamietane.
        // Wykorzystywane przy funkcjach rekurencyjnych
        /* PRZYKLAD

        double silnia( double liczba){
            if( liczba== 0){
                return 1;
            }
            else{
                return silnia( liczba- 1);  // W tym miejscu musimy zapamietac wartosc
            }                               // parametru 'liczba'
        }

        */
        std::stack< TablicaZmiennych> _stosWywolanFunkcji;
};

/* ========================================================= DefinicjaFunkcji */
inline DefinicjaFunkcji::DefinicjaFunkcji( Wartosc* __wartosc,std::string __identyfikator,ListaParametrow* __listaParametrow,Instrukcja* __instrukcja,int __numerLinii)
:Wezel( Void, __numerLinii),
_rekordAktywacji( __identyfikator, __wartosc),
_listaParametrow( __listaParametrow),
_instrukcja( __instrukcja) {
    //std::cout<<"KO2: "<<_listaParametrow->size()<<std::endl;
}

/* ================================================================== analise */
inline void DefinicjaFunkcji::analise( AnalysisData& __analysisData) {
    // tworzy dane analizy
    __analysisData.numerBloku= Zasieg::zasiegParametrow;
    __analysisData.stosWidocznosci= &_stosWidocznosci;
        _stosWidocznosci.push( __analysisData.numerBloku /* zasiegParametrow*/);
    __analysisData.tablicaZmiennychLokalnych= &_tablicaZmiennychLokalnych;

    // tworzy rekord aktywacji
    for( int parametr= 0; parametr< (int)_listaParametrow->size(); ++parametr){
        _rekordAktywacji.listaWartosci.push_back( (*_listaParametrow)[ parametr]->execute(*new RunTimeData())->kopiuj());
    }

    // dodaje funkcje (sama siebie) do tablicy funkcji
    __analysisData.tablicaFunkcji->insert( _rekordAktywacji.nazwaFunkcji, this, Zasieg::zasiegGlobalny);

    // dodaje wartosc zwracana do tablicy symboli
    _tablicaZmiennychLokalnych.insert( "return", _rekordAktywacji.wartoscZwracana, Zasieg::zasiegParametrow);

    // dodaje parametry do tablicy symboli
    // parametr dodaje sam siebie do lokalnej tablicy symboli
    _listaParametrow->analise( __analysisData);

    // analizuje w glab drzewo skladniowe
    _instrukcja->analise( __analysisData);

    // okresla typ wartosci zwracanej
    _typ= _rekordAktywacji.wartoscZwracana->typ();
}

/* ================================================================== execute */
inline const Wartosc* DefinicjaFunkcji::execute( RunTimeData& __runTimeData) {
    // tworzy nowa tablice symboli i wklada ja na stos wywolan funkcji
    _stosWywolanFunkcji.push( _tablicaZmiennychLokalnych);

    // tworzy dane wykonywania
    __runTimeData.rekordAktywacji= &_rekordAktywacji;
    __runTimeData.tablicaZmiennychLokalnych= &_stosWywolanFunkcji.top();

    // kopiuje wartosci parametrow do lokalnej tablicy symboli
    for( unsigned parametr= 0; parametr< _rekordAktywacji.listaWartosci.size(); ++parametr){
    // '::kopiuj' obiekt klasy 'OperatorPrzypisania' - plik 'operatory.h'
        Operatory::kopiuj( _stosWywolanFunkcji.top().value( Zasieg::zasiegParametrow, parametr+1),
            _rekordAktywacji.listaWartosci[ parametr]);
    }

    // wykonuje funkcje
    _instrukcja->execute( __runTimeData);

    // '::kopiuj' obiekt klasy 'OperatorPrzypisania' - plik 'operatory.h'
    // kopiuje wartosc zwracana z tablicy symboli do rekordu aktywacji

    /*
        wartosc zwracana przez funkcje znajduje sie w lokalnej tablicy symboli na pierwszej pozycji.
        jezeli w tresci funkcji pojawi sie instrukcja 'return', kopiuje ona wartosc wyrazenia
        ktore za nia stoi do lokalnej tablicy symboli na pierwsza pozycje.
        kiedy funkcja sie konczy wartosc zwracana musi zostac skopiowana z lokalnej tablicy symboli
        z pierwszej pozycji do rekordu aktywacji - ktory jest interfejsem funkcji
    */

    Operatory::kopiuj( _rekordAktywacji.wartoscZwracana,
        _stosWywolanFunkcji.top().value( Zasieg::zasiegParametrow, Zasieg::pozycjaReturn)
    );

    // zdejmuje tablice symboli ze stosu
    _stosWywolanFunkcji.pop();

    return 0x00;
}

#endif
