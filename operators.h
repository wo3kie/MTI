// Version 1.0

#ifndef _OPERATORY_H_
#define _OPERATORY_H_

#include "identifier.h"

// Klasa bazowa dla wszystkich operatorow
class Operator {
public:
    virtual ~Operator() {};
};

// Klasa bazowa dla wszystkich operatorow unarnych
class UnaryOperator : public Operator {
public:
    virtual const Value* operator()(const Value*) const = 0;
};

// Operator unarny minus
class OperatorMinus : public UnaryOperator {
public:
    virtual const Value* operator()(const Value* __w1) const
    {
        return __w1->operator-();
    }
};

// Operator unarny plus
class OperatorPlus : public UnaryOperator {
public:
    virtual const Value* operator()(const Value* __w1) const
    {
        return __w1->operator+();
    }
};

// Klasa bazowa dla wszystkich operator�w binarnych
class BinaryOperator : public Operator {
public:
    virtual const Value* operator()(const Value*, const Value*) const = 0;
};

// Klasa bazowa dla wszystkich operator�w logicznych
class BinaryLogicalOperator : public BinaryOperator {
public:
    virtual const Value* operator()(const Value*, const Value*) const = 0;
};

// Operator r�wno�ci
class EqualOperator : public BinaryLogicalOperator {
public:
    virtual const Value* operator()(const Value* __w1, const Value* __w2) const
    {
        return __w1->operator==(__w2);
    }
};

// Operator r�no�ci
class NotEqualOperator : public BinaryLogicalOperator {
public:
    virtual const Value* operator()(const Value* __w1, const Value* __w2) const
    {
        return __w1->operator!=(__w2);
    }
};

// Operator wi�kszo�ci
class GreaterOperator : public BinaryLogicalOperator {
public:
    virtual const Value* operator()(const Value* __w1, const Value* __w2) const
    {
        return __w1->operator>(__w2);
    }
};

// Operator mniejszo�ci
class LessOperator : public BinaryLogicalOperator {
public:
    virtual const Value* operator()(const Value* __w1, const Value* __w2) const
    {
        return __w1->operator<(__w2);
    }
};

// Operator alternatywy
class OrOperator : public BinaryLogicalOperator {
public:
    virtual const Value* operator()(const Value* __w1, const Value* __w2) const
    {
        return __w1->operator||(__w2);
    }
};

// Operator koniunkcji
class AndOperator : public BinaryLogicalOperator {
public:
    virtual const Value* operator()(const Value* __w1, const Value* __w2) const
    {
        return __w1->operator&&(__w2);
    }
};

// Klasa bazowa dla wszystkich operator�w addytywnych: +, -
class BiAdditiveOperator : public BinaryOperator {
public:
    virtual const Value* operator()(const Value*, const Value*) const = 0;
};

// Operator dodawania
class AddOperator : public BiAdditiveOperator {
public:
    virtual const Value* operator()(const Value* __w1, const Value* __w2) const
    {
        return __w1->operator+(__w2);
    }
};

// Operator odejmowania
class SubOperator : public BiAdditiveOperator {
public:
    virtual const Value* operator()(const Value* __w1, const Value* __w2) const
    {
        return __w1->operator-(__w2);
    }
};

// Klasa bazowa dla wszystkich operator�w multiplikatywnych: *, /
class BiMultiplicativeOperator : public BinaryOperator {
public:
    virtual const Value* operator()(const Value*, const Value*) const = 0;
};

// Operator dzielenia
class DivisionOperator : public BiMultiplicativeOperator {
public:
    virtual const Value* operator()(const Value* __w1, const Value* __w2) const
    {
        return __w1->operator/(__w2);
    }
};

// Operator mno�e�nia
class MultiplicationOperator : public BiMultiplicativeOperator {
public:
    virtual const Value* operator()(const Value* __w1, const Value* __w2) const
    {
        return __w1->operator*(__w2);
    }
};

// Operator przypisania. Nie dziedziczy po klasie 'BinaryOperator' ze wzgl�du na niezgodno�c
// interfejsu. Pierwszy argument kt�ry pobiera nie mo�e byc sta�y.
class AssignmentOperator : public Operator {
public:
    virtual const Value* operator()(Value* __w1, const Value* __w2) const
    {
        return __w1->operator=(__w2);
    }
};

namespace Operators {
extern AssignmentOperator copy;
};

#endif
