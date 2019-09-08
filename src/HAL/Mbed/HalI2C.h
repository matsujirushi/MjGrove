#pragma once

#include "../HalI2CBase.h"
#include <mbed.h>

class HalI2C : public HalI2CBase
{
private:
	I2C* _I2C;

public:
	HalI2C(I2C* i2c) : _I2C(i2c)
	{
	}

protected:
	virtual void EnableImplement();
	virtual void WriteImplement(int slaveAddress, const uint8_t* data, int dataSize);
	virtual int ReadImplement(int slaveAddress, uint8_t* data, int dataSize);

};
