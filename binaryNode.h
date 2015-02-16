// Version 1.0

#ifndef _WEZEL_BINARNY_H_
#define _WEZEL_BINARNY_H_

#include "node.h"

// Klasa reprezentuje wêz³y drzewa binarnego, które mog¹ przechowywac jednego lub dwóch potomków
template<typename O, typename P>
class BinaryNode:public Node{
    public:
        typedef O Operator;
        typedef P Right;

        //  Konstruktor dla wez³ów typu:   A         B
        //                                /|\       /|\
        //                               2 + 3     4 * 5
        BinaryNode(BinaryNode* __left, Operator* __operator, Right* __right, int __lineNumber)
        :Node( Void, __lineNumber),
        _left(__left),
        _right(__right),
        _operator(__operator){
        }

        //  Konstruktor dla wez³ów typu:   A     B
        //                                 |     |
        //                                 2     8
        BinaryNode(Right* __right, int __lineNumber)
        :Node( Void, __lineNumber),
        _left(0x00),
        _right(__right),
        _operator(0x00){
        }

        virtual ~BinaryNode(){}

        // Wykonuje wezê³
        virtual const Value* execute(RunTimeData& __runTimeData){
            if( _left){
                return ( *_operator)( _left->execute(__runTimeData), _right->execute(__runTimeData));
            }
            return _right->execute( __runTimeData);
        }

        // Analizuje wezê³ 'w glab'
        virtual void analise( AnalysisData& __analysisData) {
            if( _left) {_left->analise( __analysisData);}

            _right->analise( __analysisData);

            if(_left){
                if( _left->type()!= _right->type()){
                    throw IncorectTypes();
                }
            }

            _type= _right->type();
        }

    protected:
        // Lewy potomek wêz³a
        BinaryNode* _left;

        // Right potomek wêz³a
        Right* _right;

        // Operator u¿yty na wartoœciach potomków
        Operator* _operator;
};

#endif
