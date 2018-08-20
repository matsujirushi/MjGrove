//GROVE_NAME        "Grove - Infrared Temperature Sensor"
//SKU               101020062
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Infrared_Temperature_Sensor/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorAnalogIn.h"

class GroveTempInfrared : public GroveModule
{
private:
	HalAnalogIn* _Pin1;
	HalAnalogIn* _Pin2;

public:
	GroveTempInfrared(GroveConnectorAnalogIn* connector)
	{
		_Pin1 = &connector->P1;
		_Pin2 = &connector->P2;
	}

	void Init();
	void Read();

};
