// Version 1.0

#ifndef _MY_PARSER_H_
#define _MY_PARSER_H_

#include <iostream>

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

#include "lexer.h"
#include "parser.h"

// Parser
class MyParser : public Parser{
    public:
        // Przyjmuje wskaŸnik na strumieñ sk¹d bêdzie wczytywa³ dane
        // i gdzie je wypisywa³
        MyParser( std::istream*, std::ostream*);
};

#endif
