//GROVE_NAME        "Grove - High Temperature Sensor"
//SKU               111020002
//WIKI_URL          http://wiki.seeedstudio.com/Grove-High_Temperature_Sensor/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorAnalogIn.h"

class GroveHighTemp : public GroveModule
{
private:
	HalAnalogIn* _Pin1;
	HalAnalogIn* _Pin2;

	float ReadReferenceJunctionTemperature() const;
	float ReadThermocoupleTemperature() const;

public:
	float Temperature;

public:
	GroveHighTemp(GroveConnectorAnalogIn* connector)
	{
		_Pin1 = &connector->P1;
		_Pin2 = &connector->P2;
	}

	void Init();
	void Read();

};
