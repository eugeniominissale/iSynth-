//
//  StepSequencer.c
//  iSynth
//
//  Created by Eugenio  on 23/11/15.
//
//

#include "StepSequencer.h"

StepSequencer::StepSequencer()
{
    seq[0]=130.81;
    seq[1]=164.81;
    seq[2]=196.00;
    seq[3]=261.3;
    bpm=60;
    phase=0;
    omega = (bpm/60.0)/44100;
    i=0;
}

float StepSequencer::play()
{
        phase -= floor(phase);
        ph2 = phase*4.0;
        step = static_cast<int>(floor(ph2));
        phase += omega;
        if(step==0)
            return seq[0];
        if(step==1)
            return seq[1];
        if(step==2)
            return seq[2];
        if(step==3)
            return seq[3];
}

void StepSequencer::rec(float f)
{
    if (i!=0 && i>=4)
        i=0;
    seq[i]=f;
    i++;
}