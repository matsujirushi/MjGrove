//GROVE_NAME        "Grove - Buzzer"
//SKU               107020000
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Buzzer/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorDIO.h"

class GroveBuzzer : public GroveModule
{
private:
	GroveGpio* _Pin;

public:
	GroveBuzzer(GroveConnectorDIO* connector)
	{
		_Pin = &connector->P1;
	}

	GroveBuzzer(GroveGpio* pin)
	{
		_Pin = pin;
	}

	void Init()
	{
		_Pin->SetMode(GroveGpio::MODE_OUTPUT);
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
