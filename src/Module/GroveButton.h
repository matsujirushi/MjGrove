//GROVE_NAME        "Grove - Button"
//SKU               101020003
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Button/

#pragma once

#include "Abstract/GroveDigitalInOnOff.h"

class GroveButton : public GroveDigitalInOnOff
{
public:
	GroveButton(GroveConnectorDIO* connector) : GroveDigitalInOnOff(connector)
	{
	}

	GroveButton(HalGpio* pin) : GroveDigitalInOnOff(pin)
	{
	}

};
