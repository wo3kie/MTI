// Version 1.0

#ifndef _TABLICA_SLOW_KLUCZOWYCH_H_
#define _TABLICA_SLOW_KLUCZOWYCH_H_

#include "parser.h"

#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>

class TablicaSlowKluczowych{
    public:
        explicit TablicaSlowKluczowych(int __nieSlowo)
        :_nieSlowo(__nieSlowo){
            dodajSlowo( "do", Parser::DO );
            dodajSlowo( "double", Parser::DOUBLE );
            dodajSlowo( "string", Parser::STRING );
            dodajSlowo( "while", Parser::WHILE );
            dodajSlowo( "if", Parser::IF );
            dodajSlowo( "for", Parser::FOR );
            dodajSlowo( "return", Parser::RETURN );
            dodajSlowo( "printf", Parser::PRINTF );
            dodajSlowo( "scanf", Parser::SCANF );
            dodajSlowo( "else", Parser::ELSE );
            dodajSlowo( "endl",Parser::ENDL );
        }

        virtual ~TablicaSlowKluczowych(){}

        virtual int nieSlowo()const{ return _nieSlowo;}

        /// Podajemy co ma zwr�cic tablica je�eli lekser znajdzie identyfikator
        /// nie b�d�cy s�owem kluczowym
        virtual void nieSlowo(int __nieSlowo){_nieSlowo=__nieSlowo;}

        /// Dodajemy s�owo kluczowe oraz jego warto�c
        virtual bool dodajSlowo(const std::pair<const std::string, int>& __slowo){
            return (_slowaKluczowe.insert(__slowo)).second;
        }

        /// Dodajemy s�owo kluczowe oraz jego warto�c
        virtual bool dodajSlowo(const char* __slowo, int __wartosc){
            return dodajSlowo( make_pair(std::string(__slowo),__wartosc));
        }

        /// Sprawdzamy, czy znaleziony przez lekser identyfikator jest s�owem kluczowym
        inline virtual int znajdzSlowo(const std::string& __slowo)const;

    protected:
        int _nieSlowo;

    private:
        std::map<const std::string, int> _slowaKluczowe;
};

/* ============================================================== znajdzSlowo */
inline int TablicaSlowKluczowych::znajdzSlowo(const std::string& __slowo)const{
    std::map<const std::string,int>::const_iterator p= _slowaKluczowe.find(__slowo);

    if(p!= _slowaKluczowe.end()){
        return p->second;
    }
    else{
        return _nieSlowo;
    }
}

#endif
