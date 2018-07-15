#pragma once

#include <Wire.h>

class GroveI2C
{
private:
	TwoWire* _Wire;

public:
	GroveI2C(TwoWire* wire);

	void Write(uint8_t slaveAddress, const uint8_t* data, int dataSize);
	int Read(uint8_t slaveAddress, uint8_t* data, int dataSize);

};
