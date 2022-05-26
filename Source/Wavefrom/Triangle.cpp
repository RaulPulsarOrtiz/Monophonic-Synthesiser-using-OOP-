#define _USE_MATH_DEFINES
#include <cmath>
#include "Triangle.h"

Triangle::Triangle()
{

}

float Triangle::renderWaveShape(float currentPhase)
{
	if (currentPhase < M_PI) 
	{
		return -1 + (M_2_PI * currentPhase);
	}
	else
	{
		return 3 - (M_2_PI * currentPhase);
	}
}

//Triangle* Triangle::addVoice(Triangle* newOsc)
//{
//	return newOsc;
//}