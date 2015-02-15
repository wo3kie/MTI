// Version 1.0

#include "myParser.h"

MyParser::MyParser(istream* __in,ostream* __out)
:_in(__in),
_out(__out)
{
    _lekser.yyin= _in;
    _lekser.yyout= _out;
}

void MyParser::yyerror(char* __msg){
    std::cerr<< _lekser.sLocation.numerLinii<< ": "<< "Parse error: Bad symbol: "<<
        _lekser.sLocation.leksem<< std::endl;
    exit( 0);
}

int MyParser::yylex(){
    int token= _lekser.yylex( &yylval);

    //std::cout<< token<< std::endl;

    return token;
}

void Parser::yyerror(char*__msg){
    std::cerr<< __msg<< std::endl;
}

int Parser::yylex(){
    return 0;
}
