#pragma once
#include <JuceHeader.h>
#include "Oscillator.h"

class Sawtooth : public Oscillator
{
public:
	/** Sawtooth constructor */
	Sawtooth();

	/** Sawtooth destructor */
	virtual ~Sawtooth() = default;

	/** Override the pure virtual function from Oscillator class.
	@param phase Sets phase behaviour to have a Sawtooth waveform */
	float renderWaveShape(float phase) override;
private:
};

