/*
  ==============================================================================

    Audio.cpp
    Author:  Raul Ortiz

  ==============================================================================
*/

#include "Audio.h"
#include "../ui/MainComponent.h"

Audio::Audio() 
{
    auto midiInputDevices = MidiInput::getAvailableDevices();
    midiInputNames;
    for (auto input : midiInputDevices)
        midiInputNames.add(input.name);

    auto errorMessage = audioDeviceManager.initialiseWithDefaultDevices(1, 2);
    if (!errorMessage.isEmpty())
        DBG(errorMessage);
    audioDeviceManager.addAudioCallback(this);

}

Audio::~Audio()
{
    audioDeviceManager.removeAudioCallback(this);
    audioDeviceManager.removeMidiInputCallback("", this);
}

void Audio::setMidiInput(int index)
{
    auto list = juce::MidiInput::getAvailableDevices();
    audioDeviceManager.removeMidiInputDeviceCallback(list[lastInputIndex].identifier, this);
    auto newInput = list[index];

    if (!audioDeviceManager.isMidiInputDeviceEnabled(newInput.identifier))
        audioDeviceManager.setMidiInputDeviceEnabled(newInput.identifier, true);

    audioDeviceManager.addMidiInputDeviceCallback(newInput.identifier, this);

    lastInputIndex = index;
}

void Audio::handleIncomingMidiMessage(MidiInput* source, const MidiMessage& message)
{
     DBG("Midi event...");
     
    if (message.isNoteOn())
    {
          mySynth.setNote (message.getNoteNumber());                  
          stopGain = 1;
    }
    else 
    {
        stopGain = 0;
    }
}

void Audio::audioDeviceIOCallback(const float** inputChannelData,
    int numInputChannels,
    float** outputChannelData,
    int numOutputChannels,
    int numSamples)
{
    //All audio processing is done here
    const float* inL = inputChannelData[0];

    float* outL = outputChannelData[0];
    float* outR = outputChannelData[1];
  
    while (numSamples--)
    {       
                     
        float sinSignal = mySynth.getOscNextSample(0);
        float sqrSignal = mySynth.getOscNextSample(1);
        float harSignal = mySynth.getOscNextSample(2);
      
        float vibratoSignal = vibrato.getVibratoNextSample();
      
        mySynth.setOscFrequency(mySynth.giveFrequency(0)  + vibratoSignal * 25.f, 0); // +vibratoSignal * 25.f);
        mySynth.setOscFrequency(mySynth.giveFrequency(1) + vibratoSignal * 25.f, 1);
        
        float signal = sinSignal + sqrSignal + harSignal;
        
        tremoloSignal = (tremolo.getLFONextSample() + 1) / 2.f;
        
        signal *= tremoloSignal;
        signal *= stopGain;

        auto output = *inL;
        *outL = signal;
        *outR = signal;

        inL++;
        outL++;
        outR++;
    }
}

void Audio::audioDeviceAboutToStart(AudioIODevice* device)
{   
    
}

void Audio::audioDeviceStopped()
{

}






