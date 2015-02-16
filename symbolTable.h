// Version 4.0

#ifndef _TABLICA_SYMBOLI_H_
#define _TABLICA_SYMBOLI_H_
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>

#include "value.h"

class FunctionDefinition;

template< typename T>
class Tablica{
    public:
        typedef T value_type;

        Tablica(){}
        virtual ~Tablica(){}

        int size()const{return _table.size();}

        virtual int insert( std::string __identifier, T* __value, int __zasieg) {
            int position=0;

            for( int a=0; a<(int) _table.size(); ++a){
                if( _table[a].scope== __zasieg){
                    ++position;
                    if( _table[a].identifier== __identifier){
                        throw MultipleDeclaration( __identifier);
                    }
                }
            }

            _table.push_back( _Symbol(__identifier, __value, __zasieg, position));
            return position;
        }

        virtual int find( std::string __identifier, int __zasieg) const {
            for( int a=0; a<(int) _table.size(); ++a){
                if( _table[a].identifier== __identifier && _table[a].scope== __zasieg){
                    return _table[a].position;
                }
            }

            throw UndefinedSymbol( __identifier);
        }

        virtual T* value(int __zasieg, int __pozycja) {
            for( int a=0; a<(int) _table.size(); ++a){

                if( _table[a].scope== __zasieg && _table[a].position== __pozycja){
                    return _table[a].value;
                }
            }
            
            return 0x00;
        }

        virtual T* value( const std::pair<int,int> __pozycja){
            return value( __pozycja.first, __pozycja.second);
        }

    protected:
        struct _Symbol{
            _Symbol( std::string __identifier, T* __value, int __zasieg, int __pozycja)
            :identifier( __identifier),value( __value), scope( __zasieg), position( __pozycja){}

            _Symbol()
            :identifier(""),value(0),scope(0),position(0){}

            std::string identifier;
            T* value;
            int scope;
            int position;
        };

        std::vector< _Symbol> _table;
};

class FunctionTable:public Tablica< FunctionDefinition>{
    public:
        FunctionTable(){}
        virtual ~FunctionTable(){}

    private:
// nie mozna kopiowac
    FunctionTable( const FunctionTable&);
    const FunctionTable operator=( const FunctionTable&);
};

class VariableTable:public Tablica< Value>{
    public:
        VariableTable(){}

        virtual ~VariableTable(){}

        VariableTable( const VariableTable& __table){
            _copy( __table);
        }

        const VariableTable& operator=(const VariableTable& __table){
            _copy( __table);
            return *this;
        }

    private:
        void _copy( const VariableTable& __table){
            _table.resize( __table.size());

            for( int a=0; a< (int)__table.size(); ++a){
                _table[a].identifier= __table._table[a].identifier;
                _table[a].value= __table._table[a].value->copy();
                _table[a].scope= __table._table[a].scope;
                _table[a].position= __table._table[a].position;
            }
        }
};

namespace Scope{
    const int globalScope= 0;
    const int parameterScope= 1;
    const int returnPosition= 0;
}

#endif
