#pragma once
#include <JuceHeader.h>
#include <atomic>
#include "../Wavefrom/SinOscillator.h"
#include "../Wavefrom/SquareOscillator.h"
#include "../Wavefrom/Sawtooth.h"
#include "../Wavefrom/Triangle.h"
#include <atomic>
#include "../Wavefrom/Oscillator.h"
#include "../FX/Vibrato.h"

class MySynth  
             
{
public:
    /** MySynth constructor. Each pointer of the oscillator class is addressed to a waveform type */
    MySynth();
  
    /** MySynth destructor */
    ~MySynth();
  
    /** Transform MIDI note to a frequency and add the offset selected in oscOct comboBox.
    @param newNote Note given by a MidiKeyboard
    @see setOscFrequency()
    @see setOctave()*/
    void setNote (int newNote); 
  
    /** Choose a waveform type for Osc1 and Osc2.
    @param index based in oscMenu comboBox */
    void getOscType(int index);
   
    /** Gets Oscillator pointer nextSample() to get that value and be use in Audio class.
    @param oscNumber Sets if the waveform is used in Oscillator1, Oscillator2, or Oscillator Harmonic
    @return nextSample multiply by the respective gain value for the respective oscillator */
    float getOscNextSample(int);
      
    /** Sets Oscillator pointer frequency
    @parameter Frequency given by setNote()
    @parameter oscNumber Oscillator1 is value 0. Oscillator 2 is value1.
    @see setNote() 
    @see Oscillator::setFrequency() */
    void setOscFrequency(float, int);
       
    /** Sets Oscillator gain
    @param gain Gain value given by a Slider */
    void setGain1(float);
    void setGain2(float);
    void setGainHar(float);
        
    /** Sets frequency for harmonic interval
    @param index Giving by harmonicsMenu comboBox. Choose between a 3º Major, 3º minor or perfect 5th
    @see Oscillator::setFrequency() */
    void setHarmonicInterv(int index);

    /** Set the Harmonic oscillator (3º oscillator) to have the waveform to the oscillator1 or the oscillator2
    @param index based on harmonicOscMenu comboBox*/
    void setHarmonicOsc(int);
      
    /** Set a offset for newNote. Oscillator pitch being one or two octaves higer or lower
    @param index based on octOsc comboBox
    @param oscNumber ESCRIBIRRRRRRRR
    @See setNote() */
    void setOctave(int, int);
      
    /** @return frequency to be added to vibratoSignal used in Audio class  */
    float giveFrequency(int);
       
private:

    /** Pointers of Oscillator class */
    Oscillator* oscPtr = nullptr;
    Oscillator* oscPtr2 = nullptr;
    Oscillator* oscPtrHar = nullptr;
    
    /** Object of waveform classes */
    SinOscillator oscSin;
    SquareOscillator oscSqr;
    Sawtooth oscSaw;
    Triangle oscTri;
    Vibrato vibrato;

    /** Values os each oscillator to be updated */
    float frequency = 0.f;
    float frequency1 = 0.f;
    float frequency2 = 0.f;
    float gainOsc1 = 0;
    float gainOsc2 = 0;
    float gainHar = 0;
    int noteOffset1 = 0;
    int noteOffset2 = 0;
    int midiNumber1 = 0;
    int midiNumber2 = 0;
};

