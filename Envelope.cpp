/*
  ==============================================================================

    Envelope.cpp
    Created: 29 Oct 2015 3:57:20pm
    Author:  Eugenio 

  ==============================================================================
*/

#include "Envelope.h"

float Envelope::nextSample()
{
    /* Se il generatore è in A-D-R e currentSampleIndex ha raggiunto il valore di nextStageSampleIndex:
    - vai all'elemento successivo e da R a END col modulo
    - enterStage -> newStage
    ModificoCurrentLevel e incremento currentSampleIndex per tenere traccia del tempo.
     
    No in OFF e S: in queste fasi il livello deve rimanere lo stesso, quindi non c'è bisogno di calcolare. */
    
    /*currentLevel=currentlevel*multiplier*/
    
    if (currentStage != OFF && currentStage != SUSTAIN)
    {
        /*nuovo stage*/
        if (currentSampleIndex == nextStageSampleIndex)
            enterStage(static_cast<EnvelopeStage>((currentStage + 1) % kNumEnvelopeStages));
        currentLevel *= multiplier;
        currentSampleIndex++;
    }
    return currentLevel;
}

/* La variazione di volume è esponenziale.
   Calcolo un moltiplicatore (num vicino a 1). Moltiplico CurrentLevel con questo per ottenere una transizione esponenziale. */

void Envelope::calculateMultiplier(float startLevel,
                                            float endLevel,
                                            unsigned long long lengthInSamples) 
{
    multiplier = 1.0 + (log(endLevel) - log(startLevel)) / (lengthInSamples);
}

/* VAI ALLO  STATO SUCCESSIVO,
   INTANTO RESTO TRA OFF E SUSTAIN FINO A QUANDO NON VIENE CHIAMATA enterStage */

/* Aggiorno currentStage al nuovo valore, currentSampleIndex deve contare di nuovo da zero.
   Calcolo quanto tempo (quanti campioni) ci vorrà fino alla fase successiva (necessario solo per A D e R).
   stageValue[currentStage] è un float (la durata fase in secondi), moltiplico per sampleRate per ottenere la lunghezza in campioni.
 
   Caso OFF, imposto il livello a 0 e moltiplicatore 1 (uguale)
   Caso ATTACK, inizio da minimumLevel (0.001) e calcolo il moltiplicatore (quindi transizione da CurrentLevel a 1.0)
   Caso DECAY, cado dal valore corrente al livello di sustain, utilizzando fmax per far si che non raggiunga lo 0.
   Caso RELEASE decade dal CurrentLevel al minimumLevel. 
    
   Caso SUSTAIN contiene un valore di livello, non un valore di tempo quindi lo assegno a CurrentLevel.
*/

/* nextStageSampleIndex= valore slider (0-5 * 44110)*/
void Envelope::enterStage(EnvelopeStage newStage) 
{
    currentStage = newStage;
    currentSampleIndex = 0;
    if (currentStage == OFF || currentStage == SUSTAIN)
        nextStageSampleIndex = 0;
    else 
        nextStageSampleIndex = stageValue[currentStage] * sampleRate;
    switch (newStage) 
    {
        case OFF:
            currentLevel = 0.0;
            multiplier = 1.0;
            break;
        case ATTACK:
            currentLevel = minimumLevel;
            calculateMultiplier(currentLevel,
                                1.0,
                                nextStageSampleIndex);
            break;
        case DECAY:
            currentLevel = 1.0;
            calculateMultiplier(currentLevel,
                                max(stageValue[SUSTAIN], minimumLevel),
                                nextStageSampleIndex);
            break;
        case SUSTAIN:
            currentLevel = stageValue[SUSTAIN];
            multiplier = 1.0;
            break;
        case RELEASE:
            calculateMultiplier(currentLevel,
                                minimumLevel,
                                nextStageSampleIndex);
            break;
        default:
            break;
    }
}

void Envelope::setSampleRate(float newSampleRate) 
{
    sampleRate = newSampleRate;
}