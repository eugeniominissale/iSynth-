//
//  filter.cpp
//  iSynth
//
//  Created by Eugenio  on 02/11/15.
//
//

#include "Filter.h"

/*La process viene chiamata per ogni campione*/
float Filter::process(float inputValue)
{
    if (inputValue == 0.0) return inputValue;
    float calculatedCutoff = getCalculatedCutoff();
    
    buf0 += calculatedCutoff * (inputValue - buf0 + feedbackAmount * (buf0 - buf1)); //FPB primo ordine (-6db/8) --- + feedbackAmount * (buf0 - buf1), moltiplico per AMT il risultato di un filtro passa banda (enfatizzazione frequenza). feedbackAmount è proporzionale alla risonanza
    buf1 += calculatedCutoff * (buf0 - buf1); //FPB primo ordine (-6db/8)
    //buf1=f(buf1) -> IIR
    
    switch (mode)
    {
        case LP:
            return buf1; // -12db/8
        case HP:
            return inputValue - buf0; //alte=campione - basse frequenze
        case BP:
            return buf0 - buf1;
        default:
            return 0.0;
        /*case LP:
        {
            buf2 += calculatedCutoff * (buf1 - buf2); buf3 += calculatedCutoff * (buf2 - buf3); 
            return buf3;
        }
        case HP:
        {
            buf2 += calculatedCutoff * (buf1 - buf2); buf3 += calculatedCutoff * (buf2 - buf3); 
            return inputValue - buf3;
        }
        case BP:
        {
            buf2 += calculatedCutoff * (buf1 - buf2); buf3 += calculatedCutoff * (buf2 - buf3);
            return buf0 - buf3;
        }*/
    }
}