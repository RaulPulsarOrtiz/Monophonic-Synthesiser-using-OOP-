#pragma once
#include <JuceHeader.h>
#include "../Wavefrom/SinOscillator.h"

class Tremolo : public Component
				
{
public:
	/** Tremolo constructor. Oscillator pointer point to a sinewave */
	Tremolo();
	
	/** Tremolo destructor */
	~Tremolo();

	/** Set frequency for tremolo.
	@param freq Given by tremoloFreqSldr slider
	@see Oscillator::setFrequency */
	void setTremoloFreq(float);
	
	/** Sets depth of tremolo modulation.
	@param depth Given by tremoloDepthSldr slider*/
	void setTremoloDepth(float);
	
	/** Gets Oscillator pointer nextSample() to get that value and be use in Audio class.
	@return tremolo signal multiply by tremoloDepth
	@see setTemoloDepth() */
	float getLFONextSample();
		
private:
	/** Pointer of Oscillator class
	@see Tremolo()*/
	Oscillator* oscLFOPtr = nullptr;
	
	/** sine wave waveform */
	SinOscillator LFOtremolo;
	
	/** Values os each oscillator to be updated */
	float tDepth = 0.f;
	
};

