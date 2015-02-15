PROJECT= Interpreter
CXX=clang++
OBJS= definicjaFunkcji.o \
	identyfikator.o \
	instrukcjaIteracyjnaDoWhile.o 	instrukcjaIteracyjnaFor.o instrukcjaIteracyjnaWhile.o \
	instrukcjaPrzypisania.o \
	instrukcjaSkokuReturn.o \
	instrukcjaWarunkowaIf.o \
	lekser.o \
	main.o \
	myParser.o \
	operatory.o \
	parametryWywolania.o \
	parser.o \
	program.o \
	symbolLocation.o \
	wywolanieFunkcji.o
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

