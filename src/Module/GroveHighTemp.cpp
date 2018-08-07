#include "GroveHighTemp.h"
#include <math.h>

void GroveHighTemp::Init()
{
}

void GroveHighTemp::Read()
{
	Temperature = ReadReferenceJunctionTemperature();
}

float GroveHighTemp::ReadReferenceJunctionTemperature() const
{
	int v = _Pin2->Read();

	float resistance = (float)(_Pin2->MAX_VALUE - v) * 10000 / v;
	float temperature = 1 / (log(resistance / 10000) / 3975 + 1 / 298.15) - 273.15;	// TTC3A103*39H

	return temperature;
}
