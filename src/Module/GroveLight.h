//GROVE_NAME        "Grove - Light Sensor v1.2"
//SKU               101020132
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Light_Sensor/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorAnalogIn.h"

class GroveLight : public GroveModule
{
private:
	HalAnalogIn* _Pin;

public:
	float Value;

public:
	GroveLight(GroveConnectorAnalogIn* connector)
	{
		_Pin = &connector->P1;
	}

	GroveLight(HalAnalogIn* pin)
	{
		_Pin = pin;
	}

	void Init();
	void Read();

};
