//GROVE_NAME        "Grove - Temperature&Humidity Sensor (SHT31)"
//SKU               101020212
//WIKI_URL          http://wiki.seeedstudio.com/Grove-TempAndHumi_Sensor-SHT31/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorI2C.h"

class GroveTempHumiSHT31 : public GroveModule
{
private:
	GroveI2CDevice * _Device;

	void SendCommand(uint16_t cmd);
	static uint8_t CalcCRC8(const uint8_t* data, int dataSize);

public:
	float Temperature;
	float Humidity;

public:
	GroveTempHumiSHT31(GroveConnectorI2C* connector)
	{
		_Device = connector->NewGroveI2CDevice(0x44);	// I2C_ADDRESS
	}

	void Init();
	void Read();

};
