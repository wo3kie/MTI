// Version 1.0

#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include <iostream>
#include <fstream>

#include "myParser.h"
#include "parametryWywolania.h"
    extern Parametry parametry;

/// Podstawowa klasa programu
class Interpreter{
    public:
        /// Przyjmuje argumenty funkcji main( int argc, char** argv)
        Interpreter( int __argc, char** __argv);

        /// Wczytuje plik, buduje, sprawdza i wykonuje drzewo sk�adniowe programu.
        /// Zwraca 0 je�eli nie napotkano na bl�dy i wartosc r�na od zera w przeciwnym razie
        int run(){ return _parser->yyparse();}

    protected:
        /// Wska�nik na parser uzyty do budowy drzewa sk�adniowego
        Parser* _parser;
};

/* ============================================================== Interpreter */
Interpreter::Interpreter( int argc, char** argv){
    if( argc>= 2){
        std::ifstream* plik= new std::ifstream( argv[ 1]);

        if( !(*plik)){
            throw UnableToOpenFile( argv[1]);
        }

        // parametry wywolania
        parametry.argc= argc- 2;

        for( int parametr= 0; parametr< parametry.argc; ++parametr){
            parametry.argv.push_back( new WartoscDouble( atof( argv[ parametr+2])));
        }

        _parser= new MyParser( plik, &std::cerr);
        // bledy o parsowaniu beda skierowane na standardowe wyjscie 'std::cerr'
    }
    else{
        throw NoInputFile();
    }
}

#endif
