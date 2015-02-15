// Version 1.0

#ifndef _WEZEL_H_
#define _WEZEL_H_

#include "analysisData.h"

// Klasa bazowa dla wez³ów drzewa sk³adniowego.
class Wezel{
    public:
        // Konstruktor przyjmuje typ wêz³a oraz numer linii w której wêze³ wyst¹pi³
        inline Wezel( Typ __typ, int __numerLinii):_typ( __typ), _linia( __numerLinii){}
        virtual ~Wezel(){};

        // Wykonuje weze³
        virtual const Wartosc* execute( RunTimeData&)=0;

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencjê klasy 'AnalysisData'
        // która przechowuje informacje o tablicach symboli.
        virtual void analise( AnalysisData&)=0;

        // Zwraca typ wezla. Niektore wezly zwracaja typ Void
        virtual Typ typ()const{ return _typ;}

        // Zwraca w ktorej linii zostal utworzony wezel
        // Wazne przy generowaniu informacji o bledzie
        virtual int linia()const{ return _linia;}

    protected:
        // Przechowuje typ wezla
        Typ _typ;

        // Pamieta w ktorej linijce kodu uzytkownika wezel zostal utworzony
        int _linia;
};

#endif
