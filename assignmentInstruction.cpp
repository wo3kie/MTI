// Version 1.1

#include "assignmentInstruction.h"

/* ================================================================== execute */
const Wartosc* InstrukcjaPrzypisania::execute(RunTimeData& __runTimeData){

    // '::kopiuj' obiekt klasy 'OperatorPrzypisania' - plik operators.h
    return Operatory::kopiuj( _identyfikator->assign(__runTimeData), _wyrazenie->execute(__runTimeData));
}

/* ================================================================== analise */
void InstrukcjaPrzypisania::analise( AnalysisData& __analysisData){
    _identyfikator->analise( __analysisData);
    _wyrazenie->analise( __analysisData);

    if( ( _typ= _identyfikator->typ())!= _wyrazenie->typ()){
        throw IncorectTypes();
    }
}
