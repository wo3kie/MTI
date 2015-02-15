// Version 1.0

#ifndef _IDENTYFIKATOR_H_
#define _IDENTYFIKATOR_H_

#include <cassert>

#include "factor.h"
#include "symbolTable.h"

// Reprezentuje identyfikator, zmienn¹ w programie uzytkownika
class Identyfikator:public Czynnik{
    public:
        // Konstruktor przyjmuje nazwê zmiennej oraz numer linii
        // w której wyst¹pi³a zmienna
        Identyfikator(std::string __identyfikator, int __numerLinii)
        :Czynnik( Void, __numerLinii),
        _identyfikator( __identyfikator){
        }

        virtual ~Identyfikator(){}

        // Klasa nie jest abstrakcyjna
        virtual const Wartosc* execute( RunTimeData& _runTimeData)=0;
        virtual Wartosc* assign( RunTimeData& _runTimeData)=0;

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // ktora przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowana zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData)=0;

        // Zwraca typ
        virtual Typ typ()const{ return _typ;}

    protected:
        // Nazwa zmiennej
        std::string _identyfikator;

        // TablicaSymboli
        TablicaZmiennych* _tablicaZmiennych;

        std::pair<unsigned,unsigned> _pozycja;    // pozycja.first - zasieg; pozycja.second - pozycja w zasiegu

        // Typ zmiennej
        Typ _typ;
};

// Reprezentuje zmienne lokalne w programie uzytkownika
class ZmiennaLokalna: public Identyfikator{
    public:
        // Konstruktor przyjmuje nazwê zmiennej oraz numer linii
        // w której wyst¹pi³a zmienna
        ZmiennaLokalna( std::string __identyfikator, int __numerLinii)
        :Identyfikator( __identyfikator, __numerLinii){
        }

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // ktora przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowana zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){

            // Tworzymy kopie stosu widocznosci, zeby nie zmodyfikowac oryginalu
            std::stack<int> stosWidocznosci( *__analysisData.stosWidocznosci);

            // Przeszukujemy najpierw lokalne tablice symboli. Jezeli nie znajdziemy tam
            // poszukiwanej zmiennej szukamy w globalnej tablicy symboli.
            // Jezeli nie uda nam sie odnalezc zmiennej zglaszamy wyjatek 'UndefinedSymbol'

            while( !stosWidocznosci.empty()){   // Przeszukujemy zasiegi w ktorych jestesmy
                try{
                    _pozycja= std::make_pair(
                        stosWidocznosci.top(),
                        __analysisData.tablicaZmiennychLokalnych->find(
                            _identyfikator,
                            stosWidocznosci.top()
                        )
                    );
                }
                catch( const UndefinedSymbol& __error){
                    stosWidocznosci.pop();
                    continue;
                }

                _typ= __analysisData.tablicaZmiennychLokalnych->value( _pozycja)->typ();
                return;
            }

            try{
                _pozycja= std::make_pair( 0,
                    __analysisData.tablicaZmiennychGlobalnych->find( _identyfikator, 0)
                );
            }
            catch( const UndefinedSymbol& __error){
                throw UndefinedSymbol( std::string("Undefined symbol: ")+ _identyfikator);
            }

            _typ= __analysisData.tablicaZmiennychGlobalnych->value( _pozycja)->typ();
        }

        // Zwraca r-wartosc
        virtual const Wartosc* execute( RunTimeData& __runTimeData){

            // Zasieg globalny ma wartosc '0'. Jezeli pole '_pozycja.first' ma
            // wartosc 0 oznacza to, ze jest to zmienna globalna

            return _pozycja.first ? __runTimeData.tablicaZmiennychLokalnych->value( _pozycja)
                : __runTimeData.tablicaZmiennychGlobalnych->value( _pozycja);
        }

        // Uzywane przez 'operator=' do przypisania wartoœci
        virtual Wartosc* assign( RunTimeData& __runTimeData){
            return _pozycja.first ? __runTimeData.tablicaZmiennychLokalnych->value( _pozycja)
                : __runTimeData.tablicaZmiennychGlobalnych->value( _pozycja);
        }
};

class ZmiennaGlobalna:public Identyfikator{
    public:
        // Konstruktor przyjmuje nazwê zmiennej oraz numer linii
        // w której wyst¹pi³a zmienna
        ZmiennaGlobalna( std::string __identyfikator, int __numerLinii)
        :Identyfikator( __identyfikator, __numerLinii){
        }

        // Destruktor
        virtual ~ZmiennaGlobalna(){}

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // ktora przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowana zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){
            _pozycja= std::make_pair( Zasieg::zasiegGlobalny,
                __analysisData.tablicaZmiennychGlobalnych->find( _identyfikator, Zasieg::zasiegGlobalny)
            );

            _typ= __analysisData.tablicaZmiennychGlobalnych->value( _pozycja)->typ();
        }

        // Zwraca r-wartosc
        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            return __runTimeData.tablicaZmiennychGlobalnych->value( _pozycja);
        }

        // Uzywane przez 'operator=' do przypisania wartoœci
        virtual Wartosc* assign( RunTimeData& __runTimeData){
            return __runTimeData.tablicaZmiennychGlobalnych->value( _pozycja);
        }
};

#endif
