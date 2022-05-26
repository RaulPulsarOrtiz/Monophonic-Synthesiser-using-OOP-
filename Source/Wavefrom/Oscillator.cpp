#include "Oscillator.h"
#include <JuceHeader.h>
#include <cmath>


Oscillator::Oscillator()
{
	updatePhaseIncrement();

}

Oscillator::~Oscillator()
{

}

void Oscillator::setFrequency(float newFrequency)
{
	frequency = newFrequency;
	//frequency *= vibrato;
	updatePhaseIncrement();
}

void Oscillator::setNote(int noteNumber)
{
	setFrequency(440.f * pow(2, (noteNumber - 69) / 12.0));
}


void Oscillator::setSampleRate(float newSampleRate)
{
	sampleRate = newSampleRate;
	updatePhaseIncrement();
}

float Oscillator::nextSample()
{
	auto out = renderWaveShape(phase);

	phase += phaseIncrement;
	if (phase > MathConstants<float>::twoPi)
		phase -= MathConstants<float>::twoPi;

	return out;
}


void Oscillator::updatePhaseIncrement()
{
	phaseIncrement = (MathConstants<float>::twoPi * frequency) / sampleRate;
}

