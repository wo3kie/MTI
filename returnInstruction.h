// Version 1.0

#ifndef _INSTRUKCJA_SKOKU_RETURN_H_
#define _INSTRUKCJA_SKOKU_RETURN_H_

#include "expression.h"

// Instruction ta nie ko�czy dzia�ania funkcji. Okre�la jak� warto�c zwr�ci funkcja.
// Je�eli w funkcji u�yjemy instrukcji return wielokrotnie, funkcja zwr�ci warto�c
// wyliczon� w ostatniej instrukcji return.
//   Przyk�ad:
//      double funkcja(){
//         return 1;
//         return 2;
//     }
//
//     Funkcja zwr�ci warto�c 2
class ReturnInstruction: public Instruction{
    public:
        // Konstruktor przyjmuje wyra�enie kt�rego warto�c zwr�ci,
        // oraz numer linii w kt�rej wyst�pi�a instruction
        ReturnInstruction( Expression* __expression, int __lineNumber)
        // Zmienna 'return' jest pierwszym wpisem w lokalnej tablicy zmiennych
        // i przechowuje zwracan� warto�c
        :Instruction( Void, __lineNumber),
        _expression(__expression){
        }

        // Kopiuje do pierwszej pozycji lokalnej tablicy symboli warto�c wyrazenia
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

        // Przechodzi przez drzewo sk�adniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parameter przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan� zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){
            _expression->analise( __analysisData);
        }

    protected:
        // Wyra�enie po s�owie kluczowym 'return'
        Expression* _expression;
};

#endif
