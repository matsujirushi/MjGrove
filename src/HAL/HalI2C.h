#pragma once

#include <Wire.h>

class HalI2C
{
private:
	TwoWire* _Wire;

public:
	HalI2C(TwoWire* wire) : _Wire(wire)
	{
	}

	void Enable();

	void Write(uint8_t slaveAddress, const uint8_t* data, int dataSize);
	int Read(uint8_t slaveAddress, uint8_t* data, int dataSize);

};
