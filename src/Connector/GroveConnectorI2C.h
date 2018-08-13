#pragma once

#include "GroveConnector.h"
#include "../HAL/HalI2C.h"
#include "../HAL/HalI2CDevice.h"

class GroveConnectorI2C : public GroveConnector
{
private:
	HalI2C _I2C;

public:
	GroveConnectorI2C(TwoWire* wire) : _I2C(wire)
	{
	}

	void Enable()
	{
		_I2C.Enable();
	}

	HalI2CDevice* NewDevice(uint8_t slaveAddress)
	{
		return new HalI2CDevice(&_I2C, slaveAddress);
	}

};
