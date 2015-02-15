// libraryFunctions.h v 1.0

#ifndef _FUNKCJE_BIBLIOTECZNE_H_
#define _FUNKCJE_BIBLIOTECZNE_H_

#include "functionDefinition.h"

#include <functional>
#include <math.h>
#include <sstream>

const double M_PI_180= 0.017453292;

// double sin( double )
// double cos( double )
// double sqrt( double )
// double rad( double )
// double pi()

class _Pow:public DefinicjaFunkcji{
    public:
        _Pow():DefinicjaFunkcji(new WartoscDouble(),"pow",new Lista<Parametr>(new Lista<Parametr>(new DeklaracjaDouble("liczba",0,0)),new DeklaracjaDouble("liczba",0,0)),0x00,0){
            // tworzy rekord aktywacji
            for( int parametr= 0; parametr< _listaParametrow->size(); ++parametr){
                _rekordAktywacji.listaWartosci.push_back( (*_listaParametrow)[ parametr]->execute()->kopiuj());
            }
        }

        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            const WartoscDouble* w1= dynamic_cast<const WartoscDouble*>(_rekordAktywacji.listaWartosci[0]);
            const WartoscDouble* w2= dynamic_cast<const WartoscDouble*>(_rekordAktywacji.listaWartosci[1]);

            Operatory::kopiuj(_rekordAktywacji.wartoscZwracana,new WartoscDouble(::pow(w1->execute(),w2->execute())));
            
            return 0x00;
        }
};

class _Printf:public DefinicjaFunkcji{
    public:
        _Printf():DefinicjaFunkcji(new WartoscDouble(),"_printf",new Lista<Parametr>(new DeklaracjaDouble("liczba",0,0)),0x00,0){
            // tworzy rekord aktywacji
            for( int parametr= 0; parametr< (int)_listaParametrow->size(); ++parametr){
                _rekordAktywacji.listaWartosci.push_back( (*_listaParametrow)[ parametr]->execute()->kopiuj());
            }
        }

        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            _rekordAktywacji.listaWartosci[0]->printf();

            Operatory::kopiuj(_rekordAktywacji.wartoscZwracana,new WartoscDouble(1));
        
            return 0x00;
        }
};

class _Scanf:public DefinicjaFunkcji{
    public:
        _Scanf():DefinicjaFunkcji(new WartoscDouble(),"_scanf",new Lista<Parametr>(new DeklaracjaDouble("liczba",0,0)),0x00,0){
            // tworzy rekord aktywacji
            for( int parametr= 0; parametr<(int) _listaParametrow->size(); ++parametr){
                _rekordAktywacji.listaWartosci.push_back( (*_listaParametrow)[ parametr]->execute()->kopiuj());
            }
        }

        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            _rekordAktywacji.listaWartosci[0]->scanf();

            Operatory::kopiuj(_rekordAktywacji.wartoscZwracana,new WartoscDouble(1));
        
            return 0x00;
        }
};

class _Cos:public DefinicjaFunkcji{
    public:
        _Cos():DefinicjaFunkcji(new WartoscDouble(),"cos",new Lista<Parametr>(new DeklaracjaDouble("liczba",0,0)),0x00,0){
            // tworzy rekord aktywacji
            for( int parametr= 0; parametr<(int) _listaParametrow->size(); ++parametr){
                _rekordAktywacji.listaWartosci.push_back( (*_listaParametrow)[ parametr]->execute()->kopiuj());
            }
        }

        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            const WartoscDouble* wartosc= dynamic_cast<const WartoscDouble*>(_rekordAktywacji.listaWartosci[0]);

            Operatory::kopiuj(_rekordAktywacji.wartoscZwracana,new WartoscDouble(::cos(wartosc->execute())));
            
            return 0x00;
        }
};

class _Sin:public DefinicjaFunkcji{
    public:
        _Sin():DefinicjaFunkcji(new WartoscDouble(),"sin",new Lista<Parametr>(new DeklaracjaDouble("liczba",0,0)),0x00,0){
            // tworzy rekord aktywacji
            for( int parametr= 0; parametr<(int) _listaParametrow->size(); ++parametr){
                _rekordAktywacji.listaWartosci.push_back( (*_listaParametrow)[ parametr]->execute()->kopiuj());
            }
        }

        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            const WartoscDouble* wartosc= dynamic_cast<const WartoscDouble*>(_rekordAktywacji.listaWartosci[0]);

            Operatory::kopiuj(_rekordAktywacji.wartoscZwracana,new WartoscDouble(::sin(wartosc->execute())));
            
            return 0x00;
        }
};

class _Sqrt:public DefinicjaFunkcji{
    public:
        _Sqrt():DefinicjaFunkcji(new WartoscDouble(),"sqrt",new Lista<Parametr>(new DeklaracjaDouble("liczba",0,0)),0x00,0){
            // tworzy rekord aktywacji
            for( int parametr= 0; parametr<(int) _listaParametrow->size(); ++parametr){
                _rekordAktywacji.listaWartosci.push_back( (*_listaParametrow)[ parametr]->execute()->kopiuj());
            }
        }

        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            const WartoscDouble* wartosc= dynamic_cast<const WartoscDouble*>(_rekordAktywacji.listaWartosci[0]);

            Operatory::kopiuj(_rekordAktywacji.wartoscZwracana,new WartoscDouble(::sqrt(wartosc->execute())));
            
            return 0x00;
        }
};

class _Rad:public DefinicjaFunkcji{
    public:
        _Rad():DefinicjaFunkcji(new WartoscDouble(),"rad",new Lista<Parametr>(new DeklaracjaDouble("liczba",0,0)),0x00,0){
            // tworzy rekord aktywacji
            for( int parametr= 0; parametr<(int) _listaParametrow->size(); ++parametr){
                _rekordAktywacji.listaWartosci.push_back( (*_listaParametrow)[ parametr]->execute()->kopiuj());
            }
        }

        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            const WartoscDouble* wartosc= dynamic_cast<const WartoscDouble*>(_rekordAktywacji.listaWartosci[0]);

            Operatory::kopiuj(_rekordAktywacji.wartoscZwracana,new WartoscDouble(M_PI_180*wartosc->execute()));
            
            return 0x00;
        }
};

class _Pi:public DefinicjaFunkcji{
    public:
        _Pi():DefinicjaFunkcji(new WartoscDouble(),"pi",0x00,0x00,0){
        }

        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            Operatory::kopiuj(_rekordAktywacji.wartoscZwracana,new WartoscDouble(M_PI));
            
            return 0x00;
        }
};

class _Read:public DefinicjaFunkcji{
    public:
        _Read():DefinicjaFunkcji(new WartoscString(),"read",0x00,0x00,0){
        }

        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            std::string napis;
            std::cin>>napis;

            Operatory::kopiuj(_rekordAktywacji.wartoscZwracana,new WartoscString(napis));
            
            return 0x00;
        }
};

class _ParseDouble:public DefinicjaFunkcji{
    public:
        _ParseDouble():DefinicjaFunkcji(new WartoscDouble(),"parseDouble",new Lista<Parametr>(new DeklaracjaString("napis","",0)),0x00,0){
            // tworzy rekord aktywacji
            for( int parametr= 0; parametr<(int) _listaParametrow->size(); ++parametr){
                _rekordAktywacji.listaWartosci.push_back( (*_listaParametrow)[ parametr]->execute()->kopiuj());
            }
        }

        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            const WartoscString* wartosc= dynamic_cast<const WartoscString*>(_rekordAktywacji.listaWartosci[0]);

            std::istringstream iss(wartosc->execute());
            double liczba;
            iss>>liczba;

            Operatory::kopiuj(_rekordAktywacji.wartoscZwracana,new WartoscDouble(liczba));
        
            return 0x00;
        }
};

namespace FunkcjeBiblioteczne{
    _Cos cos;
    _Sin sin;
    _Sqrt sqrt;
    _Rad rad;
    _Pi pi;
    _Pow pow;
    _Printf _printf;
    _Scanf _scanf;

    _Read _read;
    _ParseDouble _parseDouble;

};

#undef M_PI_180

#endif
