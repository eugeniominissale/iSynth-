/*
  ==============================================================================

    Envelope.h
    Created: 29 Oct 2015 3:57:20pm
    Author:  Eugenio 

  ==============================================================================
*/

#ifndef ENVELOPE_H_INCLUDED
#define ENVELOPE_H_INCLUDED

#include <cmath>
#include <math.h>
#include <algorithm>

using namespace std;

/*A-D-R dopo un po' viene richiamata enterStage e va al prossimo stage.
 OFF-S sta all'infinito, fino a che non viene chiamata enterStage dall'esterno
 RELEASE: si decade da livello corrente a zero: release può entrare da A-D-S
 
 nextSample() genera un float da 0 a 1 che verrà moltiplicato per ogni campione all'interno della process*/

class Envelope
{
public:
    enum EnvelopeStage 
    {
        OFF = 0,
        ATTACK, // TEMPO
        DECAY, // TEMPO
        SUSTAIN, // LIVELLO
        RELEASE, // TEMPO
        kNumEnvelopeStages
    };
    void enterStage(EnvelopeStage newStage);
    float nextSample();
    void setSampleRate(float newSampleRate);
    inline EnvelopeStage getCurrentStage() const { return currentStage; };
    const float minimumLevel;
	void setStageValue(int stage, float value){ stageValue[stage]=value; }
	float getStageValue(int stage){ return stageValue[stage]; } //onlyfloat

    Envelope():
    minimumLevel(0.0001),
    currentStage(OFF),
    currentLevel(minimumLevel),
    multiplier(1.0),
    sampleRate(44100.0),
    currentSampleIndex(0),
    nextStageSampleIndex(0) 
    {
        /*INIZIALIZZAZIONE*/
        stageValue[OFF] = 0.0;
        stageValue[ATTACK] = 0.8;
        stageValue[DECAY] = 0.8;
        stageValue[SUSTAIN] = 0.5;
        stageValue[RELEASE] = 1.0;
    };
private:
    EnvelopeStage currentStage; // STAGE CORRENTE
    float currentLevel; // livello inviluppo corrente
    float multiplier; // decadimento esponenziale
    float sampleRate;
    float stageValue[kNumEnvelopeStages];
    void calculateMultiplier(float startLevel, float endLevel, unsigned long long lengthInSamples);
    unsigned long long currentSampleIndex;
    unsigned long long nextStageSampleIndex;
};

#endif  // ENVELOPE_H_INCLUDED
