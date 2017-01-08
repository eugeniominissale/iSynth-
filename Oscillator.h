//
//  Oscillator.h
//  subSynth
//
//  Created by Eugenio  on 22/09/15.
//  Copyright (c) 2015 Eugenio . All rights reserved.
//

#ifndef __subSynth__Oscillator__
#define __subSynth__Oscillator__

#include <stdio.h>
#include <math.h>

enum OscillatorMode
{
    SINE=1,
    SAW,
    SQUARE,
    TRIANGLE
};

class Oscillator
{
private:
    int oscillatorMode;
    const float PI;
    float frequency;
    float phase;
    float sampleRate;
    float phaseIncrement;
    void updateIncrement();
public:
    void setMode(int mode);
    float getFrequency(){ return frequency; }
    void setFrequency(float newFrequency);
    void setSampleRate(float sampleRate);
    float generate();
    Oscillator() :
    oscillatorMode(SINE),
    PI(2*acos(0.0)),
    frequency(440.0),
    phase(0.0),
    sampleRate(44100.0) { updateIncrement(); };
};

#endif