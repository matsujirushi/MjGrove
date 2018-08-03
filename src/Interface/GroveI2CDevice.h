#pragma once

#include "GroveI2C.h"

class GroveI2CDevice
{
private:
	GroveI2C* _I2C;
	uint8_t _SlaveAddress;

public:
	GroveI2CDevice(GroveI2C* i2c, uint8_t slaveAddress) : _I2C(i2c), _SlaveAddress(slaveAddress)
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
