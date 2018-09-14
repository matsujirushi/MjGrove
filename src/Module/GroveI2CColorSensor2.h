//GROVE_NAME        "Grove - I2C Color Sensor V2"
//SKU               101020341
//WIKI_URL          https://www.seeedstudio.com/Grove-I2C-Color-Sensor-V2-p-2890.html

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorI2C.h"

class GroveI2CColorSensor2 : public GroveModule
{
private:
	HalI2CDevice* _Device;

public:
	GroveI2CColorSensor2(GroveConnectorI2C* connector)
	{
		_Device = connector->NewDevice(0x29);	// I2C_ADDRESS
	}

	void Init();
	void Read();

};
