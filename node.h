// Version 1.0

#ifndef _WEZEL_H_
#define _WEZEL_H_

#include "analysisData.h"

// Klasa bazowa dla wez³ów drzewa sk³adniowego.
class Node{
    public:
        // Konstruktor przyjmuje type wêz³a oraz numer linii w której wêze³ wyst¹pi³
        inline Node( Type __type, int __lineNumber):_type( __type), _line( __lineNumber){}
        virtual ~Node(){};

        // Wykonuje weze³
        virtual const Value* execute( RunTimeData&)=0;

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parameter przyjmuje referencjê klasy 'AnalysisData'
        // która przechowuje informacje o tablicach symboli.
        virtual void analise( AnalysisData&)=0;

        // Zwraca type wezla. Niektore wezly zwracaja type Void
        virtual Type type()const{ return _type;}

        // Zwraca w ktorej linii zostal utworzony wezel
        // Wazne przy generowaniu informacji o bledzie
        virtual int linia()const{ return _line;}

    protected:
        // Przechowuje type wezla
        Type _type;

        // Pamieta w ktorej linijce kodu uzytkownika wezel zostal utworzony
        int _line;
};

#endif
