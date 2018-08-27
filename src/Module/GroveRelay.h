//GROVE_NAME        "Grove - Relay"
//SKU               103020005
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Relay/

#pragma once

#include "Abstract/GroveDigitalOutOnOff.h"

class GroveRelay : public GroveDigitalOutOnOff
{
private:
	HalGpio* _Pin;

public:
	GroveRelay(GroveConnectorDIO* connector) : GroveDigitalOutOnOff(connector)
	{
	}

	GroveRelay(HalGpio* pin) : GroveDigitalOutOnOff(pin)
	{
	}

};
