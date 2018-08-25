#include "GroveEMGDetector.h"

void GroveEMGDetector::Init()
{
}

void GroveEMGDetector::Read()
{
	Level = (float)_Pin->Read() / _Pin->MAX_VALUE;
}
