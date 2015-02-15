// Version 1.0

#ifndef _WEZEL_H_
#define _WEZEL_H_

#include "analysisData.h"

// Klasa bazowa dla wez��w drzewa sk�adniowego.
class Wezel{
    public:
        // Konstruktor przyjmuje typ w�z�a oraz numer linii w kt�rej w�ze� wyst�pi�
        inline Wezel( Typ __typ, int __numerLinii):_typ( __typ), _linia( __numerLinii){}
        virtual ~Wezel(){};

        // Wykonuje weze�
        virtual const Wartosc* execute( RunTimeData&)=0;

        // Przechodzi przez drzewo sk�adniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencj� klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli.
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
