// Version 1.0

#ifndef _MY_PARSER_H_
#define _MY_PARSER_H_

#include <iostream>

#include "czynnik.h"
#include "czynnikUnarny.h"
#include "definicjaFunkcji.h"
#include "instrukcjaIteracyjnaWhile.h"
#include "instrukcjaPrzypisania.h"
#include "instrukcjaSkokuReturn.h"
#include "instrukcjaWarunkowaIf.h"
#include "instrukcjeIO.h"
#include "liczba.h"
#include "lista.h"
#include "literalNapisowy.h"
#include "nawias.h"
#include "program.h"
#include "symbolLocation.h"
#include "wartosc.h"
#include "wyrazenie.h"
#include "wywolanieFunkcji.h"

#include "lekser.h"
#include "parser.h"

// Parser
class MyParser : public Parser{
    public:
        // Przyjmuje wska�nik na strumie� sk�d b�dzie wczytywa� dane
        // i gdzie je wypisywa�
        MyParser( std::istream*, std::ostream*);
};

#endif
