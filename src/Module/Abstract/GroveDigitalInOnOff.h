#pragma once

#include "GroveModule.h"
#include "../../Connector/GroveConnectorDIO.h"

class GroveDigitalInOnOff : public GroveModule
{
private:
	GroveGpio* _Pin;

public:
	GroveDigitalInOnOff(GroveConnectorDIO* connector)
	{
		_Pin = &connector->P1;
	}

	GroveDigitalInOnOff(GroveGpio* pin)
	{
		_Pin = pin;
	}

	void Init()
	{
		_Pin->SetMode(GroveGpio::MODE_INPUT);
	}

	bool IsOn() const
	{
		return _Pin->Read();
	}

};
