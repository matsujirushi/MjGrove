//GROVE_NAME        "Grove - Touch Sensor"
//SKU               101020037
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Touch_Sensor/

#pragma once

#include "Abstract/GroveDigitalInOnOff.h"

class GroveTouch : public GroveDigitalInOnOff
{
public:
	GroveTouch(GroveConnectorDIO* connector) : GroveDigitalInOnOff(connector)
	{
	}

	GroveTouch(HalGpio* pin) : GroveDigitalInOnOff(pin)
	{
	}

};
