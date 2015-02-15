/* TablicaSlowKluczowych _TSK_( Parser::IDENTYFIKATOR); */

/* %name Lekser */
/* %define IOSTREAM */

/* %define LEX_PARAM YY_Parser_STYPE *val */

%{
#include <stdlib.h>
#include <string>

#include "factor.h"
#include "unaryFactor.h"
#include "functionDefinition.h"
#include "whileInstruction.h"
#include "assignmentInstruction.h"
#include "returnInstruction.h"
#include "ifStatement.h"
#include "ioInstructions.h"
#include "number.h"
#include "list.h"
#include "textLiteral.h"
#include "bracket.h"
#include "program.h"
#include "symbolLocation.h"
#include "value.h"
#include "expression.h"
#include "functionCall.h"

#include "parser.h"
#include "keywordTable.h"
%}

%option outfile="lexer.cpp" header-file="lexer.h"
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

