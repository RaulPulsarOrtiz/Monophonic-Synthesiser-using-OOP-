#pragma once

#include <JuceHeader.h>
#include "../Wavefrom/SinOscillator.h"

class Vibrato : public Component		
{
public:
	/** Vibrato constructor. Oscillator pointer point to a sinewave */
	Vibrato();
	
	/** Vibrato destructor */
	~Vibrato();
	
	/** Set frequency for vibrato. 
	@param freq Given by vibratoFreqSldr slider 
	@see Oscillator::setFrequency */
	void setVibratoFreq(float);

	void setVibratoDepth(float);
	
	/** Gets Oscillator pointer nextSample() to get that value and be use in Audio class. 
	@return vibrato signal multiply by vibratoDepth
	@see setVibratoDepth() */
	float getVibratoNextSample();

private:
	/** Pointer of Oscillator class
	@see Vibrato() */
	Oscillator* vibratoOscPtr = nullptr;

	/** sine wave waveform */
	SinOscillator LFOvibrato;
	
	/** Values os each oscillator to be updated */
	float vibratoFreq = 0.f;
	float vDepth = 0.f;
		
};

