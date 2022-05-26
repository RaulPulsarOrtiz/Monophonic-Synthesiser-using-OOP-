#pragma once

#include <JuceHeader.h>
#include "Oscillator.h"

 /** Class for a sinewave oscillator with gain controls. Call nextSample() repetedly to stream audio samples from the oscilator. */

class SinOscillator : public Oscillator
{
public:
	/** SinOscillator constructor */
	SinOscillator();

	/** SinOscillator destructor */
	virtual ~SinOscillator() = default;

	/** Override the pure virtual function from Oscillator class.
    @param phase Sets phase behaviour to have a Sine waveform */
	float renderWaveShape(float phase) override;
private:
};

