// Version 1.0

#include "functionCall.h"

/* ================================================================== execute */
const Value* FunctionCall::execute(RunTimeData& __runTimeData){
    // kopiuje wartosci parametrow do rekordu aktywacji
    ActivationRecord& activationRecord=
        __runTimeData.functionTable->value( Scope::globalScope, _position)->activationRecord();

    for( unsigned parameter= 0; parameter< _expressionList->size(); ++parameter){
        Operators::copy( activationRecord.valueList[ parameter],
            (*_expressionList)[ parameter]->execute( __runTimeData)
        );
    }

    VariableTable* temporary= __runTimeData.localVariableTable;

    // uruchamia funkcje
    __runTimeData.functionTable->value( Scope::globalScope, _position)->execute( __runTimeData);

    __runTimeData.localVariableTable= temporary;

    return activationRecord.returnValue;
}

/* ================================================================== analise */
void FunctionCall::analise( AnalysisData& __analysisData){
    // znajduje funkcje w tablicy funkcji
    try{
        _position= __analysisData.functionTable->find( _identifier, Scope::globalScope);   // 0 bo scope globalny
    }
    catch( const UndefinedSymbol& __error){
        throw UndefinedSymbol( std::string("Cannot find function: '")+ _identifier+ std::string("'"));
    }

    // pobieramy rekord aktywacji
    ActivationRecord& activationRecord= __analysisData.functionTable->value( 0, _position)->activationRecord();

    // sprawdzam czy zgadza sie ilosc parametrow oraz ich typy
    if( _expressionList->size()!= activationRecord.valueList.size()){

        std::cout<<"LW: "<<_expressionList->size()<<std::endl
            <<"RA: "<<activationRecord.valueList.size()<<std::endl;

        throw CannotCallFunction( _identifier);
    }

    for( unsigned parameter=0; parameter< _expressionList->size(); ++parameter){
        // Analizujemy wyrazenia
        _expressionList->analise( __analysisData);

        if( (*_expressionList)[ parameter]->type()!= activationRecord.valueList[ parameter]->type()){
            throw CannotCallFunction( _identifier);
        }
    }

    // obliczam jaki type zwroci funkcja
    _type= activationRecord.returnValue->type();
}
