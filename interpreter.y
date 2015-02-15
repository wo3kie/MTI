/* * */

%{
#include <iostream>
#include <string>

#include "lekser.h"

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
%}

%name Parser

%union {
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
};

%type<_czynnik> czynnik
%type<_czynnikUnarny> czynnikUnarny
%type<_definicjaFunkcji> definicjaFunkcji
%type<_deklaracja> deklaracja
%type<_instrukcja> instrukcja
%type<_instrukcjaDrukowania> instrukcjaDrukowania
%type<_instrukcjaIteracyjnaWhile> instrukcjaIteracyjnaWhile
%type<_instrukcjaPrzypisania> instrukcjaPrzypisania
%type<_instrukcjaSkokuReturn> instrukcjaSkokuReturn
%type<_instrukcjaWarunkowaIf> instrukcjaWarunkowaIf
%type<_instrukcjaWczytywania> instrukcjaWczytywania
%type<_instrukcjaZlozona> instrukcjaZlozona
%type<_listaDeklaracji> listaDeklaracji
%type<_listaFunkcji> listaFunkcji
%type<_listaInstrukcji> listaInstrukcji
%type<_listaParametrow> listaParametrow
%type<_listaWyrazen> listaWyrazen
%type<_nawias> nawias
%type<_parametr> parametr
%type<_program> program;
%type<_prosteWyrazenie> prosteWyrazenie
%type<_skladnik> skladnik
%type<_wyrazenie> wyrazenie
%type<_wywolanieFunkcji> wywolanieFunkcji
%type<_zmiennaGlobalna> zmiennaGlobalna;
%type<_zmiennaLokalna> zmiennaLokalna;
%type<_napis> identyfikator;
%type<_napis> lnapisowy;
%type<_liczba> liczba;

%token <_liczba> LICZBA
%token <_napis>	IDENTYFIKATOR LNAPISOWY
%token DOUBLE STRING WHILE IF RETURN MAIN PRINTF SCANF ENDL
%nonassoc IFX
%nonassoc ELSE

%left '>' '<' EQ NEQ OR AND
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%left OPERATOR_ZASIEGU

%define CONSTRUCTOR_PARAM   std::istream* _in, std::ostream* _out
%define CONSTRUCTOR_INIT    : m_lexer( _in, _out )
%define CONSTRUCTOR_CODE    {}

%define MEMBERS                     \
    public:                         \
        virtual ~Parser(){}         \
    public:                         \
        SymbolLocation sLocation;   \
    protected:                      \
        yyFlexLexer m_lexer;

%define LEX_BODY { return m_lexer.yylex(); }
%define ERROR_BODY { std::cerr << "Syntax error" << std::endl; }

%%

program:
    listaDeklaracji listaFunkcji                    {$$= new Program( $1, $2);$$->execute();}
    | listaFunkcji                                  {$$= new Program( $1);$$->execute();}
    ;

listaDeklaracji:
    listaDeklaracji deklaracja                      { $$= new ListaDeklaracji( $1, $2);}
    | deklaracja                                    { $$= new ListaDeklaracji( $1);}
    ;

deklaracja:
    DOUBLE identyfikator ';'                        { $$= new DeklaracjaDouble( *( $2), 0, sLocation.numerLinii);}
    | DOUBLE identyfikator '=' liczba ';'           { $$= new DeklaracjaDouble( *( $2), $4, sLocation.numerLinii);}
    | STRING identyfikator ';'                      { $$= new DeklaracjaString( *( $2), "", sLocation.numerLinii);}
    | STRING identyfikator '=' lnapisowy ';'        { $$= new DeklaracjaString( *( $2), *( $4), sLocation.numerLinii);}
    ;

listaFunkcji:
    listaFunkcji definicjaFunkcji                   { $$= new ListaFunkcji( $1, $2);}
    | definicjaFunkcji                              { $$= new ListaFunkcji( $1);}
    ;

definicjaFunkcji:
    DOUBLE identyfikator '(' listaParametrow ')' instrukcja
                                { $$= new DefinicjaFunkcji( new WartoscDouble(), *( $2), $4, $6, sLocation.numerLinii);}
    | STRING identyfikator '(' listaParametrow ')' instrukcja
                                { $$= new DefinicjaFunkcji( new WartoscString(), *( $2), $4, $6, sLocation.numerLinii);}
    ;

listaParametrow:
    listaParametrow ',' parametr                    { $$= new ListaParametrow( $1, $3);}
    | parametr                                      { $$= new ListaParametrow( $1);}
    | /* NULL */                                    { $$= new ListaParametrow( 0x00);}
    ;

parametr:
    DOUBLE identyfikator                            { $$= new ParametrDouble( *( $2), 0, sLocation.numerLinii);}
    | STRING identyfikator                          { $$= new ParametrString( *( $2), "", sLocation.numerLinii);}
    ;

instrukcja:
    instrukcjaPrzypisania                           { $$= $1;}
    | instrukcjaZlozona                             { $$= $1;}
    | instrukcjaWarunkowaIf                         { $$= $1;}
    | instrukcjaIteracyjnaWhile                     { $$= $1;}
    | instrukcjaSkokuReturn                         { $$= $1;}
    | instrukcjaDrukowania                          { $$= $1;}
    | instrukcjaWczytywania                         { $$= $1;}
    | deklaracja                                    { $$= $1;}
    | wywolanieFunkcji ';'                          { $$= $1;}
    ;

instrukcjaZlozona:
    '{' listaInstrukcji '}'                         { $$= new InstrukcjaZlozona( $2, sLocation.numerLinii);}
    ;

listaInstrukcji:
    listaInstrukcji instrukcja                      { $$= new ListaInstrukcji( $1, $2);}
    | instrukcja                                    { $$= new ListaInstrukcji( $1);}
    ;

instrukcjaPrzypisania:
    identyfikator '=' wyrazenie ';'                 { $$= new InstrukcjaPrzypisania( new ZmiennaLokalna( *( $1), sLocation.numerLinii), $3, sLocation.numerLinii);}
    | OPERATOR_ZASIEGU identyfikator '=' wyrazenie ';'
                                                    { $$= new InstrukcjaPrzypisania( new ZmiennaGlobalna( *( $2), sLocation.numerLinii), $4, sLocation.numerLinii);}
    ;

instrukcjaWarunkowaIf:
    IF '(' wyrazenie ')' instrukcja %prec IFX
                                                    { $$= new InstrukcjaWarunkowaIf( $3, $5, sLocation.numerLinii);}
    | IF '(' wyrazenie ')' instrukcja ELSE instrukcja
                                                    { $$= new InstrukcjaWarunkowaIf( $3, $5, $7, sLocation.numerLinii);}
    ;

instrukcjaIteracyjnaWhile:
    WHILE '(' wyrazenie ')' instrukcja       { $$= new InstrukcjaIteracyjnaWhile( $3, $5, sLocation.numerLinii);}
    ;

instrukcjaSkokuReturn:
    RETURN wyrazenie ';'                            { $$= new InstrukcjaSkokuReturn( $2, sLocation.numerLinii);}
    ;

instrukcjaDrukowania:
    PRINTF '(' wyrazenie ')' ';'                    { $$= new InstrukcjaDrukowania( $3, sLocation.numerLinii);}
    | PRINTF '(' ENDL ')' ';'                       { $$= new InstrukcjaEndl(sLocation.numerLinii);}
    ;

instrukcjaWczytywania:
    SCANF '(' zmiennaLokalna ')' ';'                { $$= new InstrukcjaWczytywania( $3, sLocation.numerLinii);}
    | SCANF '(' zmiennaGlobalna ')' ';'             { $$= new InstrukcjaWczytywania( $3, sLocation.numerLinii);}
    ;

wyrazenie:
    wyrazenie '<' prosteWyrazenie                   { $$= new Wyrazenie( $1, new OperatorMniejszosci(), $3, sLocation.numerLinii);}
    | wyrazenie '>' prosteWyrazenie                 { $$= new Wyrazenie( $1, new OperatorWiekszosci(), $3, sLocation.numerLinii);}
    | wyrazenie EQ prosteWyrazenie                  { $$= new Wyrazenie( $1, new OperatorRownosci(), $3, sLocation.numerLinii);}
    | wyrazenie NEQ prosteWyrazenie                 { $$= new Wyrazenie( $1, new OperatorNierownosci(), $3, sLocation.numerLinii);}
    | wyrazenie OR prosteWyrazenie                  { $$= new Wyrazenie( $1, new OperatorAlternatywy(), $3, sLocation.numerLinii);}
    | wyrazenie AND prosteWyrazenie                 { $$= new Wyrazenie( $1, new OperatorKoniunkcji(), $3, sLocation.numerLinii);}
    | prosteWyrazenie                               { $$= new Wyrazenie( $1, sLocation.numerLinii);}
    ;

prosteWyrazenie:
    prosteWyrazenie '+' skladnik                    { $$= new ProsteWyrazenie( $1, new OperatorDodawania(), $3, sLocation.numerLinii);}
    | prosteWyrazenie '-' skladnik                  { $$= new ProsteWyrazenie( $1, new OperatorOdejmowania(), $3, sLocation.numerLinii);}
    | skladnik                                      { $$= new ProsteWyrazenie( $1, sLocation.numerLinii);}
    ;

skladnik:
    skladnik '*' czynnikUnarny                      { $$= new Skladnik( $1, new OperatorMnozenia(), $3, sLocation.numerLinii);}
    | skladnik '/' czynnikUnarny                    { $$= new Skladnik( $1, new OperatorDzielenia(), $3, sLocation.numerLinii);}
    | czynnikUnarny                                 { $$= new Skladnik( $1, sLocation.numerLinii);}
    ;

czynnikUnarny:
    czynnik                                         { $$= new CzynnikUnarny( $1, 0x00, sLocation.numerLinii);}
    | '+' czynnik                                   { $$= new CzynnikUnarny( $2, new OperatorPlus(), sLocation.numerLinii);}
    | '-' czynnik                                   { $$= new CzynnikUnarny( $2, new OperatorMinus(), sLocation.numerLinii);}
    ;

czynnik:
    zmiennaLokalna                                  { $$= $1;}
    | zmiennaGlobalna                               { $$= $1;}
    | wywolanieFunkcji                              { $$= $1;}
    | liczba                                        { $$= new Liczba( $1, sLocation.numerLinii);}
    | lnapisowy                                     { $$= new LiteralNapisowy( *( $1), sLocation.numerLinii);}
    | nawias                                        { $$= $1;}
    ;

zmiennaLokalna:
    identyfikator                                   { $$= new ZmiennaLokalna( *( $1), sLocation.numerLinii);}
    ;

zmiennaGlobalna:
    OPERATOR_ZASIEGU identyfikator                  { $$= new ZmiennaGlobalna( *( $2), sLocation.numerLinii);}
    ;

wywolanieFunkcji:
    identyfikator '(' listaWyrazen ')'              { $$= new WywolanieFunkcji( *( $1), $3, sLocation.numerLinii);}
    ;

listaWyrazen:
    listaWyrazen ',' wyrazenie                      { $$= new ListaWyrazen( $1, $3);}
    | wyrazenie                                     { $$= new ListaWyrazen( $1);}
    | /* NULL */                                    { $$= new ListaWyrazen( 0x00);}
    ;

nawias:
    '(' wyrazenie ')'                               { $$= new Nawias( $2, sLocation.numerLinii);}
    ;

lnapisowy:
    LNAPISOWY                                       { $$= new std::string( m_lexer.YYText() ); }

liczba:
    LICZBA                                          { $$= atoi( m_lexer.YYText() ); }

identyfikator:
    IDENTYFIKATOR                                   { $$= new std::string( m_lexer.YYText() ); }

%%

