#include "MySynth.h"

MySynth::MySynth()
{
	oscPtr = &oscSin;
	oscPtr2 = &oscSin;
    oscPtrHar = &oscSin;
}

MySynth::~MySynth()
{

}

void MySynth::setNote(int newNote)
{
    frequency = MidiMessage::getMidiNoteInHertz(newNote);
    midiNumber1 = newNote + noteOffset1;
    midiNumber2 = newNote + noteOffset2;
    frequency1 = MidiMessage::getMidiNoteInHertz(midiNumber1);  
    frequency2 = MidiMessage::getMidiNoteInHertz(midiNumber2);  
     
}

void MySynth::getOscType(int index)
{      
    if (index == 1)
        oscPtr = &oscSin;
    else if (index == 2)
        oscPtr = &oscSqr;
    else if (index == 3)
        oscPtr = &oscSaw;
    else if (index == 4)
        oscPtr = &oscTri;
    else if (index == 5)
        oscPtr2 = &oscSin;
    else if (index == 6)
        oscPtr2 = &oscSqr;
    else if (index == 7)
        oscPtr2 = &oscSaw;
    else if (index == 8)
        oscPtr2 = &oscTri;
}

float MySynth::getOscNextSample(int oscNumber)
{
    if (oscNumber == 0) {
        float signal = oscPtr->nextSample();
        return signal * gainOsc1;
    }
    else if (oscNumber == 1) {
        float signal = oscPtr2->nextSample();
        return signal * gainOsc2;
    }
    else if (oscNumber == 2) {
        float harSignal = oscPtrHar->nextSample();
        return harSignal * gainHar;
    }
}

void MySynth::setOscFrequency(float frequency, int oscNumber)
{
    if (oscNumber == 0)
    {
        oscPtr->setFrequency(frequency);
    }
    if (oscNumber == 1)
    {
        oscPtr2->setFrequency(frequency);
    }
}


void MySynth::setGain1(float gain)
{
    gainOsc1 = gain;
}

void MySynth::setGain2(float gain)
{
    gainOsc2 = gain;
}

void MySynth::setGainHar(float gain)
{
    gainHar = gain;
}

void MySynth::setHarmonicInterv(int index)
{
    if (index == 1)
        oscPtrHar->setFrequency(frequency * 5 / 4);
    if (index == 2)
        oscPtrHar->setFrequency(frequency * 6 / 5);
    if (index == 3)
        oscPtrHar->setFrequency(frequency * 3 / 2);
}

void MySynth::setHarmonicOsc(int index)
{
    if (index == 1)
        oscPtrHar = oscPtr;
    if (index == 2)
        oscPtrHar = oscPtr2;
}

void MySynth::setOctave(int index, int octNumber)
{
    if (octNumber == 0) {
        if (index == 1)
            noteOffset1 = 24;
        else if (index == 2)
            noteOffset1 = 12;
        if (index == 3)
            noteOffset1 = 0;
        if (index == 4)
            noteOffset1 = -12;
        if (index == 5)
            noteOffset1 = -24;
    }
   
    else if (octNumber == 1) {
        if (index == 1)
            noteOffset2 = 24;
        if (index == 2)
            noteOffset2 = 12;
        if (index == 3)
            noteOffset2 = 0;
        if (index == 4)
            noteOffset2 = -12;
        if (index == 5)
            noteOffset2 = -24;
    }
}

float MySynth::giveFrequency(int oscNumber)
{
    if (oscNumber == 0)
        return frequency1;
    if (oscNumber == 1)
        return frequency2;
}