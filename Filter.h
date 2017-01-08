//
//  filter.h
//  iSynth
//
//  Created by Eugenio  on 02/11/15.
//
//

#ifndef filter_h
#define filter_h

#include <cmath>

class Filter
{
    
public:
    enum FilterMode
    {
        LP = 1,
        HP,
        BP,
        kNumFilterModes
    };
    Filter() :
    cutoff(0.99),
    resonance(0.0),
    mode(LP),
    cutoffMod(0.0), //verrà modificata dall'inviluppo (sommata alla fc)
    buf0(0.0),
    buf1(0.0),
    buf2(0.0),
    buf3(0.0)
    {
        calculateFeedbackAmount();
    };
    float process(float inputValue);
    void setCutoff(float newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
    void setResonance(float newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
    void setFilterMode(int nMode) { mode = nMode; }
    /*per l'inviluppo del filtro (richiamata se attivo l'LFO)*/
    void setCutoffMod(float newCutoffMod)
    {
        cutoffMod = newCutoffMod;
        calculateFeedbackAmount();
    }
    float getCutOff(){return cutoff;};
private:
    float cutoff;
    float resonance;
    int mode;
    float feedbackAmount;
    
    /*es: setCutOffMod
     
        feedbackAmount=0.5+0.5/(1-gcc())*/
    
    void calculateFeedbackAmount()
    {
        feedbackAmount = resonance + resonance/(1.0 - getCalculatedCutoff());
    }
    /*ritorna: cutoff+cutoffMod*/
    float getCalculatedCutoff() const
    {
        float calculated = cutoff + cutoffMod;
        if (calculated > 0.99) calculated = 0.99;
        if (calculated < 0.01) calculated = 0.01;
        return calculated;
    };
    
    float buf0, buf1, buf2, buf3, cutoffMod;
};


#endif /* filter_h */
