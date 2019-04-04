#pragma once

#include "GroveModule.h"
#include "../../Connector/GroveConnectorDIO.h"

class GroveDigitalInOnOff : public GroveModule
{
private:
	HalGpio* _Pin;

public:
	GroveDigitalInOnOff(GroveConnectorDIO* connector)
	{
		_Pin = &connector->P1;
	}

	GroveDigitalInOnOff(HalGpio* pin)
	{
		_Pin = pin;
	}

	void Init()
	{
		_Pin->Enable(HalGpio::MODE_INPUT);
	}

	bool IsOn() const
	{
		return _Pin->Read();
	}

};
