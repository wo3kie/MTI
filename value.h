// Version 1.0

#ifndef _WARTOSC_H_
#define _WARTOSC_H_

#include "exceptions.h"

#include <iostream>

enum Type {
    Void,
    Double,
    String
};
enum Access {
    ReadOnly,
    ReadWrite
};

// Klasa interfejsu dla wartosci.
class Value {
public:
    // Konstruktor przyjmuje type warto�ci oraz specyfikacje dost�pu
    Value(Type __type, Access __access)
        : _type(__type)
        , _access(__access)
    {
    }

    virtual ~Value() {};

    // Metody te s� wywolywane przez odpowiednie klasy 'Operator...'
    virtual const Value* operator+(const Value*) const = 0;
    virtual const Value* operator+() const = 0;
    virtual const Value* operator-(const Value*) const = 0;
    virtual const Value* operator-() const = 0;
    virtual const Value* operator*(const Value*) const = 0;
    virtual const Value* operator/(const Value*) const = 0;

    virtual const Value* operator==(const Value*) const = 0;
    virtual const Value* operator!=(const Value*) const = 0;
    virtual const Value* operator<(const Value*) const = 0;
    virtual const Value* operator>(const Value*) const = 0;
    virtual const Value* operator||(const Value*) const = 0;
    virtual const Value* operator&&(const Value*) const = 0;

    virtual const Value* operator=(const Value*) = 0;

    // Metody drukuj�ce i wczytuj�ce warto�ci
    virtual const Value* printf() const = 0;
    virtual const Value* scanf() = 0;

    // Metoda okre�la, czy warto�c jest tylko do odczytu 'ReadOnly' czy
    // mo�na do niej zapisywac 'ReadWrite'
    Access access() const {
        return _access; }

    // Ustawia zmienn� tylko do odczytu
    void readOnly() {
        _access = ReadOnly; }

    // Zwraca type warto�ci: 'Double', 'String'
    Type type() const {
        return _type; }

    // Virtual constructor
    virtual Value* copy() const = 0;

protected:
    // Przechowuje type warto�ci
    Type _type;

    // Przechowuje type dostepu do warto�ci
    Access _access;
};

// Warto�c double reprezentuje liczby rzeczywiste w programie u�ytkownika.
class DoubleValue : public Value {
public:
    // Konstruktor przyjmuje warto�c oraz specyfikacj� dost�pu
    DoubleValue(double __value = 0, Access __access = ReadWrite)
        : Value(Double, __access)
        , _value(__value)
    {
    }

    // Dodaje dwie warto�ci
    virtual const Value* operator+(const Value* __value) const
    {
        const DoubleValue* doubleValue = dynamic_cast<const DoubleValue*>(__value);

        return new DoubleValue(_value + doubleValue->execute());
    }

    // Nie robi nic
    virtual const Value* operator+() const
    {
        return this;
    }

    // Odejmuje dwie warto�ci
    virtual const Value* operator-(const Value* __value) const
    {
        const DoubleValue* doubleValue = dynamic_cast<const DoubleValue*>(__value);

        return new DoubleValue(_value - doubleValue->execute());
    }

    // Zwraca warto�c o przeciwnym znaku
    virtual const Value* operator-() const
    {
        return new DoubleValue(-_value);
    }

    // Mno�y dwie warto�ci
    virtual const Value* operator*(const Value* __value) const
    {
        const DoubleValue* doubleValue = dynamic_cast<const DoubleValue*>(__value);

        return new DoubleValue(_value * doubleValue->execute());
    }

    // Dzieli dwie warto�ci
    virtual const Value* operator/(const Value* __value) const
    {
        const DoubleValue* doubleValue = dynamic_cast<const DoubleValue*>(__value);

        double divisor = doubleValue->execute();

        if (divisor) {
            return new DoubleValue(_value / divisor);
        } else {
            throw DividedByZero();
        }
    }

    // Okre�la, czy warto�ci s� r�wne
    virtual const Value* operator==(const Value* __value) const
    {
        const DoubleValue* doubleValue = dynamic_cast<const DoubleValue*>(__value);

        return new DoubleValue(_value == doubleValue->execute());
    }

    // Okre�la, czy warto�ci s� r�ne
    virtual const Value* operator!=(const Value* __value) const
    {
        const DoubleValue* doubleValue = dynamic_cast<const DoubleValue*>(__value);

        return new DoubleValue(_value != doubleValue->execute());
    }

    // Okre�la, czy warto�c jest wi�ksza
    virtual const Value* operator>(const Value* __value) const
    {
        const DoubleValue* doubleValue = dynamic_cast<const DoubleValue*>(__value);

        return new DoubleValue(_value > doubleValue->execute());
    }

    // Okre�la, czy warto�ci jest mniejsza
    virtual const Value* operator<(const Value* __value) const
    {
        const DoubleValue* doubleValue = dynamic_cast<const DoubleValue*>(__value);

        return new DoubleValue(_value < doubleValue->execute());
    }

    // Zwraca alternatywe dw�ch warto�ci
    virtual const Value* operator||(const Value* __value) const
    {
        const DoubleValue* doubleValue = dynamic_cast<const DoubleValue*>(__value);

        if (_value) {
            return new DoubleValue(true);
        }

        return new DoubleValue(doubleValue->execute());
    }

    // Zwraca koniunkcje dw�ch warto�ci
    virtual const Value* operator&&(const Value* __value) const
    {
        const DoubleValue* doubleValue = dynamic_cast<const DoubleValue*>(__value);

        if (!_value) {
            return new DoubleValue(false);
        }

        return new DoubleValue(doubleValue->execute());
    }

    // Por�wnuje dwie warto�ci
    virtual const Value* operator=(const Value* __value)
    {
        const DoubleValue* doubleValue = dynamic_cast<const DoubleValue*>(__value);

        _value = doubleValue->execute();

        return this;
    }

    // Drukuje warto�c na stdout
    virtual const Value* printf() const
    {
        std::cout << _value;
        std::cout.flush();
        return this;
    }

    // Wczytuje warto�c z stdin
    virtual const Value* scanf()
    {
        std::cin >> _value;
        return this;
    }

    // Zwraca warto�c
    double execute() const
    {
        return _value;
    }

    double& assign()
    {
        return _value;
    }

    // Virtual constructor
    virtual DoubleValue* copy() const
    {
        return new DoubleValue(*this);
    }

private:
    // Przechowuje warto�c rzeczywist�
    double _value;
};

// Value string reprezentuje napisy w programie u�ytkowanika
class StringValue : public Value {
public:
    // Konstruktor przyjmuje warto�c oraz specyfikacje dost�pu
    StringValue(std::string __value = "", Access __access = ReadWrite)
        : Value(String, __access)
        , _value(__value)
    {
    }

    // Operator nie jest zaimplementowany
    virtual const Value* operator+(const Value* __value) const
    {
        return 0x00;
    }

    // Operator nie jest zaimplementowany
    virtual const Value* operator+() const
    {
        return 0x00;
    }

    // Operator nie jest zaimplementowany
    virtual const Value* operator-(const Value* __value) const
    {
        return 0x00;
    }

    // Operator nie jest zaimplementowany
    virtual const Value* operator-() const
    {
        return 0x00;
    }

    // Operator nie jest zaimplementowany
    virtual const Value* operator*(const Value* __value) const
    {
        return 0x00;
    }

    // Operator nie jest zaimplementowany
    virtual const Value* operator/(const Value* __value) const
    {
        return 0x00;
    }

    // Operator nie jest zaimplementowany
    virtual const Value* operator==(const Value* __value) const
    {
        return 0x00;
    }

    // Operator nie jest zaimplementowany
    virtual const Value* operator!=(const Value* __value) const
    {
        return 0x00;
    }

    // Operator nie jest zaimplementowany
    virtual const Value* operator>(const Value* __value) const
    {
        return 0x00;
    }

    // Operator nie jest zaimplementowany
    virtual const Value* operator<(const Value* __value) const
    {
        return 0x00;
    }

    // Operator nie jest zaimplementowany
    virtual const Value* operator||(const Value* __value) const
    {
        return 0x00;
    }

    // Operator nie jest zaimplementowany
    virtual const Value* operator&&(const Value* __value) const
    {
        return 0x00;
    }

    // Por�wnuje dwie warto�ci
    virtual const Value* operator=(const Value* __value)
    {
        const StringValue* wartoscString = dynamic_cast<const StringValue*>(__value);

        if (_access == ReadOnly) {
            throw AssignToConstValue();
        } else {
            _value = wartoscString->execute();
        }

        return this;
    }

    // Drukuje warto�c na stdout
    virtual const Value* printf() const
    {
        std::cout << _value;
        std::cout.flush();
        return this;
    }

    // Wczytuje warto�c z stdin
    virtual const Value* scanf()
    {
        std::cin >> _value;
        return this;
    }

    // Zwraca warto�c
    std::string execute() const
    {
        return _value;
    }

    std::string& assign()
    {
        return _value;
    }

    // Virtual constructor
    virtual StringValue* copy() const
    {
        return new StringValue(*this);
    }

private:
    // Przechowuje warto�c
    std::string _value;
};

#endif
