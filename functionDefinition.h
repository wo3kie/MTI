// Version 2.0

#ifndef _DEFINICJA_FUNKCJI_H_
#define _DEFINICJA_FUNKCJI_H_

#include "complexInstruction.h"
#include "declarationList.h"
#include "parameterList.h"
#include "expressionsList.h"

#include <stack>

// 'ActivationRecord' jest interfejsem funkcji. Aby wywolac funkcj�, musimy
// jako parameter przekazac jej rekord aktywacji.
// 'Rekord aktywacji' zawiera informacje o typach zwracanych i przyjmowanych
// przez funkcj�, oraz wartosci przyjmowane i zwracane przez funkcje.
// Ka�da funkcja ma sw�j indywidualny rekord aktywacji.
// Rekord aktywacji tworzy metoda FunctionDefinition::activationRecord.

struct ActivationRecord {
    // Konstruktor przyjmuje nazwe funkcji, value zwracana oraz liste parametrow
    ActivationRecord( const std::string __functionName, Value* __returnValue)
    :functionName( __functionName),
    returnValue( __returnValue){}

    // Nazwa funkcji
    const std::string functionName;

    // Value zwracana
    Value* returnValue;

    // Wartosci arguentow
    std::vector< Value*> valueList;
};

// Reprezentuje funkcje ktora zaimplementowal uzytkownik
class FunctionDefinition:public Node{
    public:
        // Konstruktor przyjmuje value zwracana, nazwe funkcji, lista parametrow,
        // instrukcje (tresc funkcji) oraz numer linii w ktorej rozpoczela sie definicja funkcji
        FunctionDefinition( Value*__value, std::string __identifier,
            ParameterList*__parameterList, Instruction*__instruction,int __lineNumber);

        // Wykonuje funkcje
        virtual const Value* execute( RunTimeData& __runTimeData);

        // Analizuje funkcje
        virtual void analise( AnalysisData& __analysisData);

        // Tworzy rekord aktywacji funkcji
        virtual ActivationRecord& activationRecord(){ return _activationRecord;}

    protected:
        // Rekord aktywacji funkcji
        ActivationRecord _activationRecord;

        // List parametrow
        ParameterList* _parameterList;

        // Instruction, tresc funkcji
        Instruction* _instruction;

        // Tablica zmiennych lokalnych
        VariableTable _localVariableTable;

        // Stos widocznosci, sluzy sledzeniu zasiegow
        std::stack<int> _visibilityStack;

        // Stos wywolan funkcji
        // Kazde wywolanie funkcji jest osobnym obiektem. Zeby nie nadpisywac wartosci
        // zmiennych z poprzedniego wywolania, musza byc one zapamietane.
        // Wykorzystywane przy funkcjach rekurencyjnych
        /* PRZYKLAD

        double silnia( double number){
            if( number== 0){
                return 1;
            }
            else{
                return silnia( number- 1);  // W tym miejscu musimy zapamietac value
            }                               // parametru 'number'
        }

        */
        std::stack< VariableTable> _functionCallStack;
};

/* ========================================================= FunctionDefinition */
inline FunctionDefinition::FunctionDefinition( Value* __value,std::string __identifier,ParameterList* __parameterList,Instruction* __instruction,int __lineNumber)
:Node( Void, __lineNumber),
_activationRecord( __identifier, __value),
_parameterList( __parameterList),
_instruction( __instruction) {
    //std::cout<<"KO2: "<<_parameterList->size()<<std::endl;
}

/* ================================================================== analise */
inline void FunctionDefinition::analise( AnalysisData& __analysisData) {
    // tworzy dane analizy
    __analysisData.blockNumber= Scope::parameterScope;
    __analysisData.visibilityStack= &_visibilityStack;
        _visibilityStack.push( __analysisData.blockNumber /* parameterScope*/);
    __analysisData.localVariableTable= &_localVariableTable;

    // tworzy rekord aktywacji
    for( int parameter= 0; parameter< (int)_parameterList->size(); ++parameter){
        _activationRecord.valueList.push_back( (*_parameterList)[ parameter]->execute(*new RunTimeData())->copy());
    }

    // dodaje funkcje (sama siebie) do tablicy funkcji
    __analysisData.functionTable->insert( _activationRecord.functionName, this, Scope::globalScope);

    // dodaje value zwracana do tablicy symboli
    _localVariableTable.insert( "return", _activationRecord.returnValue, Scope::parameterScope);

    // dodaje parameters do tablicy symboli
    // parameter dodaje sam siebie do lokalnej tablicy symboli
    _parameterList->analise( __analysisData);

    // analizuje w glab drzewo skladniowe
    _instruction->analise( __analysisData);

    // okresla type wartosci zwracanej
    _type= _activationRecord.returnValue->type();
}

/* ================================================================== execute */
inline const Value* FunctionDefinition::execute( RunTimeData& __runTimeData) {
    // tworzy nowa tablice symboli i wklada ja na stos wywolan funkcji
    _functionCallStack.push( _localVariableTable);

    // tworzy dane wykonywania
    __runTimeData.activationRecord= &_activationRecord;
    __runTimeData.localVariableTable= &_functionCallStack.top();

    // kopiuje wartosci parametrow do lokalnej tablicy symboli
    for( unsigned parameter= 0; parameter< _activationRecord.valueList.size(); ++parameter){
    // '::copy' obiekt klasy 'AssignmentOperator' - plik 'operators.h'
        Operators::copy( _functionCallStack.top().value( Scope::parameterScope, parameter+1),
            _activationRecord.valueList[ parameter]);
    }

    // wykonuje funkcje
    _instruction->execute( __runTimeData);

    // '::copy' obiekt klasy 'AssignmentOperator' - plik 'operators.h'
    // kopiuje value zwracana z tablicy symboli do rekordu aktywacji

    /*
        value zwracana przez funkcje znajduje sie w lokalnej tablicy symboli na pierwszej pozycji.
        jezeli w tresci funkcji pojawi sie instruction 'return', kopiuje ona value wyrazenia
        ktore za nia stoi do lokalnej tablicy symboli na pierwsza pozycje.
        kiedy funkcja sie konczy value zwracana musi zostac skopiowana z lokalnej tablicy symboli
        z pierwszej pozycji do rekordu aktywacji - ktory jest interfejsem funkcji
    */

    Operators::copy( _activationRecord.returnValue,
        _functionCallStack.top().value( Scope::parameterScope, Scope::returnPosition)
    );

    // zdejmuje tablice symboli ze stosu
    _functionCallStack.pop();

    return 0x00;
}

#endif
