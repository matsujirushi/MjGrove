#include "GroveTempInfrared.h"

void GroveTempInfrared::Init()
{
}

void GroveTempInfrared::Read()
{
	int tempValue = _Pin1->Read();
	float temp = tempValue * 3.3 / _Pin1->MAX_VALUE;
	float R = 2000000 * temp / (2.50 - temp);
}
