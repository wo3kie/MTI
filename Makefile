# CXX
CXX= clang++

INC= -I.

LIBS=
LIBS_DIR=

CXXFLAG_DEBUG= -pg -g $(INC)
CXXFLAG_RELEASE= -O2 -DNDEBUG $(INC)
CXXFLAG = $(CXXFLAG_DEBUG)

# BISON
BISON = bison++
PARSER_DEFINITION_FILE = ./interpreter.y
PARSER_SOURCE_CODE_FILE = ./parser.cpp
PARSER_HEADER_FILE_NAME = ./parser.h
BISONFLAG = -v -d -h$(PARSER_HEADER_FILE_NAME) -o$(PARSER_SOURCE_CODE_FILE)

# FLEX
FLEX = flex++
LEXER_DEFINITION_FILE = ./interpreter.l
LEXER_SOURCE_CODE_FILE = ./lexer.cpp
FLEXFLAG = -I

OBJS= functionDefinition.o \
	identifier.o \
	doWhileInstruction.o \
	forInstruction.o \
	whileInstruction.o \
	assignmentInstruction.o \
	returnInstruction.o \
	ifStatement.o \
	lexer.o \
	main.o \
	myParser.o \
	operators.o \
	callParameter.o \
	parser.o \
	program.o \
	symbolLocation.o \
	functionCall.o

PROG= mti

DEP= makefile.dep

%.o: %.cpp
	$(CXX) $(CXXFLAG) -c $<

$(PROG):$(OBJS) 
	$(CXX) $(OBJS) $(LIBS) $(LIBS_DIR) -o $@

all: ccomp $(PROG)

ccomp: $(PARSER_DEFINITION_FILE) $(LEXER_DEFINITION_FILE)
	$(BISON) $(BISONFLAG) $(PARSER_DEFINITION_FILE)
	$(FLEX) $(FLEXFLAG) $(LEXER_DEFINITION_FILE)

depend: 
	$(CXX) -I. -MM $(OBJS:.o=.cpp) > $(DEP)

clean:
	rm -f $(OBJS) $(PROG)

clean_all:
	rm -f $(OBJS) $(PROG)
	rm -f $(PARSER_SOURCE_CODE_FILE) $(LEXER_SOURCE_CODE_FILE) $(PARSER_SOURCE_CODE_FILE:.cpp=.output)

run_tests:
	./mti example.mti

check_syntax_only: $(OBJS)
	$(CXX) $(CXXFLAG) -S $<

ifeq ($(wildcard $(DEP)), $(DEP))
include $(DEP)
endif

