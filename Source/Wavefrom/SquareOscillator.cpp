#define _USE_MATH_DEFINES
#include <cmath>
#include "SquareOscillator.h"


SquareOscillator::SquareOscillator()
{

}

SquareOscillator::~SquareOscillator()
{

}

float SquareOscillator::renderWaveShape(float currentPhase)
{
	if (currentPhase < M_PI)
	{
		currentPhase = 1;

	}
	else 
	{
		currentPhase = -1;
	}
	return currentPhase;

}
