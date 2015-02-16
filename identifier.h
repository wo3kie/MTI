// Version 1.0

#ifndef _IDENTYFIKATOR_H_
#define _IDENTYFIKATOR_H_

#include <cassert>

#include "factor.h"
#include "symbolTable.h"

// Reprezentuje identifier, zmienn¹ w programie uzytkownika
class Identifier:public Factor{
    public:
        // Konstruktor przyjmuje nazwê zmiennej oraz numer linii
        // w której wyst¹pi³a zmienna
        Identifier(std::string __identifier, int __lineNumber)
        :Factor( Void, __lineNumber),
        _identifier( __identifier){
        }

        virtual ~Identifier(){}

        // Klasa nie jest abstrakcyjna
        virtual const Value* execute( RunTimeData& _runTimeData)=0;
        virtual Value* assign( RunTimeData& _runTimeData)=0;

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parameter przyjmuje referencje klasy 'AnalysisData'
        // ktora przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowana zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData)=0;

        // Zwraca type
        virtual Type type()const{ return _type;}

    protected:
        // Nazwa zmiennej
        std::string _identifier;

        // TablicaSymboli
        VariableTable* _variableTable;

        std::pair<unsigned,unsigned> _position;    // position.first - scope; position.second - position w zasiegu

        // Type zmiennej
        Type _type;
};

// Reprezentuje zmienne lokalne w programie uzytkownika
class LocalVariable: public Identifier{
    public:
        // Konstruktor przyjmuje nazwê zmiennej oraz numer linii
        // w której wyst¹pi³a zmienna
        LocalVariable( std::string __identifier, int __lineNumber)
        :Identifier( __identifier, __lineNumber){
        }

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parameter przyjmuje referencje klasy 'AnalysisData'
        // ktora przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowana zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){

            // Tworzymy kopie stosu widocznosci, zeby nie zmodyfikowac oryginalu
            std::stack<int> visibilityStack( *__analysisData.visibilityStack);

            // Przeszukujemy najpierw lokalne tablice symboli. Jezeli nie znajdziemy tam
            // poszukiwanej zmiennej szukamy w globalnej tablicy symboli.
            // Jezeli nie uda nam sie odnalezc zmiennej zglaszamy wyjatek 'UndefinedSymbol'

            while( !visibilityStack.empty()){   // Przeszukujemy zasiegi w ktorych jestesmy
                try{
                    _position= std::make_pair(
                        visibilityStack.top(),
                        __analysisData.localVariableTable->find(
                            _identifier,
                            visibilityStack.top()
                        )
                    );
                }
                catch( const UndefinedSymbol& __error){
                    visibilityStack.pop();
                    continue;
                }

                _type= __analysisData.localVariableTable->value( _position)->type();
                return;
            }

            try{
                _position= std::make_pair( 0,
                    __analysisData.globalVariableTable->find( _identifier, 0)
                );
            }
            catch( const UndefinedSymbol& __error){
                throw UndefinedSymbol( std::string("Undefined symbol: ")+ _identifier);
            }

            _type= __analysisData.globalVariableTable->value( _position)->type();
        }

        // Zwraca r-value
        virtual const Value* execute( RunTimeData& __runTimeData){

            // Scope globalny ma value '0'. Jezeli pole '_position.first' ma
            // value 0 oznacza to, ze jest to zmienna globalna

            return _position.first ? __runTimeData.localVariableTable->value( _position)
                : __runTimeData.globalVariableTable->value( _position);
        }

        // Uzywane przez 'operator=' do przypisania wartoœci
        virtual Value* assign( RunTimeData& __runTimeData){
            return _position.first ? __runTimeData.localVariableTable->value( _position)
                : __runTimeData.globalVariableTable->value( _position);
        }
};

class GlobalVariable:public Identifier{
    public:
        // Konstruktor przyjmuje nazwê zmiennej oraz numer linii
        // w której wyst¹pi³a zmienna
        GlobalVariable( std::string __identifier, int __lineNumber)
        :Identifier( __identifier, __lineNumber){
        }

        // Destruktor
        virtual ~GlobalVariable(){}

        // Przechodzi przez drzewo sk³adniowe w gl¹b
        // w celu analizy semantycznej drzewa.
        // Jako parameter przyjmuje referencje klasy 'AnalysisData'
        // ktora przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowana zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){
            _position= std::make_pair( Scope::globalScope,
                __analysisData.globalVariableTable->find( _identifier, Scope::globalScope)
            );

            _type= __analysisData.globalVariableTable->value( _position)->type();
        }

        // Zwraca r-value
        virtual const Value* execute( RunTimeData& __runTimeData){
            return __runTimeData.globalVariableTable->value( _position);
        }

        // Uzywane przez 'operator=' do przypisania wartoœci
        virtual Value* assign( RunTimeData& __runTimeData){
            return __runTimeData.globalVariableTable->value( _position);
        }
};

#endif
