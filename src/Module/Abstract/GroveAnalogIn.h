#pragma once

#include "GroveModule.h"
#include "../../Connector/GroveConnectorAnalogIn.h"

class GroveAnalogIn : public GroveModule
{
private:
	HalAnalogIn* _Pin;

public:
	GroveAnalogIn(GroveConnectorAnalogIn* connector)
	{
		_Pin = &connector->P1;
	}

	GroveAnalogIn(HalAnalogIn* pin)
	{
		_Pin = pin;
	}

	void Init()
	{
	}

	int Value()
	{
		return (int)(_Pin->Read()*100);
	}

};
