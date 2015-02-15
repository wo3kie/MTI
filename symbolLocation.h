// Version 1.0

#ifndef _SYMBOL_LOCATION_H_
#define _SYMBOL_LOCATION_H_

#include <string>

/// Struktura pamiêta polo¿enie symbolu leksykalnego oraz jego wartosc leksykalna
struct SymbolLocation{
    /// Przechowuje w ktorej linii byl symbol
    static int numerLinii;

    /// Przechowuje leksem
    static std::string leksem;
};

#endif
