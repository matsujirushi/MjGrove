//GROVE_NAME        "Grove - Tilt Switch"
//SKU               101020025
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Tilt_Switch/

#pragma once

#include "Abstract/GroveDigitalInOnOff.h"

class GroveTiltSwitch : public GroveDigitalInOnOff
{
public:
	GroveTiltSwitch(GroveConnectorDIO* connector) : GroveDigitalInOnOff(connector)
	{
	}

	GroveTiltSwitch(HalGpio* pin) : GroveDigitalInOnOff(pin)
	{
	}

};
