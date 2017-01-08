/*
 *  iSynth.h
 *  iSynth
 *
 *  Created by Eugenio  on 22/09/15.
 *  Copyright (c) 2015 Eugenio . All rights reserved.
 *
 */

#ifndef __iSynth__
#define __iSynth__

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextra-tokens"
#pragma clang diagnostic pop


#include "Oscillator.h"
#include "Envelope.h"
#include "Filter.h"
#include "StepSequencer.h"


class iSynth
{
public:
    iSynth();
    ~iSynth();
    void myProcess(float* inputLeft, float* inputRight, int noteNumber);
    //oscillatore1
    void setFrequency(float value);
    float getFrequency();
    void setBypass(int bP);
    int getBypass();
    int getSynthMode();
    void setSynthMode(int m);
    //oscillatore2
    void setFrequency1(float value);
    float getFrequency1();
    void setBypass1(int bP);
    int getBypass1();
    int getSynthMode1();
    void setSynthMode1(int m);
    //inviluppo
    void setEnvA(float value);
    void setEnvD(float value);
    void setEnvS(float value);
    void setEnvR(float value);
    float getEnvA();
    float getEnvD();
    float getEnvS();
    float getEnvR();
    void setBypass3(int value);
    int getBypass3();
    void setBypass4(int value);
    int getBypass4();
    //filtro
    void setCof(float value);
    void setRes(float value);
    void setBypass2(int value);
    void setFilMode(int value);
    int getBypass2();
    //lfo
    float getFrequencyLFO();
    void setFrequencyLFO(float value);
    float getFrequencyMod();
    void setFrequencyMod(float value);
    int getLFOMode();
    void setLFOMode(int m);
    int getLFOMode2();
    void setLFOMode2(int m);
    //seq
    int getSeqMode();
    void setSeqMode(int value);
    float getBPM();
    void setBPM(float value);
    void rec(float f);
    
private:
    Oscillator osc, osc1, osc2, oscFM;
    float oscLOut, oscROut, osc1LOut, osc1ROut, osc2LOut, osc2ROut;
    Envelope env;
    Filter fil;
    Oscillator lfo;
    StepSequencer seq;
    float lfoFilterModAmount, lfoFilterModulation, modCutOff;
    int byPass, byPass1, byPass2, byPass3, byPass4;
    int synthMode, synthMode1, lfoMode, lfoMode2, seqMode;
    float seqBPM;
    bool flagSeq;
};

#endif