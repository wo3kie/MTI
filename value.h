// Version 1.0

#ifndef _WARTOSC_H_
#define _WARTOSC_H_

#include "exceptions.h"

#include <iostream>

enum Typ{Void,Double,String};
enum Access{ReadOnly,ReadWrite};

// Klasa interfejsu dla wartosci.
class Wartosc{
    public:
        // Konstruktor przyjmuje typ wartoœci oraz specyfikacje dostêpu
        Wartosc(Typ __typ,Access __access)
        :_typ(__typ),
        _access(__access){
        }

        virtual ~Wartosc(){
        };

        // Metody te s¹ wywolywane przez odpowiednie klasy 'Operator...'
        virtual const Wartosc* operator+(const Wartosc*)const=0;
        virtual const Wartosc* operator+()const=0;
        virtual const Wartosc* operator-(const Wartosc*)const=0;
        virtual const Wartosc* operator-()const=0;
        virtual const Wartosc* operator*(const Wartosc*)const=0;
        virtual const Wartosc* operator/(const Wartosc*)const=0;

        virtual const Wartosc* operator==(const Wartosc*)const=0;
        virtual const Wartosc* operator!=(const Wartosc*)const=0;
        virtual const Wartosc* operator<(const Wartosc*)const=0;
        virtual const Wartosc* operator>(const Wartosc*)const=0;
        virtual const Wartosc* operator||(const Wartosc*)const=0;
        virtual const Wartosc* operator&&(const Wartosc*)const=0;

        virtual const Wartosc* operator=(const Wartosc*)=0;

        // Metody drukuj¹ce i wczytuj¹ce wartoœci
        virtual const Wartosc* printf()const=0;
        virtual const Wartosc* scanf()=0;

        // Metoda okreœla, czy wartoœc jest tylko do odczytu 'ReadOnly' czy
        // mo¿na do niej zapisywac 'ReadWrite'
        Access access()const{return _access;}

        // Ustawia zmienn¹ tylko do odczytu
        void readOnly(){_access=ReadOnly;}

        // Zwraca typ wartoœci: 'Double', 'String'
        Typ typ()const{return _typ;}

        // Virtual constructor
        virtual Wartosc* kopiuj()const=0;

    protected:
        // Przechowuje typ wartoœci
        Typ _typ;

        // Przechowuje typ dostepu do wartoœci
        Access _access;
};

// Wartoœc double reprezentuje liczby rzeczywiste w programie u¿ytkownika.
class WartoscDouble:public Wartosc{
    public:
        // Konstruktor przyjmuje wartoœc oraz specyfikacjê dostêpu
        WartoscDouble(double __wartosc= 0,Access __access= ReadWrite)
        :Wartosc(Double,__access),
        _wartosc(__wartosc){
        }

        // Dodaje dwie wartoœci
        virtual const Wartosc* operator+(const Wartosc* __wartosc)const{
            const WartoscDouble* wartoscDouble=
            dynamic_cast< const WartoscDouble*>( __wartosc);

            return new WartoscDouble( _wartosc+ wartoscDouble->execute());
        }

        // Nie robi nic
        virtual const Wartosc* operator+()const{
            return this;
        }

        // Odejmuje dwie wartoœci
        virtual const Wartosc* operator-(const Wartosc* __wartosc)const{
            const WartoscDouble* wartoscDouble=
            dynamic_cast< const WartoscDouble*>( __wartosc);

            return new WartoscDouble( _wartosc- wartoscDouble->execute());
        }

        // Zwraca wartoœc o przeciwnym znaku
        virtual const Wartosc* operator-()const{
            return new WartoscDouble( -_wartosc);
        }

        // Mno¿y dwie wartoœci
        virtual const Wartosc* operator*(const Wartosc* __wartosc)const{
            const WartoscDouble* wartoscDouble=
            dynamic_cast< const WartoscDouble*>( __wartosc);

            return new WartoscDouble( _wartosc* wartoscDouble->execute());
        }

        // Dzieli dwie wartoœci
        virtual const Wartosc* operator/(const Wartosc* __wartosc)const{
            const WartoscDouble* wartoscDouble=
            dynamic_cast< const WartoscDouble*>( __wartosc);

            double dzielnik= wartoscDouble->execute();

            if( dzielnik){
                return new WartoscDouble( _wartosc/ dzielnik);
            }
            else{
                throw DividedByZero();
            }
        }

        // Okreœla, czy wartoœci s¹ równe
        virtual const Wartosc* operator==(const Wartosc* __wartosc)const{
            const WartoscDouble* wartoscDouble=
            dynamic_cast< const WartoscDouble*>( __wartosc);

            return new WartoscDouble( _wartosc== wartoscDouble->execute());
        }

        // Okreœla, czy wartoœci s¹ ró¿ne
        virtual const Wartosc* operator!=(const Wartosc* __wartosc)const{
            const WartoscDouble* wartoscDouble=
            dynamic_cast< const WartoscDouble*>( __wartosc);

            return new WartoscDouble( _wartosc!= wartoscDouble->execute());
        }

        // Okreœla, czy wartoœc jest wiêksza
        virtual const Wartosc* operator>(const Wartosc* __wartosc)const{
            const WartoscDouble* wartoscDouble=
            dynamic_cast< const WartoscDouble*>( __wartosc);

            return new WartoscDouble( _wartosc> wartoscDouble->execute());
        }

        // Okreœla, czy wartoœci jest mniejsza
        virtual const Wartosc* operator<(const Wartosc* __wartosc)const{
            const WartoscDouble* wartoscDouble=
            dynamic_cast< const WartoscDouble*>( __wartosc);

            return new WartoscDouble( _wartosc< wartoscDouble->execute());
        }

        // Zwraca alternatywe dwóch wartoœci
        virtual const Wartosc* operator||(const Wartosc* __wartosc)const{
            const WartoscDouble* wartoscDouble=
            dynamic_cast< const WartoscDouble*>( __wartosc);

            if( _wartosc){
                return new WartoscDouble( true);
            }

            return new WartoscDouble( wartoscDouble->execute());
        }

        // Zwraca koniunkcje dwóch wartoœci
        virtual const Wartosc* operator&&(const Wartosc* __wartosc)const{
            const WartoscDouble* wartoscDouble=
            dynamic_cast< const WartoscDouble*>( __wartosc);

            if( !_wartosc){
                return new WartoscDouble( false);
            }

            return new WartoscDouble( wartoscDouble->execute());
        }

        // Porównuje dwie wartoœci
        virtual const Wartosc* operator=(const Wartosc* __wartosc){
            const WartoscDouble* wartoscDouble=
            dynamic_cast< const WartoscDouble*>( __wartosc);

            _wartosc= wartoscDouble->execute();

            return this;
        }

        // Drukuje wartoœc na stdout
        virtual const Wartosc* printf()const{
            std::cout<< _wartosc;
            std::cout.flush();
            return this;
        }

        // Wczytuje wartoœc z stdin
        virtual const Wartosc* scanf(){
            std::cin>> _wartosc;
            return this;
        }

        // Zwraca wartoœc
        double execute()const{
            return _wartosc;
        }

        double& assign(){
            return _wartosc;
        }

        // Virtual constructor
        virtual WartoscDouble* kopiuj()const{
            return new WartoscDouble(*this);
        }

    private:
        // Przechowuje wartoœc rzeczywist¹
        double _wartosc;
};

// Wartosc string reprezentuje napisy w programie u¿ytkowanika
class WartoscString:public Wartosc{
    public:
        // Konstruktor przyjmuje wartoœc oraz specyfikacje dostêpu
        WartoscString(std::string __wartosc= "", Access __access= ReadWrite)
        :Wartosc(String, __access),
        _wartosc(__wartosc){
        }

        // Operator nie jest zaimplementowany
        virtual const Wartosc* operator+(const Wartosc* __wartosc)const{
            return 0x00;
        }

        // Operator nie jest zaimplementowany
        virtual const Wartosc* operator+()const{
            return 0x00;
        }

        // Operator nie jest zaimplementowany
        virtual const Wartosc* operator-(const Wartosc* __wartosc)const{
            return 0x00;
        }

        // Operator nie jest zaimplementowany
        virtual const Wartosc* operator-()const{
            return 0x00;
        }

        // Operator nie jest zaimplementowany
        virtual const Wartosc* operator*(const Wartosc* __wartosc)const{
            return 0x00;
        }

        // Operator nie jest zaimplementowany
        virtual const Wartosc* operator/(const Wartosc* __wartosc)const{
            return 0x00;
        }

        // Operator nie jest zaimplementowany
        virtual const Wartosc* operator==(const Wartosc* __wartosc)const{
            return 0x00;
        }

        // Operator nie jest zaimplementowany
        virtual const Wartosc* operator!=(const Wartosc* __wartosc)const{
            return 0x00;
        }

        // Operator nie jest zaimplementowany
        virtual const Wartosc* operator>(const Wartosc* __wartosc)const{
            return 0x00;
        }

        // Operator nie jest zaimplementowany
        virtual const Wartosc* operator<(const Wartosc* __wartosc)const{
            return 0x00;
        }

        // Operator nie jest zaimplementowany
        virtual const Wartosc* operator||(const Wartosc* __wartosc)const{
            return 0x00;
        }

        // Operator nie jest zaimplementowany
        virtual const Wartosc* operator&&(const Wartosc* __wartosc)const{
            return 0x00;
        }

        // Porównuje dwie wartoœci
        virtual const Wartosc* operator=(const Wartosc* __wartosc){
            const WartoscString* wartoscString=
            dynamic_cast< const WartoscString*>( __wartosc);

            if( _access== ReadOnly){
                throw AssignToConstValue();
            }
            else{
                _wartosc= wartoscString->execute();
            }

            return this;
        }

        // Drukuje wartoœc na stdout
        virtual const Wartosc* printf()const{
            std::cout<< _wartosc;
            std::cout.flush();
            return this;
        }

        // Wczytuje wartoœc z stdin
        virtual const Wartosc* scanf(){
            std::cin>> _wartosc;
            return this;
        }

        // Zwraca wartoœc
        std::string execute()const{
            return _wartosc;
        }

        std::string& assign(){
            return _wartosc;
        }

        // Virtual constructor
        virtual WartoscString* kopiuj()const{
            return new WartoscString(*this);
        }

    private:
        // Przechowuje wartoœc
        std::string _wartosc;
};

#endif
