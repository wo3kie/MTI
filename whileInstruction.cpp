// Version 1.0

#include "whileInstruction.h"

/* ================================================================== execute */
Value* WhileInstruction::execute( RunTimeData& __runTimeData){
	while( true){
		const DoubleValue* value=
		    dynamic_cast<const DoubleValue*>( _expression->execute( __runTimeData));
                // Konwersja Value* -> DoubleValue*

		if( static_cast<bool>(value->execute(/* __runTimeData*/))){
			_instruction->execute( __runTimeData);
		}
		else{
			break;
		}
	}

	return 0x00;
}

/* ================================================================== analise */
void WhileInstruction::analise( AnalysisData& __analysisData){
    _expression->analise( __analysisData);
    _instruction->analise( __analysisData);
}
