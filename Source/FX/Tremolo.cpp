#include "Tremolo.h"

Tremolo::Tremolo()
{
    oscLFOPtr = &LFOtremolo; 
}

Tremolo::~Tremolo()
{

}

void Tremolo::setTremoloFreq(float freq)
{
    oscLFOPtr->setFrequency(freq);
}

void Tremolo::setTremoloDepth(float depth)
{
    tDepth = depth;
}

float Tremolo::getLFONextSample()
{
    float tremoloSignal = oscLFOPtr->nextSample();
    return tremoloSignal * tDepth;
}
