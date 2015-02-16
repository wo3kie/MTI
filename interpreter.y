/* * */

%{
#include <iostream>
#include <string>

#include "lexer.h"

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
%}

%name Parser

%union {
    double _number;
    std::string* _text;

    Factor* _factor;
    UnaryFactor* _unaryFactor;
    FunctionDefinition* _functionDefinition;
    Declaration* _declaration;
    Instruction* _instruction;
    PrintInstruction* _printInstruction;
    WhileInstruction* _whileInstruction;
    AssignmentInstruction* _assignmentInstruction;
    ReturnInstruction* _returnInstruction;
    IfStatement* _ifStatement;
    ScanInstruction* _scanInstruction;
    ComplexInstrukction* _complexInstruction;
    DeclarationList* _declarationList;
    FunctionList* _functionList;
    InstructionList* _instructionList;
    ParameterList* _parameterList;
    ExpressionList* _expressionList;
    TextLiteral* _textLiteral;
    Bracket* _bracket;
    Parameter* _parameter;
    Program* _program;
    SimpleExpression* _simpleExpression;
    Unit* _unit;
    Expression* _expression;
    FunctionCall* _functionCall;
    GlobalVariable* _globalVariable;
    LocalVariable* _localVariable;
};

%type<_factor> factor
%type<_unaryFactor> unaryFactor
%type<_functionDefinition> functionDefinition
%type<_declaration> declaration
%type<_instruction> instruction
%type<_printInstruction> printInstruction
%type<_whileInstruction> whileInstruction
%type<_assignmentInstruction> assignmentInstruction
%type<_returnInstruction> returnInstruction
%type<_ifStatement> ifStatement
%type<_scanInstruction> scanInstruction
%type<_complexInstruction> complexInstruction
%type<_declarationList> declarationList
%type<_functionList> functionList
%type<_instructionList> instructionList
%type<_parameterList> parameterList
%type<_expressionList> expressionList
%type<_bracket> bracket
%type<_parameter> parameter
%type<_program> program;
%type<_simpleExpression> simpleExpression
%type<_unit> unit
%type<_expression> expression
%type<_functionCall> functionCall
%type<_globalVariable> globalVariable;
%type<_localVariable> localVariable;
%type<_text> identifier;
%type<_text> textLiteral;
%type<_number> number;

%token <_number> NUMBER
%token <_text>	IDENTIFIER TEXTLITERAL
%token DOUBLE STRING WHILE IF RETURN MAIN PRINTF SCANF ENDL
%nonassoc IFX
%nonassoc ELSE

%left '>' '<' EQ NEQ OR AND
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%left SCOPE_OPERATOR

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
    declarationList functionList                        {$$= new Program( $1, $2);$$->execute();}
    | functionList                                      {$$= new Program( $1);$$->execute();}
    ;

declarationList:
    declarationList declaration                         { $$= new DeclarationList( $1, $2);}
    | declaration                                       { $$= new DeclarationList( $1);}
    ;

declaration:
    DOUBLE identifier ';'                               { $$= new DoubleDeclaration( *( $2), 0, sLocation.lineNumber);}
    | DOUBLE identifier '=' number ';'                  { $$= new DoubleDeclaration( *( $2), $4, sLocation.lineNumber);}
    | STRING identifier ';'                             { $$= new StringDeclaration( *( $2), "", sLocation.lineNumber);}
    | STRING identifier '=' textLiteral ';'             { $$= new StringDeclaration( *( $2), *( $4), sLocation.lineNumber);}
    ;

functionList:
    functionList functionDefinition                     { $$= new FunctionList( $1, $2);}
    | functionDefinition                                { $$= new FunctionList( $1);}
    ;

functionDefinition:
    DOUBLE identifier '(' parameterList ')' instruction
                                { $$= new FunctionDefinition( new DoubleValue(), *( $2), $4, $6, sLocation.lineNumber);}
    | STRING identifier '(' parameterList ')' instruction
                                { $$= new FunctionDefinition( new StringValue(), *( $2), $4, $6, sLocation.lineNumber);}
    ;

parameterList:
    parameterList ',' parameter                         { $$= new ParameterList( $1, $3);}
    | parameter                                         { $$= new ParameterList( $1);}
    | /* NULL */                                        { $$= new ParameterList( 0x00);}
    ;

parameter:
    DOUBLE identifier                                   { $$= new ParametrDouble( *( $2), 0, sLocation.lineNumber);}
    | STRING identifier                                 { $$= new ParametrString( *( $2), "", sLocation.lineNumber);}
    ;

instruction:
    assignmentInstruction                               { $$= $1;}
    | complexInstruction                                { $$= $1;}
    | ifStatement                                       { $$= $1;}
    | whileInstruction                                  { $$= $1;}
    | returnInstruction                                 { $$= $1;}
    | printInstruction                                  { $$= $1;}
    | scanInstruction                                   { $$= $1;}
    | declaration                                       { $$= $1;}
    | functionCall ';'                                  { $$= $1;}
    ;

complexInstruction:
    '{' instructionList '}'                             { $$= new ComplexInstrukction( $2, sLocation.lineNumber);}
    ;

instructionList:
    instructionList instruction                         { $$= new InstructionList( $1, $2);}
    | instruction                                       { $$= new InstructionList( $1);}
    ;

assignmentInstruction:
    identifier '=' expression ';'                       { $$= new AssignmentInstruction( new LocalVariable( *( $1), sLocation.lineNumber), $3, sLocation.lineNumber);}
    | SCOPE_OPERATOR identifier '=' expression ';'
                                                        { $$= new AssignmentInstruction( new GlobalVariable( *( $2), sLocation.lineNumber), $4, sLocation.lineNumber);}
    ;

ifStatement:
    IF '(' expression ')' instruction %prec IFX
                                                        { $$= new IfStatement( $3, $5, sLocation.lineNumber);}
    | IF '(' expression ')' instruction ELSE instruction
                                                        { $$= new IfStatement( $3, $5, $7, sLocation.lineNumber);}
    ;

whileInstruction:
    WHILE '(' expression ')' instruction                { $$= new WhileInstruction( $3, $5, sLocation.lineNumber);}
    ;

returnInstruction:
    RETURN expression ';'                               { $$= new ReturnInstruction( $2, sLocation.lineNumber);}
    ;

printInstruction:
    PRINTF '(' expression ')' ';'                       { $$= new PrintInstruction( $3, sLocation.lineNumber);}
    | PRINTF '(' ENDL ')' ';'                           { $$= new EndlInstruction(sLocation.lineNumber);}
    ;

scanInstruction:
    SCANF '(' localVariable ')' ';'                     { $$= new ScanInstruction( $3, sLocation.lineNumber);}
    | SCANF '(' globalVariable ')' ';'                  { $$= new ScanInstruction( $3, sLocation.lineNumber);}
    ;

expression:
    expression '<' simpleExpression                     { $$= new Expression( $1, new LessOperator(), $3, sLocation.lineNumber);}
    | expression '>' simpleExpression                   { $$= new Expression( $1, new GreaterOperator(), $3, sLocation.lineNumber);}
    | expression EQ simpleExpression                    { $$= new Expression( $1, new EqualOperator(), $3, sLocation.lineNumber);}
    | expression NEQ simpleExpression                   { $$= new Expression( $1, new NotEqualOperator(), $3, sLocation.lineNumber);}
    | expression OR simpleExpression                    { $$= new Expression( $1, new OrOperator(), $3, sLocation.lineNumber);}
    | expression AND simpleExpression                   { $$= new Expression( $1, new AndOperator(), $3, sLocation.lineNumber);}
    | simpleExpression                                  { $$= new Expression( $1, sLocation.lineNumber);}
    ;

simpleExpression:
    simpleExpression '+' unit                           { $$= new SimpleExpression( $1, new AddOperator(), $3, sLocation.lineNumber);}
    | simpleExpression '-' unit                         { $$= new SimpleExpression( $1, new SubOperator(), $3, sLocation.lineNumber);}
    | unit                                              { $$= new SimpleExpression( $1, sLocation.lineNumber);}
    ;

unit:
    unit '*' unaryFactor                                { $$= new Unit( $1, new MultiplicationOperator(), $3, sLocation.lineNumber);}
    | unit '/' unaryFactor                              { $$= new Unit( $1, new DivisionOperator(), $3, sLocation.lineNumber);}
    | unaryFactor                                       { $$= new Unit( $1, sLocation.lineNumber);}
    ;

unaryFactor:
    factor                                              { $$= new UnaryFactor( $1, 0x00, sLocation.lineNumber);}
    | '+' factor                                        { $$= new UnaryFactor( $2, new OperatorPlus(), sLocation.lineNumber);}
    | '-' factor                                        { $$= new UnaryFactor( $2, new OperatorMinus(), sLocation.lineNumber);}
    ;

factor:
    localVariable                                       { $$= $1;}
    | globalVariable                                    { $$= $1;}
    | functionCall                                      { $$= $1;}
    | number                                            { $$= new Number( $1, sLocation.lineNumber);}
    | textLiteral                                       { $$= new TextLiteral( *( $1), sLocation.lineNumber);}
    | bracket                                           { $$= $1;}
    ;

localVariable:
    identifier                                          { $$= new LocalVariable( *( $1), sLocation.lineNumber);}
    ;

globalVariable:
    SCOPE_OPERATOR identifier                           { $$= new GlobalVariable( *( $2), sLocation.lineNumber);}
    ;

functionCall:
    identifier '(' expressionList ')'                   { $$= new FunctionCall( *( $1), $3, sLocation.lineNumber);}
    ;

expressionList:
    expressionList ',' expression                       { $$= new ExpressionList( $1, $3);}
    | expression                                        { $$= new ExpressionList( $1);}
    | /* NULL */                                        { $$= new ExpressionList( 0x00);}
    ;

bracket:
    '(' expression ')'                                  { $$= new Bracket( $2, sLocation.lineNumber);}
    ;

textLiteral:
    TEXTLITERAL                                         { $$= new std::string( m_lexer.YYText() ); }

number:
    NUMBER                                              { $$= atoi( m_lexer.YYText() ); }

identifier:
    IDENTIFIER                                          { $$= new std::string( m_lexer.YYText() ); }

%%

