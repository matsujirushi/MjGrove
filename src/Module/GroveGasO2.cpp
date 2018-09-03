#include "GroveGasO2.h"

void GroveGasO2::Init()
{
}

void GroveGasO2::Read()
{
	float volt = (float)_Pin->Read() * 3.3f / _Pin->MAX_VALUE;
	Concentration = volt * 0.21f / 2.0f;
}
