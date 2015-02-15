#ifndef YY_Parser_h_included
#define YY_Parser_h_included

#line 1 "D:\\interpreter\\bison++ flex++\\bison.h"
/* before anything */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#else
#endif
#include <stdio.h>

/* #line 14 "D:\\interpreter\\bison++ flex++\\bison.h" */
#line 21 "parser.h"
#line 9 "interpreter.y2"

#include <iostream>
#include <string>

#include "instrukcjaIteracyjnaWhile.h"
#include "instrukcjaIteracyjnaFor.h"
#include "instrukcjaIteracyjnaDoWhile.h"
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

#line 31 "interpreter.y2"
typedef union {
    double _liczba;
    std::string* _napis;

    Czynnik* _czynnik;
    CzynnikUnarny* _czynnikUnarny;
    DefinicjaFunkcji* _definicjaFunkcji;
    Deklaracja* _deklaracja;
    Instrukcja* _instrukcja;
    InstrukcjaDrukowania* _instrukcjaDrukowania;
    InstrukcjaIteracyjnaWhile* _instrukcjaIteracyjnaWhile;
    InstrukcjaIteracyjnaFor* _instrukcjaIteracyjnaFor;
    InstrukcjaIteracyjnaDoWhile* _instrukcjaIteracyjnaDoWhile;
    InstrukcjaPrzypisania* _instrukcjaPrzypisania;
    InstrukcjaSkokuReturn* _instrukcjaSkokuReturn;
    InstrukcjaWarunkowaIf* _instrukcjaWarunkowaIf;
    InstrukcjaWczytywania* _instrukcjaWczytywania;
    InstrukcjaZlozona* _instrukcjaZlozona;
    ListaDeklaracji* _listaDeklaracji;
    ListaFunkcji* _listaFunkcji;
    ListaInstrukcji* _listaInstrukcji;
    ListaParametrow* _listaParametrow;
    ListaWyrazen* _listaWyrazen;
    LiteralNapisowy* _literalNapisowy;
    Nawias* _nawias;
    Parametr* _parametr;
    Program* _program;
    ProsteWyrazenie* _prosteWyrazenie;
    Skladnik* _skladnik;
    Wyrazenie* _wyrazenie;
    WywolanieFunkcji* _wywolanieFunkcji;
    ZmiennaGlobalna* _zmiennaGlobalna;
    ZmiennaLokalna* _zmiennaLokalna;
} yy_Parser_stype;
#define YY_Parser_STYPE yy_Parser_stype
#define YY_Parser_MEMBERS  public: SymbolLocation sLocation;

#line 14 "D:\\interpreter\\bison++ flex++\\bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_Parser_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_Parser_COMPATIBILITY 1
#else
#define  YY_Parser_COMPATIBILITY 0
#endif
#endif

#if YY_Parser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_Parser_LTYPE
#define YY_Parser_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_Parser_STYPE
#define YY_Parser_STYPE YYSTYPE
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/* use %define STYPE */
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_Parser_DEBUG
#define  YY_Parser_DEBUG YYDEBUG
/* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
/* use %define DEBUG */
#endif
#endif
#ifdef YY_Parser_STYPE
#ifndef yystype
#define yystype YY_Parser_STYPE
#endif
#endif
/* use goto to be compatible */
#ifndef YY_Parser_USE_GOTO
#define YY_Parser_USE_GOTO 1
#endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_Parser_USE_GOTO
#define YY_Parser_USE_GOTO 0
#endif

#ifndef YY_Parser_PURE

/* #line 63 "D:\\interpreter\\bison++ flex++\\bison.h" */
#line 134 "parser.h"

#line 63 "D:\\interpreter\\bison++ flex++\\bison.h"
/* YY_Parser_PURE */
#endif

#line 65 "D:\\interpreter\\bison++ flex++\\bison.h"
/* prefix */
#ifndef YY_Parser_DEBUG

/* #line 67 "D:\\interpreter\\bison++ flex++\\bison.h" */
#line 154 "parser.h"

#line 67 "D:\\interpreter\\bison++ flex++\\bison.h"
/* YY_Parser_DEBUG */
#endif
#ifndef YY_Parser_LSP_NEEDED

/* #line 70 "D:\\interpreter\\bison++ flex++\\bison.h" */
#line 162 "parser.h"

#line 70 "D:\\interpreter\\bison++ flex++\\bison.h"
 /* YY_Parser_LSP_NEEDED*/
#endif
/* DEFAULT LTYPE*/
#ifdef YY_Parser_LSP_NEEDED
#ifndef YY_Parser_LTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YY_Parser_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
#ifndef YY_Parser_STYPE
#define YY_Parser_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_Parser_PARSE
#define YY_Parser_PARSE yyparse
#endif
#ifndef YY_Parser_LEX
#define YY_Parser_LEX yylex
#endif
#ifndef YY_Parser_LVAL
#define YY_Parser_LVAL yylval
#endif
#ifndef YY_Parser_LLOC
#define YY_Parser_LLOC yylloc
#endif
#ifndef YY_Parser_CHAR
#define YY_Parser_CHAR yychar
#endif
#ifndef YY_Parser_NERRS
#define YY_Parser_NERRS yynerrs
#endif
#ifndef YY_Parser_DEBUG_FLAG
#define YY_Parser_DEBUG_FLAG yydebug
#endif
#ifndef YY_Parser_ERROR
#define YY_Parser_ERROR yyerror
#endif

#ifndef YY_Parser_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_Parser_PARSE_PARAM
#ifndef YY_Parser_PARSE_PARAM_DEF
#define YY_Parser_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_Parser_PARSE_PARAM
#define YY_Parser_PARSE_PARAM void
#endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

#ifndef YY_Parser_PURE
extern YY_Parser_STYPE YY_Parser_LVAL;
#endif


/* #line 143 "D:\\interpreter\\bison++ flex++\\bison.h" */
#line 240 "parser.h"
#define	LICZBA	258
#define	IDENTYFIKATOR	259
#define	LNAPISOWY	260
#define	DOUBLE	261
#define	STRING	262
#define	WHILE	263
#define	FOR	264
#define	DO	265
#define	IF	266
#define	RETURN	267
#define	MAIN	268
#define	PRINTF	269
#define	SCANF	270
#define	ENDL	271
#define	IFX	272
#define	ELSE	273
#define	EQ	274
#define	NEQ	275
#define	OR	276
#define	AND	277
#define	UMINUS	278
#define	OPERATOR_ZASIEGU	279


#line 143 "D:\\interpreter\\bison++ flex++\\bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
#ifndef YY_Parser_CLASS
#define YY_Parser_CLASS Parser
#endif

#ifndef YY_Parser_INHERIT
#define YY_Parser_INHERIT
#endif
#ifndef YY_Parser_MEMBERS
#define YY_Parser_MEMBERS
#endif
#ifndef YY_Parser_LEX_BODY
#define YY_Parser_LEX_BODY
#endif
#ifndef YY_Parser_ERROR_BODY
#define YY_Parser_ERROR_BODY
#endif
#ifndef YY_Parser_CONSTRUCTOR_PARAM
#define YY_Parser_CONSTRUCTOR_PARAM
#endif
/* choose between enum and const */
#ifndef YY_Parser_USE_CONST_TOKEN
#define YY_Parser_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */
#endif
#if YY_Parser_USE_CONST_TOKEN != 0
#ifndef YY_Parser_ENUM_TOKEN
#define YY_Parser_ENUM_TOKEN yy_Parser_enum_token
#endif
#endif

class YY_Parser_CLASS YY_Parser_INHERIT
{
public:
#if YY_Parser_USE_CONST_TOKEN != 0
/* static const int token ... */

/* #line 182 "D:\\interpreter\\bison++ flex++\\bison.h" */
#line 307 "parser.h"
static const int LICZBA;
static const int IDENTYFIKATOR;
static const int LNAPISOWY;
static const int DOUBLE;
static const int STRING;
static const int WHILE;
static const int FOR;
static const int DO;
static const int IF;
static const int RETURN;
static const int MAIN;
static const int PRINTF;
static const int SCANF;
static const int ENDL;
static const int IFX;
static const int ELSE;
static const int EQ;
static const int NEQ;
static const int OR;
static const int AND;
static const int UMINUS;
static const int OPERATOR_ZASIEGU;


#line 182 "D:\\interpreter\\bison++ flex++\\bison.h"
 /* decl const */
#else
enum YY_Parser_ENUM_TOKEN { YY_Parser_NULL_TOKEN=0

/* #line 185 "D:\\interpreter\\bison++ flex++\\bison.h" */
#line 338 "parser.h"
	,LICZBA=258
	,IDENTYFIKATOR=259
	,LNAPISOWY=260
	,DOUBLE=261
	,STRING=262
	,WHILE=263
	,FOR=264
	,DO=265
	,IF=266
	,RETURN=267
	,MAIN=268
	,PRINTF=269
	,SCANF=270
	,ENDL=271
	,IFX=272
	,ELSE=273
	,EQ=274
	,NEQ=275
	,OR=276
	,AND=277
	,UMINUS=278
	,OPERATOR_ZASIEGU=279


#line 185 "D:\\interpreter\\bison++ flex++\\bison.h"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_Parser_PARSE(YY_Parser_PARSE_PARAM);
 virtual void YY_Parser_ERROR(char *msg) YY_Parser_ERROR_BODY;
#ifdef YY_Parser_PURE
#ifdef YY_Parser_LSP_NEEDED
 virtual int  YY_Parser_LEX(YY_Parser_STYPE *YY_Parser_LVAL,YY_Parser_LTYPE *YY_Parser_LLOC) YY_Parser_LEX_BODY;
#else
 virtual int  YY_Parser_LEX(YY_Parser_STYPE *YY_Parser_LVAL) YY_Parser_LEX_BODY;
#endif
#else
 virtual int YY_Parser_LEX() YY_Parser_LEX_BODY;
 YY_Parser_STYPE YY_Parser_LVAL;
#ifdef YY_Parser_LSP_NEEDED
 YY_Parser_LTYPE YY_Parser_LLOC;
#endif
 int YY_Parser_NERRS;
 int YY_Parser_CHAR;
#endif
#if YY_Parser_DEBUG != 0
public:
 int YY_Parser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
#endif
public:
 YY_Parser_CLASS(YY_Parser_CONSTRUCTOR_PARAM);
public:
 YY_Parser_MEMBERS
};
/* other declare folow */
#endif


#if YY_Parser_COMPATIBILITY != 0
/* backward compatibility */
#ifndef YYSTYPE
#define YYSTYPE YY_Parser_STYPE
#endif

#ifndef YYLTYPE
#define YYLTYPE YY_Parser_LTYPE
#endif
#ifndef YYDEBUG
#ifdef YY_Parser_DEBUG
#define YYDEBUG YY_Parser_DEBUG
#endif
#endif

#endif
/* END */

/* #line 236 "D:\\interpreter\\bison++ flex++\\bison.h" */
#line 417 "parser.h"
#endif
