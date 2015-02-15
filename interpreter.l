//TablicaSlowKluczowych _TSK_( Parser::IDENTYFIKATOR);

%name Lekser
%define IOSTREAM

%define LEX_PARAM YY_Parser_STYPE *val

%header{
#include <stdlib.h>
#include <string>

#include "parser.h"
#include "tablicaSlowKluczowych.h"

%}

%define MEMBERS public: SymbolLocation sLocation;

bialyZnak                   [ \t]
nowaLinia                   \n

litera                      [_a-zA-Z]

cyfra			            [0-9]

identyfikator               {litera}({litera}|{cyfra})*
literalNapisowy             \"[^"\n]*\"

liczba                      {cyfra}+(\.{cyfra}*)?([eE][-+]?{cyfra}+)?

%%

"//".*$                     {
                                ++sLocation.numerLinii;
                            }

    /* napis */
{identyfikator}             {
                                sLocation.leksem= yytext;

                                val->_napis= new std::string( yytext);
                                return _TSK_.znajdzSlowo( yytext);
                            }

{literalNapisowy}           {
                                sLocation.leksem= yytext;

                                val->_napis= new std::string( yytext);
                                return Parser::LNAPISOWY;
                            }

    /* liczba */
{liczba}                    {
                                sLocation.leksem= yytext;

                                val->_liczba= atof( yytext);
                                return Parser::LICZBA;
                            }

"=="                        {
                                sLocation.leksem= yytext;
                                return Parser::EQ;
                            }

"!="                        {
                                sLocation.leksem= yytext;
                                return Parser::NEQ;
                            }

"||"                        {
                                sLocation.leksem= yytext;
                                return Parser::OR;
                            }

"&&"                        {
                                sLocation.leksem= yytext;
                                return Parser::AND;
                            }

"::"                        {
                                sLocation.leksem= yytext;
                                return Parser::OPERATOR_ZASIEGU;

                            }


    /* operatory */
[-()<>=+*/;{}.,]            {
                                sLocation.leksem= yytext;
                                return yytext[ 0];
                            }


    /*biale znaki*/
{bialyZnak}                 {/* nie robi nic*/}
{nowaLinia}                 {
                                ++sLocation.numerLinii;
                            }

.                           {
                                std::cerr<< "Linia "<< sLocation.numerLinii<< ": Niedozwolony znak: "<< yytext<< std::endl;
                            }

%%
