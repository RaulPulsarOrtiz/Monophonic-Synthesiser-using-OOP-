#pragma once

class Oscillator
{
public:
	Oscillator();
	~Oscillator();
	/** Sets the oscillator frequency.
		@param newFrequency  specifies the oscilator frequency
		@see setNote()*/
	void setFrequency(float newFrequency);

	/** Sets the oscillator frequency using a midi note number.
		@param noteNumber  MIDI note number (0 - 127)
		@see setFrequency()*/
	void setNote(int noteNumber);

	/** Sets the oscillator gain.
		@param newGain  the new gain value */
	//void setGain(float newGain);

	/** Sets the sample rate.
		@param newSampleRate  new sample rate */
	void setSampleRate(float newSampleRate);

	/** Returns the next sample value
		@return the next oscillator sample */
	float nextSample();
	float getFrequency() { return frequency; }

protected:
	/** Generates the actual waveshape from a given phase value. This should not be called directly it is used internally by nextSample()
		@param phase argument in the range 0 - 2pi
		@return amplitude value for the given phase */
	virtual float renderWaveShape(float phase) = 0;

private:
	/** Updates the internal state for the current sample rate and frequency. */
	void updatePhaseIncrement();

	float frequency{ 440.f };
	float gain{ 1.f };
	float sampleRate{ 44100.f };
	float phase{ 0.f };
	float phaseIncrement{ 0.f };
	float LFOfrequency{ 0.f };
	float vibrato{ 0.f };

};

