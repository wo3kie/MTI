// Version 1.0

#include "doWhileInstruction.h"

/* ================================================================== execute */
Wartosc* InstrukcjaIteracyjnaDoWhile::execute( RunTimeData& __runTimeData){
        while( true){
            _listaInstrukcji->execute( __runTimeData);

            const WartoscDouble* wartosc=
                dynamic_cast<const WartoscDouble*>( _wyrazenie->execute( __runTimeData));

            if( !static_cast<bool>(wartosc->execute())){
                break;
            }
        }

        return 0x00;
}

/* ================================================================== analise */
void InstrukcjaIteracyjnaDoWhile::analise( AnalysisData& __analysisData){
    _listaInstrukcji->analise( __analysisData);
    _wyrazenie->analise( __analysisData);
}
