//GROVE_NAME        "Grove - Oxygen Sensor(ME2-O2-„U20)"
//SKU               101020002
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Gas_Sensor-O2/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorAnalogIn.h"

class GroveGasO2 : public GroveModule
{
private:
	HalAnalogIn* _Pin;

public:
	float Concentration;

public:
	GroveGasO2(GroveConnectorAnalogIn* connector)
	{
		_Pin = &connector->P1;
	}

	GroveGasO2(HalAnalogIn* pin)
	{
		_Pin = pin;
	}

	void Init();
	void Read();

};
