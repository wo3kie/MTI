// Version 1.0

#ifndef _TABLICA_SLOW_KLUCZOWYCH_H_
#define _TABLICA_SLOW_KLUCZOWYCH_H_

#include "parser.h"

#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>

class KeywordTable{
    public:
        explicit KeywordTable(int __notKeyword)
        :_notKeyword(__notKeyword){
            addKeyword( "double", Parser::DOUBLE );
            addKeyword( "string", Parser::STRING );
            addKeyword( "while", Parser::WHILE );
            addKeyword( "if", Parser::IF );
            addKeyword( "return", Parser::RETURN );
            addKeyword( "printf", Parser::PRINTF );
            addKeyword( "scanf", Parser::SCANF );
            addKeyword( "else", Parser::ELSE );
            addKeyword( "endl",Parser::ENDL );
        }

        virtual ~KeywordTable(){}

        virtual int notKeyword()const{ return _notKeyword;}

        // Podajemy co ma zwr�cic tablica je�eli lekser znajdzie identifier
        // nie b�d�cy s�owem kluczowym
        virtual void notKeyword(int __notKeyword){_notKeyword=__notKeyword;}

        // Dodajemy s�owo kluczowe oraz jego warto�c
        virtual bool addKeyword(const std::pair<const std::string, int>& __keyword){
            return (_keywords.insert(__keyword)).second;
        }

        // Dodajemy s�owo kluczowe oraz jego warto�c
        virtual bool addKeyword(const char* __keyword, int __value){
            return addKeyword( make_pair(std::string(__keyword),__value));
        }

        // Sprawdzamy, czy znaleziony przez lekser identifier jest s�owem kluczowym
        inline virtual int findKeyword(const std::string& __keyword)const;

    protected:
        int _notKeyword;

    private:
        std::map<const std::string, int> _keywords;
};

/* ============================================================== findKeyword */
inline int KeywordTable::findKeyword(const std::string& __keyword)const{
    std::map<const std::string,int>::const_iterator p= _keywords.find(__keyword);

    if(p!= _keywords.end()){
        return p->second;
    }
    else{
        return _notKeyword;
    }
}

#endif
