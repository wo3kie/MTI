// Version 1.0

#include "ifStatement.h"

/* ================================================================== execute */
const Value* IfStatement::execute( RunTimeData& __runTimeData){
    const DoubleValue* value=
        dynamic_cast<const DoubleValue*>( _expression->execute( __runTimeData));

    if( static_cast<bool>(value->execute())){
        _instruction1->execute(__runTimeData);
    }
    else{
        // sprawdzamy czy istnieje druga instruction warunkowa
        if( _instruction2){
            _instruction2->execute( __runTimeData);
        }
    }

    return 0x00;
}

/* ================================================================== analise */
void IfStatement::analise( AnalysisData& __analysisData){
    _expression->analise( __analysisData);
    _instruction1->analise( __analysisData);

    // sprawdzamy czy istnieje druga instruction warunkowa
    if( _instruction2){
        _instruction2->analise( __analysisData);
    }
}
