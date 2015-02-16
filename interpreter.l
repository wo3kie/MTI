/* KeywordTable _TSK_( Parser::IDENTIFIER); */

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

whiteChar                   [ \t]
newLine                     \n

letter                      [_a-zA-Z]

digit			            [0-9]

identifier                  {letter}({letter}|{digit})*
testLiteral                 \"[^"\n]*\"

number                      {digit}+(\.{digit}*)?([eE][-+]?{digit}+)?

%%

"//".*$                     {
                                /* ++sLocation.lineNumber; */
                            }

    /* napis */
{identifier}             {
                                /* sLocation.token= yytext;

                                val->_text= new std::string( yytext); */

                                KeywordTable _TSK_( Parser::IDENTIFIER);

                                return _TSK_.findKeyword( yytext);
                            }

{testLiteral}           {
                                /* sLocation.token= yytext;

                                val->_text= new std::string( yytext); */
                                return Parser::TEXTLITERAL;
                            }

    /* number */
{number}                    {
                                /* sLocation.token= yytext;

                                val->_number= atof( yytext); */
                                return Parser::NUMBER;
                            }

"=="                        {
                                /* sLocation.token= yytext; */
                                return Parser::EQ;
                            }

"!="                        {
                                /* sLocation.token= yytext; */
                                return Parser::NEQ;
                            }

"||"                        {
                                /* sLocation.token= yytext; */
                                return Parser::OR;
                            }

"&&"                        {
                                /* sLocation.token= yytext; */
                                return Parser::AND;
                            }

"::"                        {
                                /* sLocation.token= yytext; */
                                return Parser::SCOPE_OPERATOR;

                            }


    /* operatory */
[-()<>=+*/;{}.,]            {
                                /* sLocation.token= yytext; */
                                return yytext[ 0];
                            }


    /*biale znaki*/
{whiteChar}                 {/* nie robi nic*/}
{newLine}                 {
                                /* ++sLocation.lineNumber; */
                            }

.                           {
                                /* std::cerr<< "Linia "<< sLocation.lineNumber<< ": Niedozwolony znak: "<< yytext<< std::endl; */
                            }

%%

// Note this needs to be here
// If you define no yywrap() in the options it gets added to the header file
// which leads to multiple definitions if you are not careful.
// http://stackoverflow.com/questions/8013755/using-lex-generated-source-code-in-another-file
int yyFlexLexer::yywrap()   { return 1;} 

