#pragma once

#include "GroveConnector.h"
#include "../Interface/GroveI2C.h"
#include "../Interface/GroveI2CDevice.h"

class GroveConnectorI2C : public GroveConnector
{
private:
	GroveI2C _I2C;

public:
	GroveConnectorI2C(TwoWire* wire) : _I2C(wire)
	{
	}

	void Enable()
	{
		_I2C.Enable();
	}

	GroveI2CDevice* NewGroveI2CDevice(uint8_t slaveAddress)
	{
		return new GroveI2CDevice(&_I2C, slaveAddress);
	}

};
