#pragma once

#include "GroveConnector.h"
#include "../HAL2/Hal.h"

class GroveConnectorI2C : public GroveConnector
{
private:
	HalI2C _I2C;

public:
	GroveConnectorI2C(TwoWire* wire) : _I2C(wire)
	{
	}

	void Enable()	// TODO
	{
	}

	HalI2CDevice* NewDevice(uint8_t slaveAddress)
	{
		return new HalI2CDevice(&_I2C, slaveAddress);
	}

};
