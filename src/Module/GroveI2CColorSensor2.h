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

	void write8(uint8_t reg, uint8_t value);
	uint8_t read8(uint8_t reg);

public:
	GroveI2CColorSensor2(GroveConnectorI2C* connector)
	{
		_Device = connector->NewDevice(0x29);	// I2C_ADDRESS
	}

	void Init();
	void Read();

};
