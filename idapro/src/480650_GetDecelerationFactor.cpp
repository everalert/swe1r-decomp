#include "480650_GetDecelerationFactor.hpp"

float __cdecl GetDecelerationFactor(float decelerationInterval, float frameTime)
{
	// time constant 33.333336f = 0x42055556
	// other constant = 0x3F800000
	return 1.0f - frameTime * 33.333336f / (frameTime * 33.333336f + decelerationInterval);
}