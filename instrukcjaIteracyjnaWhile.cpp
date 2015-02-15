// Version 1.0

#include "instrukcjaIteracyjnaWhile.h"

/* ================================================================== execute */
Wartosc* InstrukcjaIteracyjnaWhile::execute( RunTimeData& __runTimeData){
	while( true){
		const WartoscDouble* wartosc=
		    dynamic_cast<const WartoscDouble*>( _wyrazenie->execute( __runTimeData));
                // Konwersja Wartosc* -> WartoscDouble*

		if( static_cast<bool>(wartosc->execute(/* __runTimeData*/))){
			_instrukcja->execute( __runTimeData);
		}
		else{
			break;
		}
	}

	return 0x00;
}

/* ================================================================== analise */
void InstrukcjaIteracyjnaWhile::analise( AnalysisData& __analysisData){
    _wyrazenie->analise( __analysisData);
    _instrukcja->analise( __analysisData);
}
