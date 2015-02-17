// Version 1.0

#include "doWhileInstruction.h"

/* ================================================================== execute */
Value* DoWhileInstruction::execute(RunTimeData& __runTimeData)
{
    while (true) {
        _instructionList->execute(__runTimeData);

        const DoubleValue* value = dynamic_cast<const DoubleValue*>(_expression->execute(__runTimeData));

        if (!static_cast<bool>(value->execute())) {
            break;
        }
    }

    return 0x00;
}

/* ================================================================== analise */
void DoWhileInstruction::analise(AnalysisData& __analysisData)
{
    _instructionList->analise(__analysisData);
    _expression->analise(__analysisData);
}
