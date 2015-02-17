// Version 1.0

#ifndef _WYJATKI_H_
#define _WYJATKI_H_

#include <exception>
#include <stdexcept>
#include <string>

// InterpreterException, wyjatki zglaszane przez aplikacje
class IException : public std::exception {
public:
    IException(const std::string& __message = "")
        : _message(__message)
    {
    }

    virtual ~IException() throw() {}
    virtual const char* what() const throw() {
        return _message.c_str(); }

protected:
    std::string _message;
};

// Wyjatek zglaszamy gdy nie mozna wywolac funkcji
class CannotCallFunction : public IException {
public:
    CannotCallFunction(const std::string& __function)
        : IException(std::string("Cannot call function: '") + __function + std::string("'"))
    {
    }

    virtual ~CannotCallFunction() throw() {}
};

// Wyjatek zglaszany je¿eli probujemy dzielic przez zero
class DividedByZero : public IException {
public:
    DividedByZero(const std::string& __message = "Divided by zero")
        : IException(__message)
    {
    }

    virtual ~DividedByZero() throw() {}
};

// Wyjatek zglaszany je¿eli nie mo¿na otworzyc pliku podanego w wierszu polecen
class UnableToOpenFile : public IException {
public:
    UnableToOpenFile(const std::string& __plik)
        : IException(std::string("Unable to open file: ") + __plik)
    {
    }

    virtual ~UnableToOpenFile() throw() {}

    virtual const char* what() const throw() {
        return _message.c_str(); }
};

// Wyjatek zglaszany jezeli podano zla liczbe parametrow wywolania programu
class NoInputFile : public IException {
public:
    virtual ~NoInputFile() throw() {}

    virtual const char* what() const throw() {
        return "No input file"; }
};

// Wyjatek zglaszany przez tablice symboli gdy odwolujemy sie do nazwy zmiennej
// ktorej nie ma w tablicy
class UndefinedSymbol : public IException {
public:
    UndefinedSymbol(const std::string& __symbol)
        : IException("Undefined symbol: ")
    {
        _message += __symbol;
    }

    virtual ~UndefinedSymbol() throw() {}

    virtual const char* what() const throw() {
        return _message.c_str(); }
};

// Wyjatek zglaszany przez tablice symboli, je¿eli probujemy do niej dodac
// identifier.o nazwie ktora jest ju¿ w tablicy
class MultipleDeclaration : public IException {
public:
    MultipleDeclaration(const std::string& __symbol)
        : IException(std::string("Multiple declaration: ") + __symbol)
    {
    }

    virtual ~MultipleDeclaration() throw() {}

    virtual const char* what() const throw() {
        return _message.c_str(); }
};

// Wyjatek zglaszany je¿eli sa niezgodne typy
class IncorectTypes : public IException {
public:
    IncorectTypes(const std::string& __message = "IncorectTypes")
        : IException(__message)
    {
    }

    virtual ~IncorectTypes() throw() {}
};

// Wyjatek zglaszany przy probie przypisania do stalej
class AssignToConstValue : public IException {
public:
    AssignToConstValue()
        : IException()
    {
    }

    virtual ~AssignToConstValue() throw() {}
};

#endif
