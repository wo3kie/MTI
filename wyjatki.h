// Version 1.0

#ifndef _WYJATKI_H_
#define _WYJATKI_H_

#include <exception>
#include <stdexcept>
#include <string>

// InterpreterException, wyj�tki zg�aszane przez aplikacje
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

// Wyj�tek zg�aszany je�eli pr�bujemy dzielic przez zero
class DividedByZero:public IException{
    public:
        DividedByZero( const std::string& __komunikat= "Divided by zero"): IException( __komunikat){}

        virtual ~DividedByZero() throw() { }
};

// Wyj�tek zg�aszany je�eli nie mo�na otworzyc pliku podanego w wierszu polece�
class UnableToOpenFile:public IException{
    public:
        UnableToOpenFile( const std::string& __plik)
        :IException( std::string( "Unable to open file: ")+ __plik){
        }

        virtual ~UnableToOpenFile()throw(){}

        virtual const char* what()const throw(){ return _komunikat.c_str();}
};

// Wyj�tek zg�aszany je�eli podano zl� liczb� parametr�w wywo�ania programu
class NoInputFile:public IException{
    public:
        virtual ~NoInputFile()throw(){}

        virtual const char* what()const throw() { return "No input file";}
};

// Wyj�tek zg�aszany przez tablic� symboli gdy odwolujemy sie do nazwy zmiennej
// kt�rej nie ma w tablicy
class UndefinedSymbol:public IException{
    public:
        UndefinedSymbol( const std::string& __symbol)
        :IException( "Undefined symbol: "){
            _komunikat+= __symbol;
        }

        virtual ~UndefinedSymbol()throw(){}

        virtual const char* what()const throw(){ return _komunikat.c_str();}

};

// Wyj�tek zg�aszany przez tablic� symboli, je�eli probujemy do niej dodac
// identyfikator o nazwie kt�ra jest ju� w tablicy
class MultipleDeclaration:public IException{
    public:
        MultipleDeclaration( const std::string& __symbol)
        :IException( std::string( "Multiple declaration: ")+ __symbol){}

        virtual ~MultipleDeclaration()throw(){}

        virtual const char* what()const throw(){ return _komunikat.c_str();}
};

// Wyj�tek zg�aszany je�eli s� niezgodne typy
class IncorectTypes:public IException{
    public:
        IncorectTypes( const std::string& __message= "IncorectTypes"):IException( __message){}

        virtual ~IncorectTypes()throw(){}
};


// Wyj�tek zg�aszany przy pr�bie przypisania do sta�ej
class AssignToConstValue:public IException{
    public:
        AssignToConstValue():IException(){}

        virtual ~AssignToConstValue()throw(){}
};

#endif
