// libraryFunctions.h v 1.0

#ifndef _FUNKCJE_BIBLIOTECZNE_H_
#define _FUNKCJE_BIBLIOTECZNE_H_

#include "functionDefinition.h"

#include <functional>
#include <math.h>
#include <sstream>

const double M_PI_180 = 0.017453292;

// double sin( double )
// double cos( double )
// double sqrt( double )
// double rad( double )
// double pi()

class _Pow : public FunctionDefinition {
public:
    _Pow()
        : FunctionDefinition(new DoubleValue(), "pow", new List<Parameter>(new List<Parameter>(new DoubleDeclaration("number", 0, 0)), new DoubleDeclaration("number", 0, 0)), 0x00, 0)
    {
        // tworzy rekord aktywacji
        for (int parameter = 0; parameter < _parameterList->size(); ++parameter) {
            _activationRecord.valueList.push_back((*_parameterList)[parameter]->execute()->copy());
        }
    }

    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        const DoubleValue* w1 = dynamic_cast<const DoubleValue*>(_activationRecord.valueList[0]);
        const DoubleValue* w2 = dynamic_cast<const DoubleValue*>(_activationRecord.valueList[1]);

        Operators::copy(_activationRecord.returnValue, new DoubleValue(::pow(w1->execute(), w2->execute())));

        return 0x00;
    }
};

class _Printf : public FunctionDefinition {
public:
    _Printf()
        : FunctionDefinition(new DoubleValue(), "_printf", new List<Parameter>(new DoubleDeclaration("number", 0, 0)), 0x00, 0)
    {
        // tworzy rekord aktywacji
        for (int parameter = 0; parameter < (int)_parameterList->size(); ++parameter) {
            _activationRecord.valueList.push_back((*_parameterList)[parameter]->execute()->copy());
        }
    }

    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        _activationRecord.valueList[0]->printf();

        Operators::copy(_activationRecord.returnValue, new DoubleValue(1));

        return 0x00;
    }
};

class _Scanf : public FunctionDefinition {
public:
    _Scanf()
        : FunctionDefinition(new DoubleValue(), "_scanf", new List<Parameter>(new DoubleDeclaration("number", 0, 0)), 0x00, 0)
    {
        // tworzy rekord aktywacji
        for (int parameter = 0; parameter < (int)_parameterList->size(); ++parameter) {
            _activationRecord.valueList.push_back((*_parameterList)[parameter]->execute()->copy());
        }
    }

    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        _activationRecord.valueList[0]->scanf();

        Operators::copy(_activationRecord.returnValue, new DoubleValue(1));

        return 0x00;
    }
};

class _Cos : public FunctionDefinition {
public:
    _Cos()
        : FunctionDefinition(new DoubleValue(), "cos", new List<Parameter>(new DoubleDeclaration("number", 0, 0)), 0x00, 0)
    {
        // tworzy rekord aktywacji
        for (int parameter = 0; parameter < (int)_parameterList->size(); ++parameter) {
            _activationRecord.valueList.push_back((*_parameterList)[parameter]->execute()->copy());
        }
    }

    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        const DoubleValue* value = dynamic_cast<const DoubleValue*>(_activationRecord.valueList[0]);

        Operators::copy(_activationRecord.returnValue, new DoubleValue(::cos(value->execute())));

        return 0x00;
    }
};

class _Sin : public FunctionDefinition {
public:
    _Sin()
        : FunctionDefinition(new DoubleValue(), "sin", new List<Parameter>(new DoubleDeclaration("number", 0, 0)), 0x00, 0)
    {
        // tworzy rekord aktywacji
        for (int parameter = 0; parameter < (int)_parameterList->size(); ++parameter) {
            _activationRecord.valueList.push_back((*_parameterList)[parameter]->execute()->copy());
        }
    }

    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        const DoubleValue* value = dynamic_cast<const DoubleValue*>(_activationRecord.valueList[0]);

        Operators::copy(_activationRecord.returnValue, new DoubleValue(::sin(value->execute())));

        return 0x00;
    }
};

class _Sqrt : public FunctionDefinition {
public:
    _Sqrt()
        : FunctionDefinition(new DoubleValue(), "sqrt", new List<Parameter>(new DoubleDeclaration("number", 0, 0)), 0x00, 0)
    {
        // tworzy rekord aktywacji
        for (int parameter = 0; parameter < (int)_parameterList->size(); ++parameter) {
            _activationRecord.valueList.push_back((*_parameterList)[parameter]->execute()->copy());
        }
    }

    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        const DoubleValue* value = dynamic_cast<const DoubleValue*>(_activationRecord.valueList[0]);

        Operators::copy(_activationRecord.returnValue, new DoubleValue(::sqrt(value->execute())));

        return 0x00;
    }
};

class _Rad : public FunctionDefinition {
public:
    _Rad()
        : FunctionDefinition(new DoubleValue(), "rad", new List<Parameter>(new DoubleDeclaration("number", 0, 0)), 0x00, 0)
    {
        // tworzy rekord aktywacji
        for (int parameter = 0; parameter < (int)_parameterList->size(); ++parameter) {
            _activationRecord.valueList.push_back((*_parameterList)[parameter]->execute()->copy());
        }
    }

    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        const DoubleValue* value = dynamic_cast<const DoubleValue*>(_activationRecord.valueList[0]);

        Operators::copy(_activationRecord.returnValue, new DoubleValue(M_PI_180 * value->execute()));

        return 0x00;
    }
};

class _Pi : public FunctionDefinition {
public:
    _Pi()
        : FunctionDefinition(new DoubleValue(), "pi", 0x00, 0x00, 0)
    {
    }

    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        Operators::copy(_activationRecord.returnValue, new DoubleValue(M_PI));

        return 0x00;
    }
};

class _Read : public FunctionDefinition {
public:
    _Read()
        : FunctionDefinition(new StringValue(), "read", 0x00, 0x00, 0)
    {
    }

    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        std::string napis;
        std::cin >> napis;

        Operators::copy(_activationRecord.returnValue, new StringValue(napis));

        return 0x00;
    }
};

class _ParseDouble : public FunctionDefinition {
public:
    _ParseDouble()
        : FunctionDefinition(new DoubleValue(), "parseDouble", new List<Parameter>(new StringDeclaration("napis", "", 0)), 0x00, 0)
    {
        // tworzy rekord aktywacji
        for (int parameter = 0; parameter < (int)_parameterList->size(); ++parameter) {
            _activationRecord.valueList.push_back((*_parameterList)[parameter]->execute()->copy());
        }
    }

    virtual const Value* execute(RunTimeData& __runTimeData)
    {
        const StringValue* value = dynamic_cast<const StringValue*>(_activationRecord.valueList[0]);

        std::istringstream iss(value->execute());
        double number;
        iss >> number;

        Operators::copy(_activationRecord.returnValue, new DoubleValue(number));

        return 0x00;
    }
};

namespace FunkcjeBiblioteczne {
_Cos cos;
_Sin sin;
_Sqrt sqrt;
_Rad rad;
_Pi pi;
_Pow pow;
_Printf _printf;
_Scanf _scanf;

_Read _read;
_ParseDouble _parseDouble;
};

#undef M_PI_180

#endif
