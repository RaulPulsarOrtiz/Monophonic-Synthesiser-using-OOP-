#include "Vibrato.h"

Vibrato::Vibrato()
{
    vibratoOscPtr = &LFOvibrato;
}

Vibrato::~Vibrato()
{

}

void Vibrato::setVibratoFreq(float freq)
{
    LFOvibrato.setFrequency(freq);
}

void Vibrato::setVibratoDepth(float depth)
{
    vDepth = depth;
}

float Vibrato::getVibratoNextSample()
{
    float vibratoSignal = vibratoOscPtr->nextSample();
    return vibratoSignal * vDepth;
}
