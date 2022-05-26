#pragma once
#include <JuceHeader.h>
#include "Oscillator.h"

class Triangle : public Oscillator

{
public:
	/** Triangle constructor */
	Triangle();
	
	/** Triangle destructor */
	virtual ~Triangle() = default;
	
	/** Override the pure virtual function from Oscillator class.
	@param phase Sets phase behaviour to have a Triangle waveform */
	float renderWaveShape(float phase) override;
	
private:
};

