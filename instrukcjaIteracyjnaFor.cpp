// Version 1.0

#include "instrukcjaIteracyjnaFor.h"

/* ================================================================== execute */
Wartosc* InstrukcjaIteracyjnaFor::execute( RunTimeData& __runTimeData){
        _deklaracja->execute( __runTimeData);

        while( true){
                const WartoscDouble* wartosc=
                    dynamic_cast<const WartoscDouble*>( _warunek->execute( __runTimeData));
                // Konwersja Wartosc* -> WartoscDouble*

                if( static_cast<bool>(wartosc->execute(/* __runTimeData*/))){
                        _instrukcja->execute( __runTimeData);
                        _przypisanie->execute( __runTimeData);
                }
                else{
                        break;
                }
        }

        return 0x00;
}

/* ================================================================== analise */
void InstrukcjaIteracyjnaFor::analise( AnalysisData& __analysisData){
    __analysisData.stosWidocznosci->push( ++__analysisData.numerBloku);
    _deklaracja->analise( __analysisData);
    _warunek->analise( __analysisData);
    _przypisanie->analise( __analysisData);
    _instrukcja->analise( __analysisData);
    __analysisData.stosWidocznosci->pop();
}
