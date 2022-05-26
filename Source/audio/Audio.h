/*
  ==============================================================================

    Audio.h
    Author:  Raul Ortiz

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <atomic>
#include "MySynth.h"
#include "../FX/Tremolo.h"
#include <atomic>


/** Class containing all audio processes */

class Audio : public MidiInputCallback,
              public AudioIODeviceCallback
                     
{
public:
    /** Constructor */
    Audio();

    /** Destructor */
    ~Audio();

    void setMidiInput(int);

    /** Returns the audio device manager, don't keep a copy of it! */
    AudioDeviceManager& getAudioDeviceManager() { return audioDeviceManager; }

    void handleIncomingMidiMessage(MidiInput* source, const MidiMessage& message) override;

    void audioDeviceIOCallback(const float** inputChannelData,
        int numInputChannels,
        float** outputChannelData,
        int numOutputChannels,
        int numSamples) override;
    void audioDeviceAboutToStart(AudioIODevice* device) override;
    void audioDeviceStopped() override;
    
    /** @return MySynth */
    MySynth* getSynth() {return &mySynth; }
    
    /** @return Vibrato */
    Vibrato* getVibrato() { return &vibrato; }
    
    /** @return Tremolo */
    Tremolo* getTremolo() { return &tremolo; }
 
  juce::StringArray midiInputNames;
private:
   AudioDeviceManager audioDeviceManager;
   int lastInputIndex = 0;
   /** Child objects */
    MySynth mySynth;
    Tremolo tremolo;
    Vibrato vibrato;

    float stopGain = 0;
    float tremoloSignal = 0;
    float vibratoSignal = 0;
    float frequency = 0;

};
