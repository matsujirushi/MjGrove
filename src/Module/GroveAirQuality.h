//GROVE_NAME        "Grove - Air quality sensor v1.3"
//SKU               101020078
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Air_Quality_Sensor_v1.3/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorAnalogIn.h"

class GroveAirQuality : public GroveModule
{
private:
	HalAnalogIn* _Pin;

public:
	float Resistance;

public:
	GroveAirQuality(GroveConnectorAnalogIn* connector)
	{
		_Pin = &connector->P1;
	}

	GroveAirQuality(HalAnalogIn* pin)
	{
		_Pin = pin;
	}

	void Init();
	void Read();

};
