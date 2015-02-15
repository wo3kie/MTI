// Version 1.0

#ifndef _LISTA_H_
#define _LISTA_H_

#include "analysisData.h"

/// Produkcja gramatyczna:
///
///         A -> A b | b
///
///     maj¹ca postac drzewa
///
///             A
///           /   \
///          A     b3
///        /   \
///       A     b2
///       |
///       b1
///
///  jest zamieniana na postac listy b1->b2->b3
///
/// Listy wykorzystywane w programie:
///   listaDeklaracji, listaInstrukcji, listaParametrow, listaWyrazen

template< typename T, typename E= IException>
class Lista{
    public:
        typedef T value_type;
        typedef E exception_type;

        /// Konstruktor dla produkcji A -> A a
        Lista(Lista* __lista,T* __pointerT)
        :_lista( __lista->_lista){
            _lista.push_back( __pointerT);
        }

        /// Konstruktor dla produkcji A -> a
        Lista(T* __pointerT){
            if( __pointerT){
                _lista.push_back( __pointerT);
            }
        }

        /// zwraca ile lista powiada elementów
        unsigned size()const{ return _lista.size();}

        /// Operator indeksowania listy
        T* operator[](unsigned __index){ return _lista[ __index];}

        /// Przechodzi po liœcie i analizuje jej elementy
        void analise( AnalysisData& __analysisData){
            for( unsigned index=0; index< _lista.size(); ++index){
                try{
                    _lista[ index]->analise( __analysisData);
                }
                catch( const E& __error){
                    ++__analysisData.liczbaBledow;
                    std::cerr<< _lista[ index]->linia()<<": " << __error.what()<< std::endl;
                }
            }
        }

        /// Przechodzi po liœcie i wykonuje jej elementy
        void execute(RunTimeData& __runTimeData){
            for( unsigned index=0; index< _lista.size(); ++index){
                try{
                    _lista[ index]->execute(__runTimeData);
                }
                catch( const E& __error){
                    std::cerr<< _lista[ index]->linia()<<": " << __error.what()<< std::endl;
                    throw IException();
                }
            }
        }

    private:
        /// Tablica przechowuj¹ca poszczególne elementy listy
        std::vector<T*> _lista;
};

#endif
