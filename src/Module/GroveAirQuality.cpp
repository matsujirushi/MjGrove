#include "GroveAirQuality.h"

void GroveAirQuality::Init()
{
}

void GroveAirQuality::Read()
{
	float vl = (float)_Pin->Read() * 3.3f / _Pin->MAX_VALUE;
	float rs = (3.3f - vl) / (vl / 10000.0f);

	Resistance = rs;
}
