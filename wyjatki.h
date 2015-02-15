// Version 1.0

#ifndef _WYJATKI_H_
#define _WYJATKI_H_

#include <exception>
#include <stdexcept>
#include <string>

// InterpreterException, wyj¹tki zg³aszane przez aplikacje
class IException:public std::exception{
    public:
        IException( const std::string& __komunikat= ""):_komunikat( __komunikat){}

        virtual ~IException()throw(){}
        virtual const char* what()const throw(){ return _komunikat.c_str();}

    protected:
        std::string _komunikat;
};

// Wyjatek zglaszamy gdy nie mozna wywolac funkcji
class CannotCallFunction:public IException{
    public:
        CannotCallFunction( const std::string& __funkcja)
        :IException( std::string("Cannot call function: '")+ __funkcja+ std::string("'")){}

        virtual ~CannotCallFunction() throw() {}
};

// Wyj¹tek zg³aszany je¿eli próbujemy dzielic przez zero
class DividedByZero:public IException{
    public:
        DividedByZero( const std::string& __komunikat= "Divided by zero"): IException( __komunikat){}

        virtual ~DividedByZero() throw() { }
};

// Wyj¹tek zg³aszany je¿eli nie mo¿na otworzyc pliku podanego w wierszu poleceñ
class UnableToOpenFile:public IException{
    public:
        UnableToOpenFile( const std::string& __plik)
        :IException( std::string( "Unable to open file: ")+ __plik){
        }

        virtual ~UnableToOpenFile()throw(){}

        virtual const char* what()const throw(){ return _komunikat.c_str();}
};

// Wyj¹tek zg³aszany jeŸeli podano zl¹ liczbê parametrów wywo³ania programu
class NoInputFile:public IException{
    public:
        virtual ~NoInputFile()throw(){}

        virtual const char* what()const throw() { return "No input file";}
};

// Wyj¹tek zg³aszany przez tablicê symboli gdy odwolujemy sie do nazwy zmiennej
// której nie ma w tablicy
class UndefinedSymbol:public IException{
    public:
        UndefinedSymbol( const std::string& __symbol)
        :IException( "Undefined symbol: "){
            _komunikat+= __symbol;
        }

        virtual ~UndefinedSymbol()throw(){}

        virtual const char* what()const throw(){ return _komunikat.c_str();}

};

// Wyj¹tek zg³aszany przez tablicê symboli, je¿eli probujemy do niej dodac
// identyfikator o nazwie która jest ju¿ w tablicy
class MultipleDeclaration:public IException{
    public:
        MultipleDeclaration( const std::string& __symbol)
        :IException( std::string( "Multiple declaration: ")+ __symbol){}

        virtual ~MultipleDeclaration()throw(){}

        virtual const char* what()const throw(){ return _komunikat.c_str();}
};

// Wyj¹tek zg³aszany je¿eli s¹ niezgodne typy
class IncorectTypes:public IException{
    public:
        IncorectTypes( const std::string& __message= "IncorectTypes"):IException( __message){}

        virtual ~IncorectTypes()throw(){}
};


// Wyj¹tek zg³aszany przy próbie przypisania do sta³ej
class AssignToConstValue:public IException{
    public:
        AssignToConstValue():IException(){}

        virtual ~AssignToConstValue()throw(){}
};

#endif
