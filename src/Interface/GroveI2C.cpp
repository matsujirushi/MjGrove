#include "GroveI2C.h"

GroveI2C::GroveI2C(TwoWire* wire) : _Wire(wire)
{
}

void GroveI2C::Write(uint8_t slaveAddress, const uint8_t* data, int dataSize)
{
	_Wire->beginTransmission(slaveAddress);
	while (dataSize--)
	{
		_Wire->write(*data++);
	}
	_Wire->endTransmission();
}

int GroveI2C::Read(uint8_t slaveAddress, uint8_t* data, int dataSize)
{
	uint8_t readSize = _Wire->requestFrom(slaveAddress, dataSize);
	dataSize = readSize;
	while (dataSize--)
	{
		*data++ = _Wire->read();
	}

	return readSize;
}
