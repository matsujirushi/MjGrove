//GROVE_NAME        "Grove - Tilt"
//SKU               101020025
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Tilt_Switch/

#pragma once

#include "Abstract/GroveDigitalInOnOff.h"

class GroveTilt : public GroveDigitalInOnOff
{
public:
	GroveTilt(GroveConnectorDIO* connector) : GroveDigitalInOnOff(connector)
	{
	}

	GroveTilt(HalGpio* pin) : GroveDigitalInOnOff(pin)
	{
	}

};
