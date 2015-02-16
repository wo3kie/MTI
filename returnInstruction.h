// Version 1.0

#ifndef _INSTRUKCJA_SKOKU_RETURN_H_
#define _INSTRUKCJA_SKOKU_RETURN_H_

#include "expression.h"

// Instruction ta nie koñczy dzia³ania funkcji. Okreœla jak¹ wartoœc zwróci funkcja.
// Je¿eli w funkcji u¿yjemy instrukcji return wielokrotnie, funkcja zwróci wartoœc
// wyliczon¹ w ostatniej instrukcji return.
//   Przyk³ad:
//      double funkcja(){
//         return 1;
//         return 2;
//     }
//
//     Funkcja zwróci wartoœc 2
class ReturnInstruction: public Instruction{
    public:
        // Konstruktor przyjmuje wyra¿enie którego wartoœc zwróci,
        // oraz numer linii w której wyst¹pi³a instruction
        ReturnInstruction( Expression* __expression, int __lineNumber)
        // Zmienna 'return' jest pierwszym wpisem w lokalnej tablicy zmiennych
        // i przechowuje zwracan¹ wartoœc
        :Instruction( Void, __lineNumber),
        _expression(__expression){
        }

        // Kopiuje do pierwszej pozycji lokalnej tablicy symboli wartoœc wyrazenia
        virtual const Value* execute(RunTimeData& __runTimeData){
            // '::copy' obiekt klasy 'AssignmentOperator' - plik operators.h

            // Value zwracana jest zawsze w pierwszym zasiegu funkcji na samym poczatku
            // _position( 1, 0)  -   scope 0 jest zarezerwowany dla zasiegu globalnego
            Operators::copy( __runTimeData.localVariableTable->value(
                    Scope::parameterScope, Scope::returnPosition
                ),
                _expression->execute( __runTimeData)
            );

            return 0x00;
        }

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parameter przyjmuje referencje klasy 'AnalysisData'
        // która przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan¹ zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){
            _expression->analise( __analysisData);
        }

    protected:
        // Wyra¿enie po s³owie kluczowym 'return'
        Expression* _expression;
};

#endif
