// Version 1.1

#include "assignmentInstruction.h"

/* ================================================================== execute */
const Value* AssignmentInstruction::execute(RunTimeData& __runTimeData){

    // '::copy' obiekt klasy 'AssignmentOperator' - plik operators.h
    return Operators::copy( _identifier->assign(__runTimeData), _expression->execute(__runTimeData));
}

/* ================================================================== analise */
void AssignmentInstruction::analise( AnalysisData& __analysisData){
    _identifier->analise( __analysisData);
    _expression->analise( __analysisData);

    if( ( _type= _identifier->type())!= _expression->type()){
        throw IncorectTypes();
    }
}
