// Version 4.0

#ifndef _TABLICA_SYMBOLI_H_
#define _TABLICA_SYMBOLI_H_
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>

#include "value.h"

class DefinicjaFunkcji;

template< typename T>
class Tablica{
    public:
        typedef T value_type;

        Tablica(){}
        virtual ~Tablica(){}

        int size()const{return _tablica.size();}

        virtual int insert( std::string __identyfikator, T* __wartosc, int __zasieg) {
            int pozycja=0;

            for( int a=0; a<(int) _tablica.size(); ++a){
                if( _tablica[a].zasieg== __zasieg){
                    ++pozycja;
                    if( _tablica[a].identyfikator== __identyfikator){
                        throw MultipleDeclaration( __identyfikator);
                    }
                }
            }

            _tablica.push_back( _Symbol(__identyfikator, __wartosc, __zasieg, pozycja));
            return pozycja;
        }

        virtual int find( std::string __identyfikator, int __zasieg) const {
            for( int a=0; a<(int) _tablica.size(); ++a){
                if( _tablica[a].identyfikator== __identyfikator && _tablica[a].zasieg== __zasieg){
                    return _tablica[a].pozycja;
                }
            }

            throw UndefinedSymbol( __identyfikator);
        }

        virtual T* value(int __zasieg, int __pozycja) {
            for( int a=0; a<(int) _tablica.size(); ++a){

                if( _tablica[a].zasieg== __zasieg && _tablica[a].pozycja== __pozycja){
                    return _tablica[a].wartosc;
                }
            }
            
            return 0x00;
        }

        virtual T* value( const std::pair<int,int> __pozycja){
            return value( __pozycja.first, __pozycja.second);
        }

    protected:
        struct _Symbol{
            _Symbol( std::string __identyfikator, T* __wartosc, int __zasieg, int __pozycja)
            :identyfikator( __identyfikator),wartosc( __wartosc), zasieg( __zasieg), pozycja( __pozycja){}

            _Symbol()
            :identyfikator(""),wartosc(0),zasieg(0),pozycja(0){}

            std::string identyfikator;
            T* wartosc;
            int zasieg;
            int pozycja;
        };

        std::vector< _Symbol> _tablica;
};

class TablicaFunkcji:public Tablica< DefinicjaFunkcji>{
    public:
        TablicaFunkcji(){}
        virtual ~TablicaFunkcji(){}

    private:
// nie mozna kopiowac
    TablicaFunkcji( const TablicaFunkcji&);
    const TablicaFunkcji operator=( const TablicaFunkcji&);
};

class TablicaZmiennych:public Tablica< Wartosc>{
    public:
        TablicaZmiennych(){}

        virtual ~TablicaZmiennych(){}

        TablicaZmiennych( const TablicaZmiennych& __tablica){
            _kopiuj( __tablica);
        }

        const TablicaZmiennych& operator=(const TablicaZmiennych& __tablica){
            _kopiuj( __tablica);
            return *this;
        }

    private:
        void _kopiuj( const TablicaZmiennych& __tablica){
            _tablica.resize( __tablica.size());

            for( int a=0; a< (int)__tablica.size(); ++a){
                _tablica[a].identyfikator= __tablica._tablica[a].identyfikator;
                _tablica[a].wartosc= __tablica._tablica[a].wartosc->kopiuj();
                _tablica[a].zasieg= __tablica._tablica[a].zasieg;
                _tablica[a].pozycja= __tablica._tablica[a].pozycja;
            }
        }
};

namespace Zasieg{
    const int zasiegGlobalny= 0;
    const int zasiegParametrow= 1;
    const int pozycjaReturn= 0;
}

#endif
