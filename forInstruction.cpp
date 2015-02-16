// Version 1.0

#include "forInstruction.h"

/* ================================================================== execute */
Value* ForInstruction::execute( RunTimeData& __runTimeData){
        _declaration->execute( __runTimeData);

        while( true){
                const DoubleValue* value=
                    dynamic_cast<const DoubleValue*>( _condition->execute( __runTimeData));
                // Konwersja Value* -> DoubleValue*

                if( static_cast<bool>(value->execute(/* __runTimeData*/))){
                        _instruction->execute( __runTimeData);
                        _assignment->execute( __runTimeData);
                }
                else{
                        break;
                }
        }

        return 0x00;
}

/* ================================================================== analise */
void ForInstruction::analise( AnalysisData& __analysisData){
    __analysisData.visibilityStack->push( ++__analysisData.blockNumber);
    _declaration->analise( __analysisData);
    _condition->analise( __analysisData);
    _assignment->analise( __analysisData);
    _instruction->analise( __analysisData);
    __analysisData.visibilityStack->pop();
}
