// Version 1.0

#ifndef _LISTA_H_
#define _LISTA_H_

#include "analysisData.h"

// Produkcja gramatyczna:
//
//         A -> A b | b
//
//     maj¹ca postac drzewa
//
//             A
//           /   \
//          A     b3
//        /   \
//       A     b2
//       |
//       b1
//
//  jest zamieniana na postac listy b1->b2->b3
//
// Listy wykorzystywane w programie:
//   listaDeklaracji, instructionList, parameterList, expressionList

template< typename T, typename E= IException>
class List{
    public:
        typedef T value_type;
        typedef E exception_type;

        // Konstruktor dla produkcji A -> A a
        List(List* __list,T* __pointerT)
        :_list( __list->_list){
            _list.push_back( __pointerT);
        }

        // Konstruktor dla produkcji A -> a
        List(T* __pointerT){
            if( __pointerT){
                _list.push_back( __pointerT);
            }
        }

        // zwraca ile lista powiada elementów
        unsigned size()const{ return _list.size();}

        // Operator indeksowania listy
        T* operator[](unsigned __index){ return _list[ __index];}

        // Przechodzi po liœcie i analizuje jej elementy
        void analise( AnalysisData& __analysisData){
            for( unsigned index=0; index< _list.size(); ++index){
                try{
                    _list[ index]->analise( __analysisData);
                }
                catch( const E& __error){
                    ++__analysisData.errorCounter;
                    std::cerr<< _list[ index]->linia()<<": " << __error.what()<< std::endl;
                }
            }
        }

        // Przechodzi po liœcie i wykonuje jej elementy
        void execute(RunTimeData& __runTimeData){
            for( unsigned index=0; index< _list.size(); ++index){
                try{
                    _list[ index]->execute(__runTimeData);
                }
                catch( const E& __error){
                    std::cerr<< _list[ index]->linia()<<": " << __error.what()<< std::endl;
                    throw IException();
                }
            }
        }

    private:
        // Tablica przechowuj¹ca poszczególne elementy listy
        std::vector<T*> _list;
};

#endif
