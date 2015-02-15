// Version 1.0

#ifndef _NAWIAS_H_
#define _NAWIAS_H_

#include "expression.h"

// Reprezentuje nawias
class Nawias: public Czynnik{
    public:
        // Konstruktor przyjmuje wyra¿enie oraz numer linii w której wyst¹pi³
        // nawias
        Nawias(Wyrazenie* __wyrazenie, int __numerLinii)
        :Czynnik( Void, __numerLinii),
        _lewy(__wyrazenie){}
        virtual ~Nawias(){}

        // Zwraca wartosc wyrazenia w nawiasach
        virtual const Wartosc* execute( RunTimeData& __runTimeData){
            return _lewy->execute( __runTimeData);
        }

        // Analizuje wyrazenie zawarte w nawiasie
        virtual void analise(AnalysisData& __analysisData);

    private:
        // Wyrazenie w nawiasie
        Wyrazenie* _lewy;
};

/* ================================================================== analise */
inline void Nawias::analise(AnalysisData& __analysisData){
    _lewy->analise( __analysisData);
    _typ= _lewy->typ();
}

#endif
