//
//  StepSequencer.h
//  iSynth
//
//  Created by Eugenio  on 23/11/15.
//
//

#ifndef StepSequencer_h
#define StepSequencer_h

#include <stdio.h>
#include <math.h>


class StepSequencer
{
    private:
        float omega, phase, bpm;
        float seq[4];
        int step, i;
        float ph2;
    public:
        StepSequencer();
        void setBpm(float newBpm) { bpm=newBpm;  omega = (bpm/60.0)/44100; }
        float play();
        void rec(float f);
        void clearVec() { for(int i=0;i<4;i++) seq[i]=0.0;}
};


#endif /* StepSequencer_h */
