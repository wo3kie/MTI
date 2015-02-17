// Version 1.0

#ifndef _LITERAL_NAPISOWY_H_
#define _LITERAL_NAPISOWY_H_

#include "factor.h"

// Reprezentuje letterl napisowy
// Literal napisowy jest ciagiem znakow zawartych pomiedzy cudzyslowami
// Literal napisowy nie mo¿e byc dlu¿szy ni¿ jedna linia
class TextLiteral : public Factor {
public:
    // Konstruktor przyjmuje wartosc letterlu napisowego
    // oraz numer linii w ktorej on wystapil
    // Usuwa cudzyslow z napisow.: "kasia" -> kasia
    inline TextLiteral(const std::string& __text, int __lineNumber)
        : Factor(String, __lineNumber)
        , _value(__text.substr(1, __text.size() - 2))
    {
    }

    // Zwraca letterl napisowy
    virtual const Value* execute(RunTimeData& _runTimeData) {
        return &_value; }

    // Analizuje letterl napisowy
    virtual void analise(AnalysisData&)
    {
        // Ta klasa jest lisciem drzewa skladniowego. Metoda 'analise' nie robi nic.
        // Na niej konczy sie przechodzenie drzewa skladniowego 'w glab'.
    }

    // Zwraca type letterlu. Zawsze jest to string
    virtual Type type() const {
        return String; }

protected:
    // Przechowuje letterl napisowy
    StringValue _value;
};

#endif
