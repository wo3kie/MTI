// Version 1.0

#ifndef _ZNAK_WYRAZENIE_H_
#define _ZNAK_WYRAZENIE_H_

#include "operatory.h"

/// Reprezentuje czynnik poprzedzony unarnym operatorem addytywnym
class CzynnikUnarny:public Czynnik{
    public:
        /// Konstruktor przyjmuje czynnik i unarny operator addytywny oraz numer linii w kt�rej w�ze�
        /// zosta� utworzony
        inline CzynnikUnarny(Czynnik* __czynnik, const OperatorUnarny* __operator, int __numerLinii);

        /// Oblicza wartosc czynnika
        virtual const Wartosc* execute(RunTimeData& __runTimeData);

        /// Przechodzi przez drzewo skladniowe w gl�b
        /// w celu analizy semantycznej drzewa.
        /// Jako parametr przyjmuje referencje klasy 'AnalysisData'
        /// kt�ra przechowuje informacje o tablicach symboli
        virtual void analise( AnalysisData& __analysisData);

    private:
        /// Operator unarny np.: +2, -3
        const OperatorUnarny* _operator;

        /// Wska�nik na czynnik
        Czynnik* _lewy;
};

/* ============================================================ CzynnikUnarny */
inline CzynnikUnarny::CzynnikUnarny(Czynnik* __czynnik,const OperatorUnarny* __operator, int __numerLinii)
:Czynnik( Void, __numerLinii),
_operator(__operator),_lewy(__czynnik){
}

/* ================================================================== analise */
inline void CzynnikUnarny::analise( AnalysisData& __analysisData){
    _lewy->analise( __analysisData);
    _typ= _lewy->typ();
}

/* ================================================================== execute */
inline const Wartosc* CzynnikUnarny::execute( RunTimeData& __runTimeData){
    if( _operator){
        return (*_operator)( _lewy->execute( __runTimeData));
    }
    return _lewy->execute( __runTimeData);
}

#endif
