// Version 1.0

#ifndef _ZNAK_WYRAZENIE_H_
#define _ZNAK_WYRAZENIE_H_

#include "operators.h"

// Reprezentuje unit poprzedzony unarnym operatorem addytywnym
class UnaryFactor:public Factor{
    public:
        // Konstruktor przyjmuje unit i unarny operator addytywny oraz numer linii w kt�rej w�ze�
        // zosta� utworzony
        inline UnaryFactor(Factor* __unit, const UnaryOperator* __operator, int __lineNumber);

        // Oblicza value czynnika
        virtual const Value* execute(RunTimeData& __runTimeData);

        // Przechodzi przez drzewo skladniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parameter przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli
        virtual void analise( AnalysisData& __analysisData);

    private:
        // Operator unarny np.: +2, -3
        const UnaryOperator* _operator;

        // Wska�nik na unit
        Factor* _left;
};

/* ============================================================ UnaryFactor */
inline UnaryFactor::UnaryFactor(Factor* __unit,const UnaryOperator* __operator, int __lineNumber)
:Factor( Void, __lineNumber),
_operator(__operator),_left(__unit){
}

/* ================================================================== analise */
inline void UnaryFactor::analise( AnalysisData& __analysisData){
    _left->analise( __analysisData);
    _type= _left->type();
}

/* ================================================================== execute */
inline const Value* UnaryFactor::execute( RunTimeData& __runTimeData){
    if( _operator){
        return (*_operator)( _left->execute( __runTimeData));
    }
    return _left->execute( __runTimeData);
}

#endif
