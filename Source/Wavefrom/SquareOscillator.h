#pragma once
#include "Oscillator.h"

class SquareOscillator : public Oscillator
{
public:
	/** SquareOscillator constructor */
	SquareOscillator();

	/** SquareOscillator destructor */
	~SquareOscillator();
	
	/** Override the pure virtual function from Oscillator class.
	@param phase Sets phase behaviour to have a Square waveform */
	float renderWaveShape(float phase) override;
private:
};

