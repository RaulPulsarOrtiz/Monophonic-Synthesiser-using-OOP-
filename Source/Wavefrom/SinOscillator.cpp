#include "SinOscillator.h"
#include <JuceHeader.h>
#include <cmath>

SinOscillator::SinOscillator()
{

}


float SinOscillator::renderWaveShape(float currentPhase)
{
	return std::sin(currentPhase);
}
