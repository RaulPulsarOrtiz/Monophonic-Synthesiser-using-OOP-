#define _USE_MATH_DEFINES
#include <cmath>
#include "Sawtooth.h"

Sawtooth::Sawtooth()
{

}

float Sawtooth::renderWaveShape(float currentPhase)
{
	return 1 - (M_1_PI * currentPhase);
}