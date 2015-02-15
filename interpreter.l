/* TablicaSlowKluczowych _TSK_( Parser::IDENTYFIKATOR); */

/* %name Lekser */
/* %define IOSTREAM */

/* %define LEX_PARAM YY_Parser_STYPE *val */

%{
#include <stdlib.h>
#include <string>

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

#include "parser.h"
#include "tablicaSlowKluczowych.h"
%}

%option outfile="lekser.cpp" header-file="lekser.h"
%option c++ 8bit warn debug

/* %define MEMBERS public: SymbolLocation sLocation; */

bialyZnak                   [ \t]
nowaLinia                   \n

litera                      [_a-zA-Z]

cyfra			            [0-9]

identyfikator               {litera}({litera}|{cyfra})*
literalNapisowy             \"[^"\n]*\"

liczba                      {cyfra}+(\.{cyfra}*)?([eE][-+]?{cyfra}+)?

%%

"//".*$                     {
                                /* ++sLocation.numerLinii; */
                            }

    /* napis */
{identyfikator}             {
                                /* sLocation.leksem= yytext;

                                val->_napis= new std::string( yytext); */

                                TablicaSlowKluczowych _TSK_( Parser::IDENTYFIKATOR);

                                return _TSK_.znajdzSlowo( yytext);
                            }

{literalNapisowy}           {
                                /* sLocation.leksem= yytext;

                                val->_napis= new std::string( yytext); */
                                return Parser::LNAPISOWY;
                            }

    /* liczba */
{liczba}                    {
                                /* sLocation.leksem= yytext;

                                val->_liczba= atof( yytext); */
                                return Parser::LICZBA;
                            }

"=="                        {
                                /* sLocation.leksem= yytext; */
                                return Parser::EQ;
                            }

"!="                        {
                                /* sLocation.leksem= yytext; */
                                return Parser::NEQ;
                            }

"||"                        {
                                /* sLocation.leksem= yytext; */
                                return Parser::OR;
                            }

"&&"                        {
                                /* sLocation.leksem= yytext; */
                                return Parser::AND;
                            }

"::"                        {
                                /* sLocation.leksem= yytext; */
                                return Parser::OPERATOR_ZASIEGU;

                            }


    /* operatory */
[-()<>=+*/;{}.,]            {
                                /* sLocation.leksem= yytext; */
                                return yytext[ 0];
                            }


    /*biale znaki*/
{bialyZnak}                 {/* nie robi nic*/}
{nowaLinia}                 {
                                /* ++sLocation.numerLinii; */
                            }

.                           {
                                /* std::cerr<< "Linia "<< sLocation.numerLinii<< ": Niedozwolony znak: "<< yytext<< std::endl; */
                            }

%%

// Note this needs to be here
// If you define no yywrap() in the options it gets added to the header file
// which leads to multiple definitions if you are not careful.
// http://stackoverflow.com/questions/8013755/using-lex-generated-source-code-in-another-file
int yyFlexLexer::yywrap()   { return 1;} 

