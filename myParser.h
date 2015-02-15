// Version 1.0

#ifndef _MY_PARSER_H_
#define _MY_PARSER_H_

#include "lekser.h"

/// Parser
class MyParser:public Parser{
    public:
        /// Przyjmuje wskaünik na strumieÒ skπd bÍdzie wczytywa≥ dane
        /// i gdzie je wypisywa≥
        MyParser(istream*,ostream*);

        virtual ~MyParser(){ delete _out; delete _in;}

        /// Funkcja wywo≥ywana z przypadku b≥Ídu parsowania
        virtual void yyerror(char* __msg);

        /// Metoda dostarcza kolejny symbol leksykalny ze strumienia
        virtual int yylex();
    private:
        /// Lekser wczytuje plik i dostarcza symbole leksykalne do parsera
        Lekser _lekser;

        /// Wskaüniki na wejúcie
        istream* _in;

        /// Wskaünik na wyjúcie
        ostream* _out;
};

#endif
