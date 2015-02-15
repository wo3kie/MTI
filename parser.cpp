#define YY_Parser_h_included

/*  A Bison++ parser, made from interpreter.y2  */

 /* with Bison++ version bison++ Version 1.21-8, adapted from GNU bison by coetmeur@icdc.fr
  */


#line 1 "D:\\interpreter\\bison++ flex++\\bison.cc"
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* HEADER SECTION */
#if defined( _MSDOS ) || defined(MSDOS) || defined(__MSDOS__)
#define __MSDOS_AND_ALIKE
#endif
#if defined(_WINDOWS) && defined(_MSC_VER)
#define __HAVE_NO_ALLOCA
#define __MSDOS_AND_ALIKE
#endif

#ifndef alloca
#if defined( __GNUC__)
#define alloca __builtin_alloca

#elif (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)  || defined (__sgi)
#include <alloca.h>

#elif defined (__MSDOS_AND_ALIKE)
#include <malloc.h>
#ifndef __TURBOC__
/* MS C runtime lib */
#define alloca _alloca
#endif

#elif defined(_AIX)
#include <malloc.h>
#pragma alloca

#elif defined(__hpux)
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */

#endif /* not _AIX  not MSDOS, or __TURBOC__ or _AIX, not sparc.  */
#endif /* alloca not defined.  */
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
#ifndef __STDC__
#define const
#endif
#endif
#include <stdio.h>
#define YYBISON 1

/* #line 73 "D:\\interpreter\\bison++ flex++\\bison.cc" */
#line 85 "parser.cpp"
#line 5 "interpreter.y2"

void *alloca (unsigned int){}; // bez tego XBuilder si� wyk�ada :)
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

#line 73 "D:\\interpreter\\bison++ flex++\\bison.cc"
/* %{ and %header{ and %union, during decl */
#define YY_Parser_BISON 1
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
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_Parser_STYPE
#define YY_Parser_STYPE YYSTYPE
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_Parser_DEBUG
#define  YY_Parser_DEBUG YYDEBUG
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

/* #line 117 "D:\\interpreter\\bison++ flex++\\bison.cc" */
#line 196 "parser.cpp"

#line 117 "D:\\interpreter\\bison++ flex++\\bison.cc"
/*  YY_Parser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

#line 121 "D:\\interpreter\\bison++ flex++\\bison.cc"
/* prefix */
#ifndef YY_Parser_DEBUG

/* #line 123 "D:\\interpreter\\bison++ flex++\\bison.cc" */
#line 218 "parser.cpp"

#line 123 "D:\\interpreter\\bison++ flex++\\bison.cc"
/* YY_Parser_DEBUG */
#endif


#ifndef YY_Parser_LSP_NEEDED

/* #line 128 "D:\\interpreter\\bison++ flex++\\bison.cc" */
#line 228 "parser.cpp"

#line 128 "D:\\interpreter\\bison++ flex++\\bison.cc"
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
      /* We used to use `unsigned long' as YY_Parser_STYPE on MSDOS,
	 but it seems better to be consistent.
	 Most programs should declare their own type anyway.  */

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
#if YY_Parser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YY_Parser_LTYPE
#ifndef YYLTYPE
#define YYLTYPE YY_Parser_LTYPE
#else
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
#endif
#endif
#ifndef YYSTYPE
#define YYSTYPE YY_Parser_STYPE
#else
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
#endif
#ifdef YY_Parser_PURE
#ifndef YYPURE
#define YYPURE YY_Parser_PURE
#endif
#endif
#ifdef YY_Parser_DEBUG
#ifndef YYDEBUG
#define YYDEBUG YY_Parser_DEBUG
#endif
#endif
#ifndef YY_Parser_ERROR_VERBOSE
#ifdef YYERROR_VERBOSE
#define YY_Parser_ERROR_VERBOSE YYERROR_VERBOSE
#endif
#endif
#ifndef YY_Parser_LSP_NEEDED
#ifdef YYLSP_NEEDED
#define YY_Parser_LSP_NEEDED YYLSP_NEEDED
#endif
#endif
#endif
#ifndef YY_USE_CLASS
/* TOKEN C */

/* #line 236 "D:\\interpreter\\bison++ flex++\\bison.cc" */
#line 341 "parser.cpp"
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


#line 236 "D:\\interpreter\\bison++ flex++\\bison.cc"
 /* #defines tokens */
#else
/* CLASS */
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
#ifndef YY_Parser_CONSTRUCTOR_CODE
#define YY_Parser_CONSTRUCTOR_CODE
#endif
#ifndef YY_Parser_CONSTRUCTOR_INIT
#define YY_Parser_CONSTRUCTOR_INIT
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

/* #line 280 "D:\\interpreter\\bison++ flex++\\bison.cc" */
#line 413 "parser.cpp"
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


#line 280 "D:\\interpreter\\bison++ flex++\\bison.cc"
 /* decl const */
#else
enum YY_Parser_ENUM_TOKEN { YY_Parser_NULL_TOKEN=0

/* #line 283 "D:\\interpreter\\bison++ flex++\\bison.cc" */
#line 444 "parser.cpp"
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


#line 283 "D:\\interpreter\\bison++ flex++\\bison.cc"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_Parser_PARSE (YY_Parser_PARSE_PARAM);
 virtual void YY_Parser_ERROR(char *msg) YY_Parser_ERROR_BODY;
#ifdef YY_Parser_PURE
#ifdef YY_Parser_LSP_NEEDED
 virtual int  YY_Parser_LEX (YY_Parser_STYPE *YY_Parser_LVAL,YY_Parser_LTYPE *YY_Parser_LLOC) YY_Parser_LEX_BODY;
#else
 virtual int  YY_Parser_LEX (YY_Parser_STYPE *YY_Parser_LVAL) YY_Parser_LEX_BODY;
#endif
#else
 virtual int YY_Parser_LEX() YY_Parser_LEX_BODY;
 YY_Parser_STYPE YY_Parser_LVAL;
#ifdef YY_Parser_LSP_NEEDED
 YY_Parser_LTYPE YY_Parser_LLOC;
#endif
 int   YY_Parser_NERRS;
 int    YY_Parser_CHAR;
#endif
#if YY_Parser_DEBUG != 0
 int YY_Parser_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_Parser_CLASS(YY_Parser_CONSTRUCTOR_PARAM);
public:
 YY_Parser_MEMBERS
};
/* other declare folow */
#if YY_Parser_USE_CONST_TOKEN != 0

/* #line 314 "D:\\interpreter\\bison++ flex++\\bison.cc" */
#line 503 "parser.cpp"
const int YY_Parser_CLASS::LICZBA=258;
const int YY_Parser_CLASS::IDENTYFIKATOR=259;
const int YY_Parser_CLASS::LNAPISOWY=260;
const int YY_Parser_CLASS::DOUBLE=261;
const int YY_Parser_CLASS::STRING=262;
const int YY_Parser_CLASS::WHILE=263;
const int YY_Parser_CLASS::FOR=264;
const int YY_Parser_CLASS::DO=265;
const int YY_Parser_CLASS::IF=266;
const int YY_Parser_CLASS::RETURN=267;
const int YY_Parser_CLASS::MAIN=268;
const int YY_Parser_CLASS::PRINTF=269;
const int YY_Parser_CLASS::SCANF=270;
const int YY_Parser_CLASS::ENDL=271;
const int YY_Parser_CLASS::IFX=272;
const int YY_Parser_CLASS::ELSE=273;
const int YY_Parser_CLASS::EQ=274;
const int YY_Parser_CLASS::NEQ=275;
const int YY_Parser_CLASS::OR=276;
const int YY_Parser_CLASS::AND=277;
const int YY_Parser_CLASS::UMINUS=278;
const int YY_Parser_CLASS::OPERATOR_ZASIEGU=279;


#line 314 "D:\\interpreter\\bison++ flex++\\bison.cc"
 /* const YY_Parser_CLASS::token */
#endif
/*apres const  */
YY_Parser_CLASS::YY_Parser_CLASS(YY_Parser_CONSTRUCTOR_PARAM) YY_Parser_CONSTRUCTOR_INIT
{
#if YY_Parser_DEBUG != 0
YY_Parser_DEBUG_FLAG=0;
#endif
YY_Parser_CONSTRUCTOR_CODE;
};
#endif

/* #line 325 "D:\\interpreter\\bison++ flex++\\bison.cc" */
#line 542 "parser.cpp"


#define	YYFINAL		167
#define	YYFLAG		32768
#define	YYNTBASE	38

#define YYTRANSLATE(x) ((unsigned)(x) <= 279 ? yytranslate[x] : 66)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
    34,    27,    25,    35,    26,     2,    28,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    31,    20,
    32,    19,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    36,     2,    37,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    21,    22,    23,    24,    29,    30
};

#if YY_Parser_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     5,     8,    10,    14,    20,    24,    30,    33,
    35,    42,    49,    53,    55,    56,    59,    62,    64,    66,
    68,    70,    72,    74,    76,    78,    80,    82,    85,    89,
    92,    94,    99,   105,   111,   119,   125,   134,   144,   148,
   154,   160,   166,   172,   176,   180,   184,   188,   192,   196,
   198,   202,   206,   208,   212,   216,   218,   220,   223,   226,
   228,   230,   232,   234,   236,   238,   240,   243,   248,   252,
   254,   255
};

static const short yyrhs[] = {    39,
    41,     0,    41,     0,    39,    40,     0,    40,     0,     6,
     4,    31,     0,     6,     4,    32,     3,    31,     0,     7,
     4,    31,     0,     7,     4,    32,     5,    31,     0,    41,
    42,     0,    42,     0,     6,     4,    33,    43,    34,    45,
     0,     7,     4,    33,    43,    34,    45,     0,    43,    35,
    44,     0,    44,     0,     0,     6,     4,     0,     7,     4,
     0,    48,     0,    46,     0,    49,     0,    50,     0,    51,
     0,    52,     0,    53,     0,    54,     0,    55,     0,    40,
     0,    63,    31,     0,    36,    47,    37,     0,    47,    45,
     0,    45,     0,     4,    32,    56,    31,     0,    30,     4,
    32,    56,    31,     0,    11,    33,    56,    34,    45,     0,
    11,    33,    56,    34,    45,    18,    45,     0,     8,    33,
    56,    34,    45,     0,     9,    33,    40,    56,    31,    48,
    34,    45,     0,    10,    36,    47,    37,     8,    33,    56,
    34,    31,     0,    12,    56,    31,     0,    14,    33,    56,
    34,    31,     0,    14,    33,    16,    34,    31,     0,    15,
    33,    61,    34,    31,     0,    15,    33,    62,    34,    31,
     0,    56,    20,    57,     0,    56,    19,    57,     0,    56,
    21,    57,     0,    56,    22,    57,     0,    56,    23,    57,
     0,    56,    24,    57,     0,    57,     0,    57,    25,    58,
     0,    57,    26,    58,     0,    58,     0,    58,    27,    59,
     0,    58,    28,    59,     0,    59,     0,    60,     0,    25,
    60,     0,    26,    60,     0,    61,     0,    62,     0,    63,
     0,     3,     0,     5,     0,    65,     0,     4,     0,    30,
     4,     0,     4,    33,    64,    34,     0,    64,    35,    56,
     0,    56,     0,     0,    33,    56,    34,     0
};

#endif

#if YY_Parser_DEBUG != 0
static const short yyrline[] = { 0,
   111,   113,   116,   118,   121,   123,   124,   125,   128,   130,
   133,   136,   140,   142,   143,   146,   148,   151,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   165,   169,
   171,   174,   176,   180,   183,   187,   191,   196,   200,   204,
   206,   209,   211,   214,   216,   217,   218,   219,   220,   221,
   224,   226,   227,   230,   232,   233,   236,   238,   239,   242,
   244,   245,   246,   247,   248,   251,   255,   259,   263,   265,
   266,   269
};

static const char * const yytname[] = {   "$","error","$illegal.","LICZBA","IDENTYFIKATOR",
"LNAPISOWY","DOUBLE","STRING","WHILE","FOR","DO","IF","RETURN","MAIN","PRINTF",
"SCANF","ENDL","IFX","ELSE","'>'","'<'","EQ","NEQ","OR","AND","'+'","'-'","'*'",
"'/'","UMINUS","OPERATOR_ZASIEGU","';'","'='","'('","')'","','","'{'","'}'",
"program","listaDeklaracji","deklaracja","listaFunkcji","definicjaFunkcji","listaParametrow",
"parametr","instrukcja","instrukcjaZlozona","listaInstrukcji","instrukcjaPrzypisania",
"instrukcjaWarunkowaIf","instrukcjaIteracyjnaWhile","instrukcjaIteracyjnaFor",
"instrukcjaIteracyjnaDoWhile","instrukcjaSkokuReturn","instrukcjaDrukowania",
"instrukcjaWczytywania","wyrazenie","prosteWyrazenie","skladnik","czynnikUnarny",
"czynnik","zmiennaLokalna","zmiennaGlobalna","wywolanieFunkcji","listaWyrazen",
"nawias",""
};
#endif

static const short yyr1[] = {     0,
    38,    38,    39,    39,    40,    40,    40,    40,    41,    41,
    42,    42,    43,    43,    43,    44,    44,    45,    45,    45,
    45,    45,    45,    45,    45,    45,    45,    45,    46,    47,
    47,    48,    48,    49,    49,    50,    51,    52,    53,    54,
    54,    55,    55,    56,    56,    56,    56,    56,    56,    56,
    57,    57,    57,    58,    58,    58,    59,    59,    59,    60,
    60,    60,    60,    60,    60,    61,    62,    63,    64,    64,
    64,    65
};

static const short yyr2[] = {     0,
     2,     1,     2,     1,     3,     5,     3,     5,     2,     1,
     6,     6,     3,     1,     0,     2,     2,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
     1,     4,     5,     5,     7,     5,     8,     9,     3,     5,
     5,     5,     5,     3,     3,     3,     3,     3,     3,     1,
     3,     3,     1,     3,     3,     1,     1,     2,     2,     1,
     1,     1,     1,     1,     1,     1,     2,     4,     3,     1,
     0,     3
};

static const short yydefact[] = {     0,
     0,     0,     0,     4,     2,    10,     0,     0,     3,     1,
     0,     0,     9,     5,     0,    15,     7,     0,    15,     0,
     0,     0,     0,     0,     0,    14,     0,     0,     6,    16,
    17,     0,     0,     8,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    27,    11,    19,
    18,    20,    21,    22,    23,    24,    25,    26,     0,    13,
    12,     0,    71,     0,     0,     0,     0,     0,     0,    63,
    66,    64,     0,     0,     0,     0,     0,    50,    53,    56,
    57,    60,    61,    62,    65,     0,     0,     0,    31,     0,
    28,     0,    70,     0,     0,     0,     0,     0,    58,    59,
    67,     0,     0,     0,     0,     0,     0,     0,    39,     0,
     0,     0,     0,     0,     0,    66,     0,     0,     0,    29,
    30,    32,    68,     0,     0,     0,     0,     0,    72,    45,
    44,    46,    47,    48,    49,    51,    52,    54,    55,     0,
     0,     0,     0,     0,    69,    36,     0,     0,    34,    41,
    40,    42,    43,    33,     0,     0,     0,     0,     0,     0,
    35,    37,     0,    38,     0,     0,     0
};

static const short yydefgoto[] = {   165,
     3,    48,     5,     6,    25,    26,    89,    50,    90,    51,
    52,    53,    54,    55,    56,    57,    58,    77,    78,    79,
    80,    81,    82,    83,    84,    94,    85
};

static const short yypact[] = {    27,
    -3,     0,    27,-32768,    55,-32768,    18,    24,-32768,    55,
    10,    40,-32768,-32768,     9,    63,-32768,    36,    63,   -11,
    19,    28,    44,    60,    37,-32768,    35,    69,-32768,-32768,
-32768,   104,    63,-32768,   104,    91,    79,    82,    61,    64,
    73,    66,    13,    72,    84,   121,   104,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    42,-32768,
-32768,    13,    13,   105,   107,    13,   138,   104,    13,-32768,
   102,-32768,   127,   127,   142,    13,   176,   123,   131,-32768,
-32768,-32768,-32768,-32768,-32768,   117,     5,   109,-32768,    17,
-32768,   189,   214,   128,    68,    13,    70,   132,-32768,-32768,
-32768,   148,    13,    13,    13,    13,    13,    13,-32768,    13,
    13,    13,    13,   147,   154,-32768,   151,   152,    13,-32768,
-32768,-32768,-32768,    13,   104,   195,   153,   104,-32768,   123,
   123,   123,   123,   123,   123,   131,   131,-32768,-32768,   156,
   171,   172,   174,   208,   214,-32768,    15,   168,   188,-32768,
-32768,-32768,-32768,-32768,   190,   187,    13,   104,   104,   170,
-32768,-32768,   192,-32768,   224,   225,-32768
};

static const short yypgoto[] = {-32768,
-32768,     8,   243,    32,   228,   215,   -30,-32768,   181,   103,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -56,   137,    54,
    67,   110,   164,   165,   -32,-32768,-32768
};


#define	YYLAST		252


static const short yytable[] = {    59,
     7,    49,    59,     8,    61,    92,    93,     4,   116,    95,
     9,    22,    98,    20,    59,    70,    71,    72,   155,   102,
    36,    16,    37,    38,    39,    40,    41,    42,    43,   115,
    44,    45,     1,     2,    75,    59,    13,    73,    74,   126,
    27,    13,    75,    21,    46,    76,    46,    30,    14,    15,
    16,    19,    47,   120,    17,    18,    19,    59,    29,   121,
    11,    12,   144,    31,    59,    34,   121,   145,    23,    24,
    32,    33,    91,    36,    96,    37,    38,    39,    40,    41,
    42,    43,    64,    44,    45,    65,   103,   104,   105,   106,
   107,   108,    59,    66,   146,    59,    67,   149,    69,    46,
   160,   125,    35,    33,    86,    47,   127,    36,    68,    37,
    38,    39,    40,    41,    42,    43,    87,    44,    45,    70,
    71,    72,    62,    63,    88,    59,    59,   161,   162,    70,
    71,    72,   114,    46,    63,    14,    15,    17,    18,    47,
   119,    73,    74,    37,    38,   101,    75,   110,   111,    76,
   103,   104,   105,   106,   107,   108,    75,   112,   113,    76,
   148,   123,   124,   136,   137,   128,   103,   104,   105,   106,
   107,   108,   103,   104,   105,   106,   107,   108,   138,   139,
   140,   129,    99,   100,   142,   143,   150,   141,   103,   104,
   105,   106,   107,   108,   103,   104,   105,   106,   107,   108,
   157,   151,   152,   163,   153,   158,   109,   103,   104,   105,
   106,   107,   108,   103,   104,   105,   106,   107,   108,   122,
   159,    62,   164,   166,   167,   147,   103,   104,   105,   106,
   107,   108,   103,   104,   105,   106,   107,   108,   154,   130,
   131,   132,   133,   134,   135,    10,    28,    60,    97,   156,
   117,   118
};

static const short yycheck[] = {    32,
     4,    32,    35,     4,    35,    62,    63,     0,     4,    66,
     3,     3,    69,     4,    47,     3,     4,     5,     4,    76,
     4,    33,     6,     7,     8,     9,    10,    11,    12,    86,
    14,    15,     6,     7,    30,    68,     5,    25,    26,    96,
     5,    10,    30,     4,    30,    33,    30,     4,    31,    32,
    33,    33,    36,    37,    31,    32,    33,    90,    31,    90,
     6,     7,   119,     4,    97,    31,    97,   124,     6,     7,
    34,    35,    31,     4,    67,     6,     7,     8,     9,    10,
    11,    12,     4,    14,    15,     4,    19,    20,    21,    22,
    23,    24,   125,    33,   125,   128,    33,   128,    33,    30,
   157,    34,    34,    35,    33,    36,    37,     4,    36,     6,
     7,     8,     9,    10,    11,    12,    33,    14,    15,     3,
     4,     5,    32,    33,     4,   158,   159,   158,   159,     3,
     4,     5,    16,    30,    33,    31,    32,    31,    32,    36,
    32,    25,    26,     6,     7,     4,    30,    25,    26,    33,
    19,    20,    21,    22,    23,    24,    30,    27,    28,    33,
     8,    34,    35,   110,   111,    34,    19,    20,    21,    22,
    23,    24,    19,    20,    21,    22,    23,    24,   112,   113,
    34,    34,    73,    74,    34,    34,    31,    34,    19,    20,
    21,    22,    23,    24,    19,    20,    21,    22,    23,    24,
    33,    31,    31,    34,    31,    18,    31,    19,    20,    21,
    22,    23,    24,    19,    20,    21,    22,    23,    24,    31,
    34,    32,    31,     0,     0,    31,    19,    20,    21,    22,
    23,    24,    19,    20,    21,    22,    23,    24,    31,   103,
   104,   105,   106,   107,   108,     3,    19,    33,    68,   147,
    87,    87
};

#line 325 "D:\\interpreter\\bison++ flex++\\bison.cc"
 /* fattrs + tables */

/* parser code folow  */


/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: dollar marks section change
   the next  is replaced by the list of actions, each action
   as one case of the switch.  */

#if YY_Parser_USE_GOTO != 0
/*
 SUPRESSION OF GOTO : on some C++ compiler (sun c++)
  the goto is strictly forbidden if any constructor/destructor
  is used in the whole function (very stupid isn't it ?)
 so goto are to be replaced with a 'while/switch/case construct'
 here are the macro to keep some apparent compatibility
*/
#define YYGOTO(lb) {yy_gotostate=lb;continue;}
#define YYBEGINGOTO  enum yy_labels yy_gotostate=yygotostart; \
                     for(;;) switch(yy_gotostate) { case yygotostart: {
#define YYLABEL(lb) } case lb: {
#define YYENDGOTO } }
#define YYBEGINDECLARELABEL enum yy_labels {yygotostart
#define YYDECLARELABEL(lb) ,lb
#define YYENDDECLARELABEL  };
#else
/* macro to keep goto */
#define YYGOTO(lb) goto lb
#define YYBEGINGOTO
#define YYLABEL(lb) lb:
#define YYENDGOTO
#define YYBEGINDECLARELABEL
#define YYDECLARELABEL(lb)
#define YYENDDECLARELABEL
#endif
/* LABEL DECLARATION */
YYBEGINDECLARELABEL
  YYDECLARELABEL(yynewstate)
  YYDECLARELABEL(yybackup)
/* YYDECLARELABEL(yyresume) */
  YYDECLARELABEL(yydefault)
  YYDECLARELABEL(yyreduce)
  YYDECLARELABEL(yyerrlab)   /* here on detecting error */
  YYDECLARELABEL(yyerrlab1)   /* here on error raised explicitly by an action */
  YYDECLARELABEL(yyerrdefault)  /* current state does not do anything special for the error token. */
  YYDECLARELABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */
  YYDECLARELABEL(yyerrhandle)
YYENDDECLARELABEL
/* ALLOCA SIMULATION */
/* __HAVE_NO_ALLOCA */
#ifdef __HAVE_NO_ALLOCA
int __alloca_free_ptr(char *ptr,char *ref)
{if(ptr!=ref) free(ptr);
 return 0;}

#define __ALLOCA_alloca(size) malloc(size)
#define __ALLOCA_free(ptr,ref) __alloca_free_ptr((char *)ptr,(char *)ref)

#ifdef YY_Parser_LSP_NEEDED
#define __ALLOCA_return(num) \
            return( __ALLOCA_free(yyss,yyssa)+\
		    __ALLOCA_free(yyvs,yyvsa)+\
		    __ALLOCA_free(yyls,yylsa)+\
		   (num))
#else
#define __ALLOCA_return(num) \
            return( __ALLOCA_free(yyss,yyssa)+\
		    __ALLOCA_free(yyvs,yyvsa)+\
		   (num))
#endif
#else
#define __ALLOCA_return(num) return(num)
#define __ALLOCA_alloca(size) alloca(size)
#define __ALLOCA_free(ptr,ref)
#endif

/* ENDALLOCA SIMULATION */

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (YY_Parser_CHAR = YYEMPTY)
#define YYEMPTY         -2
#define YYEOF           0
#define YYACCEPT        __ALLOCA_return(0)
#define YYABORT         __ALLOCA_return(1)
#define YYERROR         YYGOTO(yyerrlab1)
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL          YYGOTO(yyerrlab)
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do                                                              \
  if (YY_Parser_CHAR == YYEMPTY && yylen == 1)                               \
    { YY_Parser_CHAR = (token), YY_Parser_LVAL = (value);                 \
      yychar1 = YYTRANSLATE (YY_Parser_CHAR);                                \
      YYPOPSTACK;                                               \
      YYGOTO(yybackup);                                            \
    }                                                           \
  else                                                          \
    { YY_Parser_ERROR ("syntax error: cannot back up"); YYERROR; }   \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YY_Parser_PURE
/* UNPURE */
#define YYLEX           YY_Parser_LEX()
#ifndef YY_USE_CLASS
/* If nonreentrant, and not class , generate the variables here */
int     YY_Parser_CHAR;                      /*  the lookahead symbol        */
YY_Parser_STYPE      YY_Parser_LVAL;              /*  the semantic value of the */
				/*  lookahead symbol    */
int YY_Parser_NERRS;                 /*  number of parse errors so far */
#ifdef YY_Parser_LSP_NEEDED
YY_Parser_LTYPE YY_Parser_LLOC;   /*  location data for the lookahead     */
			/*  symbol                              */
#endif
#endif


#else
/* PURE */
#ifdef YY_Parser_LSP_NEEDED
#define YYLEX           YY_Parser_LEX(&YY_Parser_LVAL, &YY_Parser_LLOC)
#else
#define YYLEX           YY_Parser_LEX(&YY_Parser_LVAL)
#endif
#endif
#ifndef YY_USE_CLASS
#if YY_Parser_DEBUG != 0
int YY_Parser_DEBUG_FLAG;                    /*  nonzero means print parse trace     */
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif
#endif



/*  YYINITDEPTH indicates the initial size of the parser's stacks       */

#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif


#if __GNUC__ > 1                /* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)       __builtin_memcpy(TO,FROM,COUNT)
#else                           /* not GNU C or C++ */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */

#ifdef __cplusplus
static void __yy_bcopy (char *from, char *to, int count)
#else
#ifdef __STDC__
static void __yy_bcopy (char *from, char *to, int count)
#else
static void __yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
#endif
#endif
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}
#endif

int
#ifdef YY_USE_CLASS
 YY_Parser_CLASS::
#endif
     YY_Parser_PARSE(YY_Parser_PARSE_PARAM)
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
/* parameter definition without protypes */
YY_Parser_PARSE_PARAM_DEF
#endif
#endif
#endif
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YY_Parser_STYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1=0;          /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YY_Parser_STYPE yyvsa[YYINITDEPTH];        /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YY_Parser_STYPE *yyvs = yyvsa;     /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YY_Parser_LSP_NEEDED
  YY_Parser_LTYPE yylsa[YYINITDEPTH];        /*  the location stack                  */
  YY_Parser_LTYPE *yyls = yylsa;
  YY_Parser_LTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YY_Parser_PURE
  int YY_Parser_CHAR;
  YY_Parser_STYPE YY_Parser_LVAL;
  int YY_Parser_NERRS;
#ifdef YY_Parser_LSP_NEEDED
  YY_Parser_LTYPE YY_Parser_LLOC;
#endif
#endif

  YY_Parser_STYPE yyval;             /*  the variable used to return         */
				/*  semantic values from the action     */
				/*  routines                            */

  int yylen;
/* start loop, in which YYGOTO may be used. */
YYBEGINGOTO

#if YY_Parser_DEBUG != 0
  if (YY_Parser_DEBUG_FLAG)
    fprintf(stderr, "Starting parse\n");
#endif
  yystate = 0;
  yyerrstatus = 0;
  YY_Parser_NERRS = 0;
  YY_Parser_CHAR = YYEMPTY;          /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YY_Parser_LSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
YYLABEL(yynewstate)

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YY_Parser_STYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YY_Parser_LSP_NEEDED
      YY_Parser_LTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YY_Parser_LSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YY_Parser_LSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  YY_Parser_ERROR("parser stack overflow");
	  __ALLOCA_return(2);
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) __ALLOCA_alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      __ALLOCA_free(yyss1,yyssa);
      yyvs = (YY_Parser_STYPE *) __ALLOCA_alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
      __ALLOCA_free(yyvs1,yyvsa);
#ifdef YY_Parser_LSP_NEEDED
      yyls = (YY_Parser_LTYPE *) __ALLOCA_alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
      __ALLOCA_free(yyls1,yylsa);
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YY_Parser_LSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YY_Parser_DEBUG != 0
      if (YY_Parser_DEBUG_FLAG)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YY_Parser_DEBUG != 0
  if (YY_Parser_DEBUG_FLAG)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  YYGOTO(yybackup);
YYLABEL(yybackup)

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* YYLABEL(yyresume) */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yydefault);

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (YY_Parser_CHAR == YYEMPTY)
    {
#if YY_Parser_DEBUG != 0
      if (YY_Parser_DEBUG_FLAG)
	fprintf(stderr, "Reading a token: ");
#endif
      YY_Parser_CHAR = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (YY_Parser_CHAR <= 0)           /* This means end of input. */
    {
      yychar1 = 0;
      YY_Parser_CHAR = YYEOF;                /* Don't call YYLEX any more */

#if YY_Parser_DEBUG != 0
      if (YY_Parser_DEBUG_FLAG)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(YY_Parser_CHAR);

#if YY_Parser_DEBUG != 0
      if (YY_Parser_DEBUG_FLAG)
	{
	  fprintf (stderr, "Next token is %d (%s", YY_Parser_CHAR, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, YY_Parser_CHAR, YY_Parser_LVAL);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    YYGOTO(yydefault);

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrlab);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrlab);

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YY_Parser_DEBUG != 0
  if (YY_Parser_DEBUG_FLAG)
    fprintf(stderr, "Shifting token %d (%s), ", YY_Parser_CHAR, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (YY_Parser_CHAR != YYEOF)
    YY_Parser_CHAR = YYEMPTY;

  *++yyvsp = YY_Parser_LVAL;
#ifdef YY_Parser_LSP_NEEDED
  *++yylsp = YY_Parser_LLOC;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  YYGOTO(yynewstate);

/* Do the default action for the current state.  */
YYLABEL(yydefault)

  yyn = yydefact[yystate];
  if (yyn == 0)
    YYGOTO(yyerrlab);

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
YYLABEL(yyreduce)
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YY_Parser_DEBUG != 0
  if (YY_Parser_DEBUG_FLAG)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


/* #line 811 "D:\\interpreter\\bison++ flex++\\bison.cc" */
#line 1276 "parser.cpp"

  switch (yyn) {

case 1:
#line 112 "interpreter.y2"
{yyval._program= new Program( yyvsp[-1]._listaDeklaracji, yyvsp[0]._listaFunkcji);yyval._program->execute();;
    break;}
case 2:
#line 113 "interpreter.y2"
{yyval._program= new Program( yyvsp[0]._listaFunkcji);yyval._program->execute();;
    break;}
case 3:
#line 117 "interpreter.y2"
{ yyval._listaDeklaracji= new ListaDeklaracji( yyvsp[-1]._listaDeklaracji, yyvsp[0]._deklaracja);;
    break;}
case 4:
#line 118 "interpreter.y2"
{ yyval._listaDeklaracji= new ListaDeklaracji( yyvsp[0]._deklaracja);;
    break;}
case 5:
#line 122 "interpreter.y2"
{ yyval._deklaracja= new DeklaracjaDouble( *( yyvsp[-1]._napis), 0, sLocation.numerLinii);;
    break;}
case 6:
#line 123 "interpreter.y2"
{ yyval._deklaracja= new DeklaracjaDouble( *( yyvsp[-3]._napis), yyvsp[-1]._liczba, sLocation.numerLinii);;
    break;}
case 7:
#line 124 "interpreter.y2"
{ yyval._deklaracja= new DeklaracjaString( *( yyvsp[-1]._napis), "", sLocation.numerLinii);;
    break;}
case 8:
#line 125 "interpreter.y2"
{ yyval._deklaracja= new DeklaracjaString( *( yyvsp[-3]._napis), *( yyvsp[-1]._napis), sLocation.numerLinii);;
    break;}
case 9:
#line 129 "interpreter.y2"
{ yyval._listaFunkcji= new ListaFunkcji( yyvsp[-1]._listaFunkcji, yyvsp[0]._definicjaFunkcji);;
    break;}
case 10:
#line 130 "interpreter.y2"
{ yyval._listaFunkcji= new ListaFunkcji( yyvsp[0]._definicjaFunkcji);;
    break;}
case 11:
#line 135 "interpreter.y2"
{ yyval._definicjaFunkcji= new DefinicjaFunkcji( new WartoscDouble(), *( yyvsp[-4]._napis), yyvsp[-2]._listaParametrow, yyvsp[0]._instrukcja, sLocation.numerLinii);;
    break;}
case 12:
#line 137 "interpreter.y2"
{ yyval._definicjaFunkcji= new DefinicjaFunkcji( new WartoscString(), *( yyvsp[-4]._napis), yyvsp[-2]._listaParametrow, yyvsp[0]._instrukcja, sLocation.numerLinii);;
    break;}
case 13:
#line 141 "interpreter.y2"
{ yyval._listaParametrow= new ListaParametrow( yyvsp[-2]._listaParametrow, yyvsp[0]._parametr);;
    break;}
case 14:
#line 142 "interpreter.y2"
{ yyval._listaParametrow= new ListaParametrow( yyvsp[0]._parametr);;
    break;}
case 15:
#line 143 "interpreter.y2"
{ yyval._listaParametrow= new ListaParametrow( 0x00);;
    break;}
case 16:
#line 147 "interpreter.y2"
{ yyval._parametr= new ParametrDouble( *( yyvsp[0]._napis), 0, sLocation.numerLinii);;
    break;}
case 17:
#line 148 "interpreter.y2"
{ yyval._parametr= new ParametrString( *( yyvsp[0]._napis), "", sLocation.numerLinii);;
    break;}
case 18:
#line 152 "interpreter.y2"
{ yyval._instrukcja= yyvsp[0]._instrukcjaPrzypisania;;
    break;}
case 19:
#line 153 "interpreter.y2"
{ yyval._instrukcja= yyvsp[0]._instrukcjaZlozona;;
    break;}
case 20:
#line 154 "interpreter.y2"
{ yyval._instrukcja= yyvsp[0]._instrukcjaWarunkowaIf;;
    break;}
case 21:
#line 155 "interpreter.y2"
{ yyval._instrukcja= yyvsp[0]._instrukcjaIteracyjnaWhile;;
    break;}
case 22:
#line 156 "interpreter.y2"
{ yyval._instrukcja= yyvsp[0]._instrukcjaIteracyjnaFor;;
    break;}
case 23:
#line 157 "interpreter.y2"
{ yyval._instrukcja= yyvsp[0]._instrukcjaIteracyjnaDoWhile;;
    break;}
case 24:
#line 158 "interpreter.y2"
{ yyval._instrukcja= yyvsp[0]._instrukcjaSkokuReturn;;
    break;}
case 25:
#line 159 "interpreter.y2"
{ yyval._instrukcja= yyvsp[0]._instrukcjaDrukowania;;
    break;}
case 26:
#line 160 "interpreter.y2"
{ yyval._instrukcja= yyvsp[0]._instrukcjaWczytywania;;
    break;}
case 27:
#line 161 "interpreter.y2"
{ yyval._instrukcja= yyvsp[0]._deklaracja;;
    break;}
case 28:
#line 162 "interpreter.y2"
{ yyval._instrukcja= yyvsp[-1]._wywolanieFunkcji;;
    break;}
case 29:
#line 166 "interpreter.y2"
{ yyval._instrukcjaZlozona= new InstrukcjaZlozona( yyvsp[-1]._listaInstrukcji, sLocation.numerLinii);;
    break;}
case 30:
#line 170 "interpreter.y2"
{ yyval._listaInstrukcji= new ListaInstrukcji( yyvsp[-1]._listaInstrukcji, yyvsp[0]._instrukcja);;
    break;}
case 31:
#line 171 "interpreter.y2"
{ yyval._listaInstrukcji= new ListaInstrukcji( yyvsp[0]._instrukcja);;
    break;}
case 32:
#line 175 "interpreter.y2"
{ yyval._instrukcjaPrzypisania= new InstrukcjaPrzypisania( new ZmiennaLokalna( *( yyvsp[-3]._napis), sLocation.numerLinii), yyvsp[-1]._wyrazenie, sLocation.numerLinii);;
    break;}
case 33:
#line 177 "interpreter.y2"
{ yyval._instrukcjaPrzypisania= new InstrukcjaPrzypisania( new ZmiennaGlobalna( *( yyvsp[-3]._napis), sLocation.numerLinii), yyvsp[-1]._wyrazenie, sLocation.numerLinii);;
    break;}
case 34:
#line 182 "interpreter.y2"
{ yyval._instrukcjaWarunkowaIf= new InstrukcjaWarunkowaIf( yyvsp[-2]._wyrazenie, yyvsp[0]._instrukcja, sLocation.numerLinii);;
    break;}
case 35:
#line 184 "interpreter.y2"
{ yyval._instrukcjaWarunkowaIf= new InstrukcjaWarunkowaIf( yyvsp[-4]._wyrazenie, yyvsp[-2]._instrukcja, yyvsp[0]._instrukcja, sLocation.numerLinii);;
    break;}
case 36:
#line 188 "interpreter.y2"
{ yyval._instrukcjaIteracyjnaWhile= new InstrukcjaIteracyjnaWhile( yyvsp[-2]._wyrazenie, yyvsp[0]._instrukcja, sLocation.numerLinii);;
    break;}
case 37:
#line 193 "interpreter.y2"
{ yyval._instrukcjaIteracyjnaFor= new InstrukcjaIteracyjnaFor( yyvsp[-5]._deklaracja, yyvsp[-4]._wyrazenie, yyvsp[-2]._instrukcjaPrzypisania, yyvsp[0]._instrukcja, sLocation.numerLinii);;
    break;}
case 38:
#line 197 "interpreter.y2"
{ yyval._instrukcjaIteracyjnaDoWhile= new InstrukcjaIteracyjnaDoWhile( yyvsp[-6]._listaInstrukcji, yyvsp[-2]._wyrazenie, sLocation.numerLinii);;
    break;}
case 39:
#line 201 "interpreter.y2"
{ yyval._instrukcjaSkokuReturn= new InstrukcjaSkokuReturn( yyvsp[-1]._wyrazenie, sLocation.numerLinii);;
    break;}
case 40:
#line 205 "interpreter.y2"
{ yyval._instrukcjaDrukowania= new InstrukcjaDrukowania( yyvsp[-2]._wyrazenie, sLocation.numerLinii);;
    break;}
case 41:
#line 206 "interpreter.y2"
{ yyval._instrukcjaDrukowania= new InstrukcjaEndl(sLocation.numerLinii);;
    break;}
case 42:
#line 210 "interpreter.y2"
{ yyval._instrukcjaWczytywania= new InstrukcjaWczytywania( yyvsp[-2]._zmiennaLokalna, sLocation.numerLinii);;
    break;}
case 43:
#line 211 "interpreter.y2"
{ yyval._instrukcjaWczytywania= new InstrukcjaWczytywania( yyvsp[-2]._zmiennaGlobalna, sLocation.numerLinii);;
    break;}
case 44:
#line 215 "interpreter.y2"
{ yyval._wyrazenie= new Wyrazenie( yyvsp[-2]._wyrazenie, new OperatorMniejszosci(), yyvsp[0]._prosteWyrazenie, sLocation.numerLinii);;
    break;}
case 45:
#line 216 "interpreter.y2"
{ yyval._wyrazenie= new Wyrazenie( yyvsp[-2]._wyrazenie, new OperatorWiekszosci(), yyvsp[0]._prosteWyrazenie, sLocation.numerLinii);;
    break;}
case 46:
#line 217 "interpreter.y2"
{ yyval._wyrazenie= new Wyrazenie( yyvsp[-2]._wyrazenie, new OperatorRownosci(), yyvsp[0]._prosteWyrazenie, sLocation.numerLinii);;
    break;}
case 47:
#line 218 "interpreter.y2"
{ yyval._wyrazenie= new Wyrazenie( yyvsp[-2]._wyrazenie, new OperatorNierownosci(), yyvsp[0]._prosteWyrazenie, sLocation.numerLinii);;
    break;}
case 48:
#line 219 "interpreter.y2"
{ yyval._wyrazenie= new Wyrazenie( yyvsp[-2]._wyrazenie, new OperatorAlternatywy(), yyvsp[0]._prosteWyrazenie, sLocation.numerLinii);;
    break;}
case 49:
#line 220 "interpreter.y2"
{ yyval._wyrazenie= new Wyrazenie( yyvsp[-2]._wyrazenie, new OperatorKoniunkcji(), yyvsp[0]._prosteWyrazenie, sLocation.numerLinii);;
    break;}
case 50:
#line 221 "interpreter.y2"
{ yyval._wyrazenie= new Wyrazenie( yyvsp[0]._prosteWyrazenie, sLocation.numerLinii);;
    break;}
case 51:
#line 225 "interpreter.y2"
{ yyval._prosteWyrazenie= new ProsteWyrazenie( yyvsp[-2]._prosteWyrazenie, new OperatorDodawania(), yyvsp[0]._skladnik, sLocation.numerLinii);;
    break;}
case 52:
#line 226 "interpreter.y2"
{ yyval._prosteWyrazenie= new ProsteWyrazenie( yyvsp[-2]._prosteWyrazenie, new OperatorOdejmowania(), yyvsp[0]._skladnik, sLocation.numerLinii);;
    break;}
case 53:
#line 227 "interpreter.y2"
{ yyval._prosteWyrazenie= new ProsteWyrazenie( yyvsp[0]._skladnik, sLocation.numerLinii);;
    break;}
case 54:
#line 231 "interpreter.y2"
{ yyval._skladnik= new Skladnik( yyvsp[-2]._skladnik, new OperatorMnozenia(), yyvsp[0]._czynnikUnarny, sLocation.numerLinii);;
    break;}
case 55:
#line 232 "interpreter.y2"
{ yyval._skladnik= new Skladnik( yyvsp[-2]._skladnik, new OperatorDzielenia(), yyvsp[0]._czynnikUnarny, sLocation.numerLinii);;
    break;}
case 56:
#line 233 "interpreter.y2"
{ yyval._skladnik= new Skladnik( yyvsp[0]._czynnikUnarny, sLocation.numerLinii);;
    break;}
case 57:
#line 237 "interpreter.y2"
{ yyval._czynnikUnarny= new CzynnikUnarny( yyvsp[0]._czynnik, 0x00, sLocation.numerLinii);;
    break;}
case 58:
#line 238 "interpreter.y2"
{ yyval._czynnikUnarny= new CzynnikUnarny( yyvsp[0]._czynnik, new OperatorPlus(), sLocation.numerLinii);;
    break;}
case 59:
#line 239 "interpreter.y2"
{ yyval._czynnikUnarny= new CzynnikUnarny( yyvsp[0]._czynnik, new OperatorMinus(), sLocation.numerLinii);;
    break;}
case 60:
#line 243 "interpreter.y2"
{ yyval._czynnik= yyvsp[0]._zmiennaLokalna;;
    break;}
case 61:
#line 244 "interpreter.y2"
{ yyval._czynnik= yyvsp[0]._zmiennaGlobalna;;
    break;}
case 62:
#line 245 "interpreter.y2"
{ yyval._czynnik= yyvsp[0]._wywolanieFunkcji;;
    break;}
case 63:
#line 246 "interpreter.y2"
{ yyval._czynnik= new Liczba( yyvsp[0]._liczba, sLocation.numerLinii);;
    break;}
case 64:
#line 247 "interpreter.y2"
{ yyval._czynnik= new LiteralNapisowy( *( yyvsp[0]._napis), sLocation.numerLinii);;
    break;}
case 65:
#line 248 "interpreter.y2"
{ yyval._czynnik= yyvsp[0]._nawias;;
    break;}
case 66:
#line 252 "interpreter.y2"
{ yyval._zmiennaLokalna= new ZmiennaLokalna( *( yyvsp[0]._napis), sLocation.numerLinii);;
    break;}
case 67:
#line 256 "interpreter.y2"
{ yyval._zmiennaGlobalna= new ZmiennaGlobalna( *( yyvsp[0]._napis), sLocation.numerLinii);;
    break;}
case 68:
#line 260 "interpreter.y2"
{ yyval._wywolanieFunkcji= new WywolanieFunkcji( *( yyvsp[-3]._napis), yyvsp[-1]._listaWyrazen, sLocation.numerLinii);;
    break;}
case 69:
#line 264 "interpreter.y2"
{ yyval._listaWyrazen= new ListaWyrazen( yyvsp[-2]._listaWyrazen, yyvsp[0]._wyrazenie);;
    break;}
case 70:
#line 265 "interpreter.y2"
{ yyval._listaWyrazen= new ListaWyrazen( yyvsp[0]._wyrazenie);;
    break;}
case 71:
#line 266 "interpreter.y2"
{ yyval._listaWyrazen= new ListaWyrazen( 0x00);;
    break;}
case 72:
#line 270 "interpreter.y2"
{ yyval._nawias= new Nawias( yyvsp[-1]._wyrazenie, sLocation.numerLinii);;
//    '(' wyrazenie ')'    { $$= new Nawias( $2, sLocation.numerLinii);}
    break;}
}

#line 811 "D:\\interpreter\\bison++ flex++\\bison.cc"
   /* the action file gets copied in in place of this dollarsign  */
  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YY_Parser_LSP_NEEDED
  yylsp -= yylen;
#endif

#if YY_Parser_DEBUG != 0
  if (YY_Parser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YY_Parser_LSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = YY_Parser_LLOC.first_line;
      yylsp->first_column = YY_Parser_LLOC.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  YYGOTO(yynewstate);

YYLABEL(yyerrlab)   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++YY_Parser_NERRS;

#ifdef YY_Parser_ERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      YY_Parser_ERROR(msg);
	      free(msg);
	    }
	  else
	    YY_Parser_ERROR ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YY_Parser_ERROR_VERBOSE */
	YY_Parser_ERROR("parse error");
    }

  YYGOTO(yyerrlab1);
YYLABEL(yyerrlab1)   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (YY_Parser_CHAR == YYEOF)
	YYABORT;

#if YY_Parser_DEBUG != 0
      if (YY_Parser_DEBUG_FLAG)
	fprintf(stderr, "Discarding token %d (%s).\n", YY_Parser_CHAR, yytname[yychar1]);
#endif

      YY_Parser_CHAR = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;              /* Each real token shifted decrements this */

  YYGOTO(yyerrhandle);

YYLABEL(yyerrdefault)  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) YYGOTO(yydefault);
#endif

YYLABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YY_Parser_LSP_NEEDED
  yylsp--;
#endif

#if YY_Parser_DEBUG != 0
  if (YY_Parser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

YYLABEL(yyerrhandle)

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yyerrdefault);

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    YYGOTO(yyerrdefault);

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrpop);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrpop);

  if (yyn == YYFINAL)
    YYACCEPT;

#if YY_Parser_DEBUG != 0
  if (YY_Parser_DEBUG_FLAG)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = YY_Parser_LVAL;
#ifdef YY_Parser_LSP_NEEDED
  *++yylsp = YY_Parser_LLOC;
#endif

  yystate = yyn;
  YYGOTO(yynewstate);
/* end loop, in which YYGOTO may be used. */
  YYENDGOTO
}

/* END */

/* #line 1010 "D:\\interpreter\\bison++ flex++\\bison.cc" */
#line 1772 "parser.cpp"
#line 273 "interpreter.y2"

