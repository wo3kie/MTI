// Version 1.0

#include "instrukcjaWarunkowaIf.h"

/* ================================================================== execute */
const Wartosc* InstrukcjaWarunkowaIf::execute( RunTimeData& __runTimeData){
    const WartoscDouble* wartosc=
        dynamic_cast<const WartoscDouble*>( _wyrazenie->execute( __runTimeData));

    if( static_cast<bool>(wartosc->execute())){
        _instrukcja1->execute(__runTimeData);
    }
    else{
        // sprawdzamy czy istnieje druga instrukcja warunkowa
        if( _instrukcja2){
            _instrukcja2->execute( __runTimeData);
        }
    }

    return 0x00;
}

/* ================================================================== analise */
void InstrukcjaWarunkowaIf::analise( AnalysisData& __analysisData){
    _wyrazenie->analise( __analysisData);
    _instrukcja1->analise( __analysisData);

    // sprawdzamy czy istnieje druga instrukcja warunkowa
    if( _instrukcja2){
        _instrukcja2->analise( __analysisData);
    }
}
