#pragma once

#include "GroveModule.h"
#include "../../Connector/GroveConnectorDIO.h"

class GroveDigitalOutOnOff : public GroveModule
{
private:
	HalGpio* _Pin;

public:
	GroveDigitalOutOnOff(GroveConnectorDIO* connector)
	{
		_Pin = &connector->P1;
	}

	GroveDigitalOutOnOff(HalGpio* pin)
	{
		_Pin = pin;
	}

	void Init()
	{
		_Pin->Enable(HalGpio::MODE_OUTPUT);
		_Pin->Write(false);
	}

	void On()
	{
		_Pin->Write(true);
	}

	void Off()
	{
		_Pin->Write(false);
	}

	bool IsOn() const
	{
		return _Pin->ReadOutput();
	}

};
