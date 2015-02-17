// Version 1.0

#ifndef _WEZEL_BINARNY_H_
#define _WEZEL_BINARNY_H_

#include "node.h"

// Klasa reprezentuje wezly drzewa binarnego, ktore moga przechowywac jednego lub dwoch potomkow
template <typename O, typename P>
class BinaryNode : public Node {
public:
    typedef O Operator;
    typedef P Right;

    //  Konstruktor dla wezlow typu:   A         B
    //                                /|\       /|\
        //                               2 + 3     4 * 5
    BinaryNode(BinaryNode* __left, Operator* __operator, Right* __right, int __lineNumber)
        : Node(Void, __lineNumber)
        , _left(__left)
        , _right(__right)
        , _operator(__operator)
    {
    }

    //  Konstruktor dla wezlow typu:   A     B
    //                                 |     |
    //                                 2     8
    BinaryNode(Right* __right, int __lineNumber)
        : Node(Void, __lineNumber)
        , _left(0x00)
        , _right(__right)
        , _operator(0x00)
    {
    }

    virtual ~BinaryNode() {}

    // Wykonuje wezel
    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        if (_left) {
            return (*_operator)(_left->execute(__runTimeData), _right->execute(__runTimeData));
        }
        return _right->execute(__runTimeData);
    }

    // Analizuje wezel 'w glab'
    virtual void analise(AnalysisData& __analysisData)
    {
        if (_left) {
            _left->analise(__analysisData);
        }

        _right->analise(__analysisData);

        if (_left) {
            if (_left->type() != _right->type()) {
                throw IncorectTypes();
            }
        }

        _type = _right->type();
    }

protected:
    // Lewy potomek wezla
    BinaryNode* _left;

    // Right potomek wezla
    Right* _right;

    // Operator u¿yty na wartosciach potomkow
    Operator* _operator;
};

#endif
