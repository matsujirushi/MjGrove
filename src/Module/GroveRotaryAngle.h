//GROVE_NAME        "Grove - Rotary Angle Sensor"
//SKU               101020017
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Rotary_Angle_Sensor/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorAnalogIn.h"

class GroveRotaryAngle : public GroveModule
{
private:
	GroveAnalogIn * _Pin;

public:
	float Volume;

public:
	GroveRotaryAngle(GroveConnectorAnalogIn* connector)
	{
		_Pin = &connector->P1;
	}

	GroveRotaryAngle(GroveAnalogIn* pin)
	{
		_Pin = pin;
	}

	void Init();
	void Read();

};
