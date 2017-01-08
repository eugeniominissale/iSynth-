/*
 *  iSynth.cp
 *  iSynth
 *
 *  Created by Eugenio  on 22/09/15.
 *  Copyright (c) 2015 Eugenio . All rights reserved.
 *
 */

#include "iSynth.h"
#include "Oscillator.h"

iSynth::iSynth()
{
    byPass=byPass1=byPass2=byPass3=byPass4=0;
    oscLOut=oscROut=osc1LOut=osc1ROut=osc2LOut=osc2ROut=0.0;
    
    fil.setFilterMode(1);
    
    lfo.setMode(TRIANGLE);
    lfo.setFrequency(6.0);
    lfoFilterModAmount=0.1;
    lfo.setSampleRate(44100.0);
    
    lfoMode2=1;
    flagSeq=false;
}
    
iSynth::~iSynth() { }

void iSynth::myProcess(float* inputLeft, float* inputRight, int noteNumber)
{
    if(byPass)
    {
        oscLOut=osc.generate();
        oscROut=osc.generate();
    }
    else
        oscLOut=oscROut=0;
    if(byPass1)
    {
        osc1LOut=osc1.generate();
        osc1ROut=osc1.generate();
    }
    else
        osc1LOut=osc1ROut=0;
    if(byPass3)
    {
        float lfoFilterModulation = lfo.generate() * lfoFilterModAmount; // tra 1 e -1,lfoFilterModAmount all'inizio è 1
        float fm;
        /*l'LFO modula il filtro */
        if(lfoMode2==1)
        {
            modCutOff = fil.getCutOff() + lfoFilterModulation;
            if(modCutOff < 0.01 ) modCutOff = 0.01;
            if(modCutOff > 0.99 ) modCutOff = 0.99;
            /*la fc del filtro viene modulata dall'inviluppo del filtro e dal LFO*/
            fil.setCutoffMod(modCutOff); // sommo inviluppo del filtro e modLFO
        }
        /*l'LFO modula il pitch  c*/
        if(lfoMode2==2)
        {
            //fm=osc1.getFrequency()* 2 *(lfoFilterModulation);
            fm=osc1.getFrequency()*(1+lfoFilterModulation);
            oscFM.setFrequency(fm);
            osc1LOut=oscFM.generate();
            osc1ROut=oscFM.generate();
        }
    }
    
    if (env.getCurrentStage() == Envelope::OFF)
       env.enterStage(Envelope::ATTACK);
    if (env.getCurrentStage() == Envelope::SUSTAIN)
        env.enterStage(Envelope::RELEASE);
    if(byPass2)
    {
        oscLOut=fil.process(oscLOut);
        oscROut=fil.process(oscROut);
        osc1LOut=fil.process(osc1LOut);
        osc1ROut=fil.process(osc1ROut);
    }
    if(byPass4)
    {
        *inputLeft=(oscLOut+osc1LOut) * env.nextSample() ;
        *inputRight=(oscROut+osc1ROut) * env.nextSample() ;
    }
    if(!byPass4)
    {
        *inputLeft=(oscLOut+osc1LOut+osc2LOut);
        *inputRight=(oscROut+osc1ROut+osc2ROut);
    }
    if (seqMode==2)
    {
        seq.setBpm(seqBPM);
        osc2.setFrequency(seq.play());
        osc2LOut=osc2.generate();
        osc2ROut=osc2.generate();
        *inputLeft=(oscLOut+osc1LOut+osc2LOut);
        *inputRight=(oscROut+osc1ROut+osc2ROut);
    }
}

/*-----------------------------------------------------------------*/

float iSynth::getFrequency() { return(osc.getFrequency()); }
void iSynth::setFrequency(float value) { osc.setFrequency(value); }
int iSynth::getBypass() { return byPass; }
void iSynth::setBypass(int bP) { byPass=bP; }
int iSynth::getSynthMode() { return synthMode; }
void iSynth::setSynthMode(int m)
{
    synthMode=m;
    osc.setMode(m);
}

/*-----------------------------------------------------------------*/

float iSynth::getFrequency1() { return(osc1.getFrequency()); }
void iSynth::setFrequency1(float value) { osc1.setFrequency(value); }
int iSynth::getBypass1() { return byPass1; }
void iSynth::setBypass1(int bP) { byPass1=bP; }
int iSynth::getSynthMode1() { return synthMode1; }
void iSynth::setSynthMode1(int m)
{
    synthMode1=m;
    osc1.setMode(m);
}

/*-----------------------------------------------------------------*/

void iSynth::setEnvA(float value) { env.setStageValue(1,value); }
void iSynth::setEnvD(float value) { env.setStageValue(2,value); }
void iSynth::setEnvS(float value) { env.setStageValue(3,value); }
void iSynth::setEnvR(float value) { env.setStageValue(4,value); }
float iSynth::getEnvA() { return env.getStageValue(1); }
float iSynth::getEnvD() { return env.getStageValue(2); }
float iSynth::getEnvS() { return env.getStageValue(3); }
float iSynth::getEnvR() { return env.getStageValue(4); }
int iSynth::getBypass4() { return byPass4; }
void iSynth::setBypass4(int bP) { byPass4=bP; }

/*-----------------------------------------------------------------*/

void iSynth::setCof(float value) { fil.setCutoff(value); }
void iSynth::setRes(float value) { fil.setResonance(value); }
void iSynth::setBypass2(int value) { byPass2=value; }
void iSynth::setFilMode(int value) { fil.setFilterMode(value); }
int iSynth::getBypass2() { return byPass2; }

/*-----------------------------------------------------------------*/

void iSynth::setBypass3(int value) { byPass3=value; }
int iSynth::getBypass3() { return byPass3; }
float iSynth::getFrequencyLFO() { return(lfo.getFrequency()); }
void iSynth::setFrequencyLFO(float value) { lfo.setFrequency(value); }
float iSynth::getFrequencyMod() { return(lfoFilterModAmount); }
void iSynth::setFrequencyMod(float value) { lfoFilterModAmount=value; }
int iSynth::getLFOMode() { return lfoMode; }
void iSynth::setLFOMode(int m)
{
    lfoMode=m;
    lfo.setMode(m);
}
int iSynth::getLFOMode2() { return lfoMode2; }
void iSynth::setLFOMode2(int m)
{
    lfoMode2=m;
}

/*-----------------------------------------------------------------*/

void iSynth::setSeqMode(int value){ seqMode=value; }
int iSynth::getSeqMode(){ return seqMode; }
void iSynth::setBPM(float value){ seqBPM=value; }
float iSynth::getBPM(){ return seqBPM; }
void iSynth::rec(float f){ seq.rec(f); }




