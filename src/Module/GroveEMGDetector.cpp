#include "GroveEMGDetector.h"

void GroveEMGDetector::Init()
{
}

void GroveEMGDetector::Read()
{
	Level = _Pin->Read();
}
