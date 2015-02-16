// Version 1.0

#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include <iostream>
#include <fstream>

#include "myParser.h"
#include "callParameter.h"
    extern Parameters parameters;

// Podstawowa klasa programu
class Interpreter{
    public:
        // Przyjmuje argumenty funkcji main( int argc, char** argv)
        Interpreter( int __argc, char** __argv);

        // Wczytuje plik, buduje, sprawdza i wykonuje drzewo sk³adniowe programu.
        // Zwraca 0 je¿eli nie napotkano na blêdy i value ró¿na od zera w przeciwnym razie
        int run(){ return _parser->yyparse();}

    protected:
        // WskaŸnik na parser uzyty do budowy drzewa sk³adniowego
        Parser* _parser;
};

/* ============================================================== Interpreter */
Interpreter::Interpreter( int argc, char** argv){
    if( argc>= 2){
        std::ifstream* plik= new std::ifstream( argv[ 1]);

        if( !(*plik)){
            throw UnableToOpenFile( argv[1]);
        }

        // parameters wywolania
        parameters.argc= argc- 2;

        for( int parameter= 0; parameter< parameters.argc; ++parameter){
            parameters.argv.push_back( new DoubleValue( atof( argv[ parameter+2])));
        }

        _parser= new MyParser( plik, &std::cerr);
        // bledy o parsowaniu beda skierowane na standardowe wyjscie 'std::cerr'
    }
    else{
        throw NoInputFile();
    }
}

#endif
