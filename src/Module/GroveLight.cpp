#include "GroveLight.h"

void GroveLight::Init()
{
}

void GroveLight::Read()
{
	Value = _Pin->Read();
}
