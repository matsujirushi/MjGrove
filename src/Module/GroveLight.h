//GROVE_NAME        "Grove - Light Sensor"
//SKU               101020132
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Light_Sensor/

#pragma once

#include "Abstract/GroveAnalogIn.h"

class GroveLight : public GroveAnalogIn
{
public:
	GroveLight(GroveConnectorAnalogIn* connector) : GroveAnalogIn(connector)
	{
	}

	GroveLight(HalAnalogIn* pin) : GroveAnalogIn(pin)
	{
	}

};
