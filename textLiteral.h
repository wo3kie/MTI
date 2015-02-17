// Version 1.0

#ifndef _LITERAL_NAPISOWY_H_
#define _LITERAL_NAPISOWY_H_

#include "factor.h"

// Reprezentuje letter³ napisowy
// Litera³ napisowy jest ci¹giem znaków zawartych pomiêdzy cudzys³owami
// Litera³ napisowy nie mo¿e byc dlu¿szy ni¿ jedna linia
class TextLiteral : public Factor {
public:
    // Konstruktor przyjmuje wartoœc letter³u napisowego
    // oraz numer linii w której on wyst¹pi³
    // Usuwa cudzys³ów z napisów.: "kasia" -> kasia
    inline TextLiteral(const std::string& __text, int __lineNumber)
        : Factor(String, __lineNumber)
        , _value(__text.substr(1, __text.size() - 2))
    {
    }

    // Zwraca letter³ napisowy
    virtual const Value* execute(RunTimeData& _runTimeData) {
        return &_value; }

    // Analizuje letter³ napisowy
    virtual void analise(AnalysisData&)
    {
        // Ta klasa jest liœciem drzewa sk³adniowego. Metoda 'analise' nie robi nic.
        // Na niej koñczy siê przechodzenie drzewa sk³adniowego 'w gl¹b'.
    }

    // Zwraca type letter³u. Zawsze jest to string
    virtual Type type() const {
        return String; }

protected:
    // Przechowuje letter³ napisowy
    StringValue _value;
};

#endif
