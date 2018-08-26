//GROVE_NAME        "Grove - Buzzer"
//SKU               107020000
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Buzzer/

#pragma once

#include "Abstract/GroveDigitalOutOnOff.h"

class GroveBuzzer : public GroveDigitalOutOnOff
{
private:
	HalGpio* _Pin;

public:
	GroveBuzzer(GroveConnectorDIO* connector) : GroveDigitalOutOnOff(connector)
	{
	}

	GroveBuzzer(HalGpio* pin) : GroveDigitalOutOnOff(pin)
	{
	}

};
