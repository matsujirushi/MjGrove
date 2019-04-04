#pragma once

#include "../../HalI2CBase.h"
#include <Wire.h>

class HalI2C : public HalI2CBase
{
private:
	TwoWire* _Wire;

public:
	HalI2C(TwoWire* wire) : _Wire(wire)
	{
	}

protected:
	virtual void WriteImplement(int slaveAddress, const uint8_t* data, int dataSize);
	virtual int ReadImplement(int slaveAddress, uint8_t* data, int dataSize);

};
