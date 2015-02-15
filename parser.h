#ifndef YY_Parser_h_included
#define YY_Parser_h_included
#define YY_USE_CLASS

#line 1 "/usr/share/bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "/usr/share/bison++/bison.h"

#line 30 "interpreter.y"
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
#define YY_Parser_CONSTRUCTOR_PARAM    std::istream* _in, std::ostream* _out
#define YY_Parser_CONSTRUCTOR_INIT     : m_lexer( _in, _out )
#define YY_Parser_CONSTRUCTOR_CODE     {}
#define YY_Parser_MEMBERS                      \
    public:                         \
        virtual ~Parser(){}         \
    public:                         \
        SymbolLocation sLocation;   \
    protected:                      \
        yyFlexLexer m_lexer;
#define YY_Parser_LEX_BODY  { return m_lexer.yylex(); }
#define YY_Parser_ERROR_BODY  { std::cerr << "Syntax error" << std::endl; }

#line 21 "/usr/share/bison++/bison.h"
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
/*#ifdef YYSTYPE*/
  #ifndef YY_Parser_STYPE
   #define YY_Parser_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_Parser_DEBUG
   #define  YY_Parser_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
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

 #line 65 "/usr/share/bison++/bison.h"

#line 65 "/usr/share/bison++/bison.h"
/* YY_Parser_PURE */
#endif


 #line 68 "/usr/share/bison++/bison.h"

#line 68 "/usr/share/bison++/bison.h"
/* prefix */

#ifndef YY_Parser_DEBUG

 #line 71 "/usr/share/bison++/bison.h"

#line 71 "/usr/share/bison++/bison.h"
/* YY_Parser_DEBUG */
#endif

#ifndef YY_Parser_LSP_NEEDED

 #line 75 "/usr/share/bison++/bison.h"

#line 75 "/usr/share/bison++/bison.h"
 /* YY_Parser_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_Parser_LSP_NEEDED
 #ifndef YY_Parser_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
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
  #endif

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
  #ifndef yylval
   extern YY_Parser_STYPE YY_Parser_LVAL;
  #else
   #if yylval != YY_Parser_LVAL
    extern YY_Parser_STYPE YY_Parser_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "/usr/share/bison++/bison.h"
#define	LICZBA	258
#define	IDENTYFIKATOR	259
#define	LNAPISOWY	260
#define	DOUBLE	261
#define	STRING	262
#define	WHILE	263
#define	IF	264
#define	RETURN	265
#define	MAIN	266
#define	PRINTF	267
#define	SCANF	268
#define	ENDL	269
#define	IFX	270
#define	ELSE	271
#define	EQ	272
#define	NEQ	273
#define	OR	274
#define	AND	275
#define	UMINUS	276
#define	OPERATOR_ZASIEGU	277


#line 169 "/usr/share/bison++/bison.h"
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
  
 #line 212 "/usr/share/bison++/bison.h"
static const int LICZBA;
static const int IDENTYFIKATOR;
static const int LNAPISOWY;
static const int DOUBLE;
static const int STRING;
static const int WHILE;
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


#line 212 "/usr/share/bison++/bison.h"
 /* decl const */
 #else
  enum YY_Parser_ENUM_TOKEN { YY_Parser_NULL_TOKEN=0
  
 #line 215 "/usr/share/bison++/bison.h"
	,LICZBA=258
	,IDENTYFIKATOR=259
	,LNAPISOWY=260
	,DOUBLE=261
	,STRING=262
	,WHILE=263
	,IF=264
	,RETURN=265
	,MAIN=266
	,PRINTF=267
	,SCANF=268
	,ENDL=269
	,IFX=270
	,ELSE=271
	,EQ=272
	,NEQ=273
	,OR=274
	,AND=275
	,UMINUS=276
	,OPERATOR_ZASIEGU=277


#line 215 "/usr/share/bison++/bison.h"
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
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_Parser_STYPE
 /#endif*/

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

 #line 267 "/usr/share/bison++/bison.h"
#endif
