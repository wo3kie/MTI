// Version 1.0

#ifndef _OPERATORY_H_
#define _OPERATORY_H_

#include "identyfikator.h"

/// Klasa bazowa dla wszystkich operatorow
class Operator{
    public:
        virtual ~Operator(){};
};

/// Klasa bazowa dla wszystkich operatorow unarnych
class OperatorUnarny:public Operator{
    public:
        virtual const Wartosc* operator()(const Wartosc*)const=0;
};

    /// Operator unarny minus
    class OperatorMinus: public OperatorUnarny{
        public:
            virtual const Wartosc* operator()(const Wartosc* __w1)const{
                return __w1->operator-();
            }
    };

    /// Operator unarny plus
    class OperatorPlus: public OperatorUnarny{
        public:
            virtual const Wartosc* operator()(const Wartosc* __w1)const{
                return __w1->operator+();
            }
    };

/// Klasa bazowa dla wszystkich operator�w binarnych
class OperatorBinarny:public Operator{
    public:
        virtual const Wartosc* operator()(const Wartosc*,const Wartosc*)const=0;
};

    /// Klasa bazowa dla wszystkich operator�w logicznych
    class OperatorLogicznyBi:public OperatorBinarny{
        public:
            virtual const Wartosc* operator()(const Wartosc*,const Wartosc*)const=0;
    };

        /// Operator r�wno�ci
        class OperatorRownosci:public OperatorLogicznyBi{
            public:
                virtual const Wartosc* operator()(const Wartosc* __w1,const Wartosc* __w2)const{
                    return __w1->operator==( __w2);
                }
        };

        /// Operator r�no�ci
        class OperatorNierownosci:public OperatorLogicznyBi{
            public:
                virtual const Wartosc* operator()(const Wartosc* __w1,const Wartosc* __w2)const{
                    return __w1->operator!=( __w2);
                }
        };

        /// Operator wi�kszo�ci
        class OperatorWiekszosci:public OperatorLogicznyBi{
            public:
                virtual const Wartosc* operator()(const Wartosc* __w1,const Wartosc* __w2)const{
                    return __w1->operator>( __w2);
                }
        };

        /// Operator mniejszo�ci
        class OperatorMniejszosci:public OperatorLogicznyBi{
            public:
                virtual const Wartosc* operator()(const Wartosc* __w1,const Wartosc* __w2)const{
                    return __w1->operator<( __w2);
                }
        };

        /// Operator alternatywy
        class OperatorAlternatywy:public OperatorLogicznyBi{
            public:
                virtual const Wartosc* operator()(const Wartosc* __w1,const Wartosc* __w2)const{
                    return __w1->operator||( __w2);
                }
        };

        /// Operator koniunkcji
        class OperatorKoniunkcji:public OperatorLogicznyBi{
            public:
                virtual const Wartosc* operator()(const Wartosc* __w1,const Wartosc* __w2)const{
                    return __w1->operator&&( __w2);
                }
        };

    /// Klasa bazowa dla wszystkich operator�w addytywnych: +, -
    class OperatorAddytywnyBi:public OperatorBinarny{
        public:
            virtual const Wartosc* operator()(const Wartosc*,const Wartosc*)const=0;
    };

        /// Operator dodawania
        class OperatorDodawania:public OperatorAddytywnyBi{
            public:
                virtual const Wartosc* operator()(const Wartosc* __w1,const Wartosc* __w2)const{
                    return __w1->operator+( __w2);
                }
        };

        /// Operator odejmowania
        class OperatorOdejmowania:public OperatorAddytywnyBi{
            public:
                virtual const Wartosc* operator()(const Wartosc* __w1,const Wartosc* __w2)const{
                    return __w1->operator-( __w2);
                }
        };

    /// Klasa bazowa dla wszystkich operator�w multiplikatywnych: *, /
    class OperatorMultiplikatywnyBi:public OperatorBinarny{
        public:
            virtual const Wartosc* operator()(const Wartosc*,const Wartosc*)const=0;
    };

        /// Operator dzielenia
        class OperatorDzielenia:public OperatorMultiplikatywnyBi{
            public:
                virtual const Wartosc* operator()(const Wartosc* __w1,const Wartosc* __w2)const{
                    return __w1->operator/( __w2);
                }
        };

        /// Operator mno�e�nia
        class OperatorMnozenia:public OperatorMultiplikatywnyBi{
            public:
                virtual const Wartosc* operator()(const Wartosc* __w1,const Wartosc* __w2)const{
                    return __w1->operator*( __w2);
                }
        };

    /// Operator przypisania. Nie dziedziczy po klasie 'OperatorBinarny' ze wzgl�du na niezgodno�c
    /// interfejsu. Pierwszy argument kt�ry pobiera nie mo�e byc sta�y.
    class OperatorPrzypisania:public Operator{
        public:
            virtual const Wartosc* operator()(Wartosc* __w1,const Wartosc* __w2)const{
                return __w1->operator=( __w2);
            }
    };

namespace Operatory{
    extern OperatorPrzypisania kopiuj;
};

#endif
