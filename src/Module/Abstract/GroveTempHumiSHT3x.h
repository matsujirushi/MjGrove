#pragma once

#include "GroveModule.h"
#include "../../Connector/GroveConnectorI2C.h"

class GroveTempHumiSHT3x : public GroveModule
{
protected:
	HalI2CDevice* _Device;

	void SendCommand(uint16_t cmd);
	static uint8_t CalcCRC8(const uint8_t* data, int dataSize);

public:
	float Temperature;
	float Humidity;

protected:
	GroveTempHumiSHT3x(GroveConnectorI2C* connector, uint8_t slaveAddress)
	{
		_Device = connector->NewDevice(slaveAddress);	// I2C_ADDRESS
	}

public:
	void Init();
	void Read();
	void SetHeater(bool on);

};
