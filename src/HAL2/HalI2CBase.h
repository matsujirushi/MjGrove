#pragma once

#include <stdint.h>

class HalI2CBase
{
public:
	void Write(int slaveAddress, const uint8_t* data, int dataSize)
	{
		WriteImplement(slaveAddress, data, dataSize);
	}

	int Read(int slaveAddress, uint8_t* data, int dataSize)
	{
		return ReadImplement(slaveAddress, data, dataSize);
	}

protected:
	virtual void WriteImplement(int slaveAddress, const uint8_t* data, int dataSize) = 0;
	virtual int ReadImplement(int slaveAddress, uint8_t* data, int dataSize) = 0;

};
