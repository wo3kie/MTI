// Version 1.0

#include "funkcjeBiblioteczne.h"
#include "parametryWywolania.h"
    extern Parametry parametry;
#include "program.h"
#include "wywolanieFunkcji.h"

void Program::dodajFunkcjeBiblioteczne(){
    _tablicaFunkcji.insert( "cos", &FunkcjeBiblioteczne::cos, Zasieg::zasiegGlobalny);
    _tablicaFunkcji.insert( "sin", &FunkcjeBiblioteczne::sin, Zasieg::zasiegGlobalny);
    _tablicaFunkcji.insert( "sqrt", &FunkcjeBiblioteczne::sqrt, Zasieg::zasiegGlobalny);
    _tablicaFunkcji.insert( "rad", &FunkcjeBiblioteczne::rad, Zasieg::zasiegGlobalny);
    _tablicaFunkcji.insert( "pi", &FunkcjeBiblioteczne::pi, Zasieg::zasiegGlobalny);
    _tablicaFunkcji.insert( "pow", &FunkcjeBiblioteczne::pow, Zasieg::zasiegGlobalny);
    _tablicaFunkcji.insert( "_printf", &FunkcjeBiblioteczne::_printf, Zasieg::zasiegGlobalny);
    _tablicaFunkcji.insert( "_scanf", &FunkcjeBiblioteczne::_scanf, Zasieg::zasiegGlobalny);
    _tablicaFunkcji.insert( "_read", &FunkcjeBiblioteczne::_read, Zasieg::zasiegGlobalny);
    _tablicaFunkcji.insert( "_parseDouble", &FunkcjeBiblioteczne::_parseDouble, Zasieg::zasiegGlobalny);
}

void Program::analise() {
    dodajFunkcjeBiblioteczne();

    // tworze strukture z danymi wykorzystywanymi podczas analizy
    AnalysisData analysisData;

    analysisData.liczbaBledow= 0;
    analysisData.numerBloku= Zasieg::zasiegGlobalny;

    analysisData.stosWidocznosci= new std::stack<int>;
        // jestesmy w zasiegu globalnym, zasieg 0
        analysisData.stosWidocznosci->push( Zasieg::zasiegGlobalny);

    analysisData.tablicaFunkcji= &_tablicaFunkcji;
    analysisData.tablicaZmiennychGlobalnych= &_tablicaZmiennychGlobalnych;
    analysisData.tablicaZmiennychLokalnych= 0x00;

    // dodaje zmienne globalne to globalnej tablicy symboli
    if( _listaDeklaracji){
        // w globalnym zasiegu globalna tablice jest lokalna :o)
        // deklaracja dodaje sie do lokalnej tablicy symboli

        analysisData.tablicaZmiennychLokalnych= &_tablicaZmiennychGlobalnych;

        _listaDeklaracji->analise( analysisData);

        analysisData.tablicaZmiennychLokalnych= 0x00; // wraca do poczatkowego ustawienia
    }

    // analizujemy funkcje programu
    _listaFunkcji->analise( analysisData);

    // sprawdzamy, czy analiza zakonczyla sie bezblednie
    if( analysisData.liczbaBledow!= 0){
        throw IException("Cannot run program becouse of error(s)");
    }

    _analizowany= true;
}

const Wartosc* Program::execute() {

    WywolanieFunkcji* start=new WywolanieFunkcji( _funkcjaGlowna, 0x00, 0);

    // tworze strukture z danymi wykorzystywanymi podczas wykonywania
    RunTimeData runTimeData;

    runTimeData.tablicaFunkcji= &_tablicaFunkcji;
    runTimeData.tablicaZmiennychGlobalnych= &_tablicaZmiennychGlobalnych;
    runTimeData.tablicaZmiennychLokalnych= 0x00;

    // sprawdzamy czy program byl juz analizowany
    if( !_analizowany){
        analise();
    }

    // szukamy funkcji glownej
    int funkcjaGlownaPozycja;
    try{
        funkcjaGlownaPozycja= _tablicaFunkcji.find( _funkcjaGlowna, Zasieg::zasiegGlobalny);
    }
    catch( const UndefinedSymbol& __error){
        throw UndefinedSymbol( std::string("Cannot find '")+ _funkcjaGlowna+ std::string("' function"));
    }

    // pobieram rekord aktywacji funkcj glownej
    runTimeData.rekordAktywacji=
        &_tablicaFunkcji.value( std::make_pair( Zasieg::zasiegGlobalny, funkcjaGlownaPozycja))->rekordAktywacji();

    // kopiuje tablice wartosci ktora jest parametrem wywolania
    // do rekordu aktywacji
    runTimeData.rekordAktywacji->listaWartosci= parametry.argv;

    if( runTimeData.rekordAktywacji->listaWartosci.size()!= parametry.argv.size()){
        throw IException(std::string("Cannot call function: ")+ _funkcjaGlowna);
    }

    for( int parametr= 0; parametr< runTimeData.rekordAktywacji->listaWartosci.size(); ++parametr){
        if( runTimeData.rekordAktywacji->listaWartosci[ parametr]->typ()!=
        parametry.argv[ parametr]->typ()){
            throw IException(std::string("Cannot call function: ")+ _funkcjaGlowna);
        }
    }

    _tablicaFunkcji.value( std::make_pair( Zasieg::zasiegGlobalny, funkcjaGlownaPozycja))->execute( runTimeData);

    return 0x00;
}

