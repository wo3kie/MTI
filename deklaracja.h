#ifndef _DEKLARACJA_H_
#define _DEKLARACJA_H_

#include <cassert>

#include "instrukcja.h"

// Reprezetuje deklaracje zmiennej
class Deklaracja: public Instrukcja{
    public:
        // Przyjmuje typ zmiennej i jej nazw� oraz numer linii w kt�rej utworzono w�ze�
        inline Deklaracja(Typ __typ,const std::string& __identyfikator, int __numerLinii)
        :Instrukcja(__typ, __numerLinii),
        _identyfikator(__identyfikator){
        }

        virtual ~Deklaracja(){}

        // Zwraca nazw� zmiennej
        virtual const std::string identyfikator()const{ return _identyfikator;}

        // Zwraca r-warto�c
        virtual const Wartosc* execute( RunTimeData& __runTimeData)=0;
        virtual const Wartosc* execute()=0;

        // Przechodzi przez drzewo skladniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli
        virtual void analise( AnalysisData& __analysisData)=0;

    protected:
        // Nazwa zmiennej
        const std::string _identyfikator;
};

// Reprezentuje deklaracje zemiennej typu double
class DeklaracjaDouble:public Deklaracja{
    public:
        // Konstruktor przyjmuje nazwe zmiennej i zainicjowanie oraz numer linii w kt�rej w�ze�
        // zosta� utworzony
        DeklaracjaDouble(const std::string& __identyfikator,double __inicjator, int __numerLinii)
        :Deklaracja(Double,__identyfikator,__numerLinii),
        _wartosc(__inicjator){
        }

        virtual ~DeklaracjaDouble(){}

        virtual const WartoscDouble* execute( RunTimeData& __runTimeData){ return &_wartosc;}
        virtual const WartoscDouble* execute(){return &_wartosc;}

        // Przechodzi przez drzewo skladniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli.
        // dodaje zadeklarowana zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){
            __analysisData.tablicaZmiennychLokalnych->insert( _identyfikator, &_wartosc, __analysisData.stosWidocznosci->top());
        }

    protected:
        // Przechowuje r-warto�c zmiennej
        WartoscDouble _wartosc;
};

// Reprezentuje deklaracje zemiennej typu string
class DeklaracjaString:public Deklaracja{
    public:
        // Konstruktor przyjmuje jako parametr nazwe zmiennej i zainicjowanie oraz numer linii
        // w kt�rej utworzone w�ze�
        DeklaracjaString(const std::string& __identyfikator,std::string __inicjator, int __numerLinii)
        :Deklaracja(String,__identyfikator,__numerLinii),
        _wartosc(__inicjator){
        }

        virtual ~DeklaracjaString(){}

        virtual const WartoscString* execute( RunTimeData& __runTimeData){ return &_wartosc;}
        virtual const WartoscString* execute(){ return &_wartosc;}

        // Przechodzi przez drzewo skladniowe w gl�b
        // w celu analizy semantycznej drzewa.
        // Jako parametr przyjmuje referencje klasy 'AnalysisData'
        // kt�ra przechowuje informacje o tablicach symboli.
        // Dodaje zadeklarowana zmienna do tablicy symboli
        virtual void analise( AnalysisData& __analysisData){
            __analysisData.tablicaZmiennychLokalnych->insert( _identyfikator, &_wartosc, __analysisData.stosWidocznosci->top());
        }

    protected:
        // Przechowuje r-warto�c zmiennej
        WartoscString _wartosc;
};

#endif
