PROJECT= Interpreter
CXX=clang++
OBJS= functionDefinition.o \
	identifier.o \
	doWhileInstruction.o 	forInstruction.o whileInstruction.o \
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
CXXFLAGS= -g

all: $(PROJECT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PROJECT): $(OBJS)
	$(CXX) $(OBJS) -o $(PROJECT)

depend:
	$(CXX) -MM $(CXXFLAGS) *.cpp > depend.mk

clean:
	rm -rf $(PROJECT) $(OBJS)

