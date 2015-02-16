// Version 1.0

#ifndef _INSTRUKCJA_WARUNKOWA_IF_
#define _INSTRUKCJA_WARUNKOWA_IF_

#include "complexInstruction.h"
#include "expression.h"

// Reprezentuje instrukcje warunkow¹ w programie u¿ytkowanika
class IfStatement:public Instruction{
    public:
        // Konstruktor przyjmuje wyra¿enie, dwie instrukcje z³o¿one oraz numer linii
        // w której wyst¹pi³a ta instruction
        IfStatement(Expression* __expression,Instruction* __instrukcja1,
        Instruction* __instrukcja2, int __lineNumber)
        :Instruction( Void, __lineNumber),
        _expression(__expression),
        _instruction1(__instrukcja1),
        _instruction2(__instrukcja2){
        }

        // Konstruktor przyjmuje wyra¿enie, instrukcje z³o¿on¹ oraz numer linii
        // w której wyst¹pi³a ta instruction
        IfStatement(Expression* __expression,Instruction* __instruction, int __lineNumber)
        :Instruction( Void, __lineNumber),
        _expression(__expression),
        _instruction1(__instruction),
        _instruction2(0x00){
        }

        // Wykonuje instrukcjê warunkow¹
        virtual const Value* execute( RunTimeData& __runTimeData);

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parameter przyjmuje referencje klasy 'AnalysisData'
        // która przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowan¹ zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData);

    private:
        // Wyra¿enie logiczne
        Expression* _expression;

        // Je¿eli wyra¿enie logiczne bylo prawdziwe wykona siê ta instruction
        Instruction* _instruction1;

        // Je¿eli wyra¿enie logiczne bylo fa³szywe wykona siê ta instruction
        Instruction* _instruction2;
};

#endif
