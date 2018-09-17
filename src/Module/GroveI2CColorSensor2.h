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
	uint16_t read16(uint8_t reg);

	void enable();
	void getRawData(uint16_t* r, uint16_t* g, uint16_t* b, uint16_t* c);

public:
	uint16_t R;
	uint16_t G;
	uint16_t B;
	uint16_t C;

public:
	GroveI2CColorSensor2(GroveConnectorI2C* connector)
	{
		_Device = connector->NewDevice(0x29);	// I2C_ADDRESS
	}

	void Init();
	void SetIntegrationTime(float time);
private:
	void SetGain(int gain);
public:
	void Read();

};
