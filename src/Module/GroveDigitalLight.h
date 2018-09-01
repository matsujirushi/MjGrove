//GROVE_NAME        "Grove - Digital Light Sensor"
//SKU               101020030
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Digital_Light_Sensor/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorI2C.h"

class GroveDigitalLight : public GroveModule
{
private:
	HalI2CDevice* _Device;

public:
	GroveDigitalLight(GroveConnectorI2C* connector)
	{
		_Device = connector->NewDevice(0x29);	// I2C_ADDRESS
	}

	void Init();
	void Read();

};
