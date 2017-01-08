//
//  Oscillator.cpp
//  subSynth
//
//  Created by Eugenio  on 22/09/15.
//  Copyright (c) 2015 Eugenio . All rights reserved.
//

#include "Oscillator.h"


void Oscillator::setMode(int mode)
{
    oscillatorMode = mode;
}

void Oscillator::setFrequency(float newFrequency)
{
    frequency = newFrequency;
    updateIncrement();
}

void Oscillator::setSampleRate(float sampleRate)
{
    sampleRate = sampleRate;
    updateIncrement();
}

void Oscillator::updateIncrement()
{
    phaseIncrement = frequency * 2 * PI / sampleRate;
}

// richiamata durante la process
float Oscillator::generate()
{
    const float twoPI = 2 * PI;
    switch (oscillatorMode)
    {
        case SINE:
            phase += phaseIncrement;
            while (phase >= twoPI) //mi assicuro che sia tra 0 e 2P, phase = 0 quando raggiunge 2P
                phase -= twoPI;
            return sin(phase);
            break;
        case SAW:
            /* phase/twoPI 0 -> 1 -> 0
               2phase/twoPI 0 -> 2
               per phase=0 -> exp=1
               phase va su, exp va giù e va a 1 quando raggiunge -1*/
            phase += phaseIncrement;
            while (phase >= twoPI)
                phase -= twoPI;
            return(1.0 - (2.0 * phase / twoPI));
            break;
        case SQUARE:
            phase += phaseIncrement;
            while (phase >= twoPI)
                phase -= twoPI;
            if (phase <= PI)
                return 1.0;
            else
                return -1.0;
            break;
        case TRIANGLE:
            phase += phaseIncrement;
            while (phase >= twoPI)
                phase -= twoPI;
            return (-1.0 + (2.0 * phase / twoPI));
            break;
    }
}