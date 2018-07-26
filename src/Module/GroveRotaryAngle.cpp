#include "GroveRotaryAngle.h"

void GroveRotaryAngle::Init()
{
}

void GroveRotaryAngle::Read()
{
	Volume = (float)_Pin->Read() / _Pin->MAX_VALUE;
}
