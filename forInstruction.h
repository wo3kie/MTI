// Version 1.0

#ifndef _INSTRUKCJA_ITERACYJNA_FOR_H_
#define _INSTRUKCJA_ITERACYJNA_FOR_H_

#include "declaration.h"
#include "assignmentInstruction.h"
#include "complexInstruction.h"
#include "expression.h"

// Reprezentuje instrukcje 'while'
class ForInstruction: public Instruction{
    public:
        // Konstruktor przyjmuje jako argumenty wyra�enie kt�re b�dzie sprawdzane
        // przed ka�d� iteracj� p�tli, instrukcje z�o�on� kt�ra jest tre�ci� p�tli,
        // oraz numer linii gdzie instruction warunkowa si� rozpoczyna
        inline ForInstruction(
            Declaration* __declaration, Expression* __condition, AssignmentInstruction* __assignment,
            Instruction* __instruction,int __lineNumber);

        // Wykonuje instrukcj�
        virtual Value* execute( RunTimeData& __runTimeData);

        // Przechodzi przez drzewo sk�adniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parameter przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli
        virtual void analise( AnalysisData& __analysisData);

    private:
        Declaration* _declaration;//declaration
        Expression* _condition;// warunek konca petli
        AssignmentInstruction* _assignment;// inkrementacja

        // Instruction zlo�ona kt�ra wykona si� je�eli warunek b�dzie spe�niony
        Instruction* _instruction;
};

/* ================================================ WhileInstruction */
inline ForInstruction::ForInstruction(
    Declaration* __declaration,Expression*__condition,AssignmentInstruction* __assignment,Instruction* __instruction,int __lineNumber)
:Instruction( Void, __lineNumber),
_declaration( __declaration),
_condition( __condition),
_assignment( __assignment),
_instruction( __instruction){
}

#endif
