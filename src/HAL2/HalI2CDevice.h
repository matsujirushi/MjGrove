#pragma once

#include "HalI2CBase.h"

class HalI2CDevice
{
private:
	HalI2CBase* _I2C;
	int _SlaveAddress;

public:
	HalI2CDevice(HalI2CBase* i2c, int slaveAddress) : _I2C(i2c), _SlaveAddress(slaveAddress)
	{
	}

	void Write(const uint8_t* data, int dataSize)
	{
		_I2C->Write(_SlaveAddress, data, dataSize);
	}

	int Read(uint8_t* data, int dataSize)
	{
		return _I2C->Read(_SlaveAddress, data, dataSize);
	}

	void WriteRegByte(uint8_t reg, uint8_t data);
	void WriteRegBytes(uint8_t reg, const uint8_t* data, int dataSize);

	int ReadRegByte(uint8_t reg, uint8_t* data);
	int ReadRegBytes(uint8_t reg, uint8_t* data, int dataSize);

};
