// Version 1.0

#ifndef _LITERAL_NAPISOWY_H_
#define _LITERAL_NAPISOWY_H_

#include "factor.h"

// Reprezentuje letter� napisowy
// Litera� napisowy jest ci�giem znak�w zawartych pomi�dzy cudzys�owami
// Litera� napisowy nie mo�e byc dlu�szy ni� jedna linia
class TextLiteral : public Factor {
public:
    // Konstruktor przyjmuje warto�c letter�u napisowego
    // oraz numer linii w kt�rej on wyst�pi�
    // Usuwa cudzys��w z napis�w.: "kasia" -> kasia
    inline TextLiteral(const std::string& __text, int __lineNumber)
        : Factor(String, __lineNumber)
        , _value(__text.substr(1, __text.size() - 2))
    {
    }

    // Zwraca letter� napisowy
    virtual const Value* execute(RunTimeData& _runTimeData) {
        return &_value; }

    // Analizuje letter� napisowy
    virtual void analise(AnalysisData&)
    {
        // Ta klasa jest li�ciem drzewa sk�adniowego. Metoda 'analise' nie robi nic.
        // Na niej ko�czy si� przechodzenie drzewa sk�adniowego 'w gl�b'.
    }

    // Zwraca type letter�u. Zawsze jest to string
    virtual Type type() const {
        return String; }

protected:
    // Przechowuje letter� napisowy
    StringValue _value;
};

#endif
