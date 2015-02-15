// Version 1.0

#ifndef _WEZEL_BINARNY_H_
#define _WEZEL_BINARNY_H_

#include "wezel.h"

/// Klasa reprezentuje w�z�y drzewa binarnego, kt�re mog� przechowywac jednego lub dw�ch potomk�w
template<typename O, typename P>
class WezelBinarny:public Wezel{
    public:
        typedef O Operator;
        typedef P Prawy;

        ///  Konstruktor dla wez��w typu:   A         B
        ///                                /|\       /|\
        ///                               2 + 3     4 * 5
        WezelBinarny(WezelBinarny* __lewy, Operator* __operator, Prawy* __prawy, int __numerLinii)
        :Wezel( Void, __numerLinii),
        _lewy(__lewy),
        _prawy(__prawy),
        _operator(__operator){
        }

        ///  Konstruktor dla wez��w typu:   A     B
        ///                                 |     |
        ///                                 2     8
        WezelBinarny(Prawy* __prawy, int __numerLinii)
        :Wezel( Void, __numerLinii),
        _lewy(0x00),
        _prawy(__prawy),
        _operator(0x00){
        }

        virtual ~WezelBinarny(){}

        /// Wykonuje wez�
        virtual const Wartosc* execute(RunTimeData& __runTimeData){
            if( _lewy){
                return ( *_operator)( _lewy->execute(__runTimeData), _prawy->execute(__runTimeData));
            }
            return _prawy->execute( __runTimeData);
        }

        /// Analizuje wez� 'w glab'
        virtual void analise( AnalysisData& __analysisData) {
            if( _lewy) {_lewy->analise( __analysisData);}

            _prawy->analise( __analysisData);

            if(_lewy){
                if( _lewy->typ()!= _prawy->typ()){
                    throw IncorectTypes();
                }
            }

            _typ= _prawy->typ();
        }

    protected:
        /// Lewy potomek w�z�a
        WezelBinarny* _lewy;

        /// Prawy potomek w�z�a
        Prawy* _prawy;

        /// Operator u�yty na warto�ciach potomk�w
        Operator* _operator;
};

#endif
