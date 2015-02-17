// Version 1.0

#include "libraryFunctions.h"
#include "callParameter.h"
extern Parameters parameters;
#include "program.h"
#include "functionCall.h"

void Program::dodajFunkcjeBiblioteczne()
{
    _tablicaFunkcji.insert("cos", &FunkcjeBiblioteczne::cos, Scope::globalScope);
    _tablicaFunkcji.insert("sin", &FunkcjeBiblioteczne::sin, Scope::globalScope);
    _tablicaFunkcji.insert("sqrt", &FunkcjeBiblioteczne::sqrt, Scope::globalScope);
    _tablicaFunkcji.insert("rad", &FunkcjeBiblioteczne::rad, Scope::globalScope);
    _tablicaFunkcji.insert("pi", &FunkcjeBiblioteczne::pi, Scope::globalScope);
    _tablicaFunkcji.insert("pow", &FunkcjeBiblioteczne::pow, Scope::globalScope);
    _tablicaFunkcji.insert("_printf", &FunkcjeBiblioteczne::_printf, Scope::globalScope);
    _tablicaFunkcji.insert("_scanf", &FunkcjeBiblioteczne::_scanf, Scope::globalScope);
    _tablicaFunkcji.insert("_read", &FunkcjeBiblioteczne::_read, Scope::globalScope);
    _tablicaFunkcji.insert("_parseDouble", &FunkcjeBiblioteczne::_parseDouble, Scope::globalScope);
}

void Program::analise()
{
    dodajFunkcjeBiblioteczne();

    // tworze strukture z danymi wykorzystywanymi podczas analizy
    AnalysisData analysisData;

    analysisData.errorCounter = 0;
    analysisData.blockNumber = Scope::globalScope;

    analysisData.visibilityStack = new std::stack<int>;
    // jestesmy w zasiegu globalnym, scope 0
    analysisData.visibilityStack->push(Scope::globalScope);

    analysisData.functionTable = &_tablicaFunkcji;
    analysisData.globalVariableTable = &_tablicaZmiennychGlobalnych;
    analysisData.localVariableTable = 0x00;

    // dodaje zmienne globalne to globalnej tablicy symboli
    if (_listaDeklaracji) {
        // w globalnym zasiegu globalna tablice jest lokalna :o)
        // declaration dodaje sie do lokalnej tablicy symboli

        analysisData.localVariableTable = &_tablicaZmiennychGlobalnych;

        _listaDeklaracji->analise(analysisData);

        analysisData.localVariableTable = 0x00; // wraca do poczatkowego ustawienia
    }

    // analizujemy funkcje programu
    _listaFunkcji->analise(analysisData);

    // sprawdzamy, czy analiza zakonczyla sie bezblednie
    if (analysisData.errorCounter != 0) {
        throw IException("Cannot run program becouse of error(s)");
    }

    _analizowany = true;
}

const Value* Program::execute()
{

    FunctionCall* start = new FunctionCall(_funkcjaGlowna, 0x00, 0);

    // tworze strukture z danymi wykorzystywanymi podczas wykonywania
    RunTimeData runTimeData;

    runTimeData.functionTable = &_tablicaFunkcji;
    runTimeData.globalVariableTable = &_tablicaZmiennychGlobalnych;
    runTimeData.localVariableTable = 0x00;

    // sprawdzamy czy program byl juz analizowany
    if (!_analizowany) {
        analise();
    }

    // szukamy funkcji glownej
    int funkcjaGlownaPozycja;
    try
    {
        funkcjaGlownaPozycja = _tablicaFunkcji.find(_funkcjaGlowna, Scope::globalScope);
    }
    catch (const UndefinedSymbol& __error)
    {
        throw UndefinedSymbol(std::string("Cannot find '") + _funkcjaGlowna + std::string("' function"));
    }

    // pobieram rekord aktywacji funkcj glownej
    runTimeData.activationRecord = &_tablicaFunkcji.value(std::make_pair(Scope::globalScope, funkcjaGlownaPozycja))->activationRecord();

    // kopiuje tablice wartosci ktora jest parametrem wywolania
    // do rekordu aktywacji
    runTimeData.activationRecord->valueList = parameters.argv;

    if (runTimeData.activationRecord->valueList.size() != parameters.argv.size()) {
        throw IException(std::string("Cannot call function: ") + _funkcjaGlowna);
    }

    for (int parameter = 0; parameter < runTimeData.activationRecord->valueList.size(); ++parameter) {
        if (runTimeData.activationRecord->valueList[parameter]->type() != parameters.argv[parameter]->type()) {
            throw IException(std::string("Cannot call function: ") + _funkcjaGlowna);
        }
    }

    _tablicaFunkcji.value(std::make_pair(Scope::globalScope, funkcjaGlownaPozycja))->execute(runTimeData);

    return 0x00;
}
