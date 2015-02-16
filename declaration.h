#ifndef _DEKLARACJA_H_
#define _DEKLARACJA_H_

#include <cassert>

#include "instruction.h"

// Reprezetuje deklaracje zmiennej
class Declaration: public Instruction{
    public:
        // Przyjmuje type zmiennej i jej nazw� oraz numer linii w kt�rej utworzono w�ze�
        inline Declaration(Type __type,const std::string& __identifier, int __lineNumber)
        :Instruction(__type, __lineNumber),
        _identifier(__identifier){
        }

        virtual ~Declaration(){}

        // Zwraca nazw� zmiennej
        virtual const std::string identifier()const{ return _identifier;}

        // Zwraca r-warto�c
        virtual const Value* execute( RunTimeData& __runTimeData)=0;
        virtual const Value* execute()=0;

        // Przechodzi przez drzewo skladniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parameter przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli
        virtual void analise( AnalysisData& __analysisData)=0;

    protected:
        // Nazwa zmiennej
        const std::string _identifier;
};

// Reprezentuje deklaracje zemiennej typu double
class DoubleDeclaration:public Declaration{
    public:
        // Konstruktor przyjmuje nazwe zmiennej i zainicjowanie oraz numer linii w kt�rej w�ze�
        // zosta� utworzony
        DoubleDeclaration(const std::string& __identifier,double __init, int __lineNumber)
        :Declaration(Double,__identifier,__lineNumber),
        _value(__init){
        }

        virtual ~DoubleDeclaration(){}

        virtual const DoubleValue* execute( RunTimeData& __runTimeData){ return &_value;}
        virtual const DoubleValue* execute(){return &_value;}

        // Przechodzi przez drzewo skladniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parameter przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli.
        // dodaje zadeklarowana zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){
            __analysisData.localVariableTable->insert( _identifier, &_value, __analysisData.visibilityStack->top());
        }

    protected:
        // Przechowuje r-warto�c zmiennej
        DoubleValue _value;
};

// Reprezentuje deklaracje zemiennej typu string
class StringDeclaration:public Declaration{
    public:
        // Konstruktor przyjmuje jako parameter nazwe zmiennej i zainicjowanie oraz numer linii
        // w kt�rej utworzone w�ze�
        StringDeclaration(const std::string& __identifier,std::string __init, int __lineNumber)
        :Declaration(String,__identifier,__lineNumber),
        _value(__init){
        }

        virtual ~StringDeclaration(){}

        virtual const StringValue* execute( RunTimeData& __runTimeData){ return &_value;}
        virtual const StringValue* execute(){ return &_value;}

        // Przechodzi przez drzewo skladniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parameter przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowana zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){
            __analysisData.localVariableTable->insert( _identifier, &_value, __analysisData.visibilityStack->top());
        }

    protected:
        // Przechowuje r-warto�c zmiennej
        StringValue _value;
};

#endif
