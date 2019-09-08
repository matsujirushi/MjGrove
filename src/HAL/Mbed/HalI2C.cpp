#if defined __MBED__

#include "HalI2C.h"

void HalI2C::EnableImplement()
{
}

void HalI2C::WriteImplement(int slaveAddress, const uint8_t* data, int dataSize)
{
	_I2C->write(slaveAddress << 1, (const char*)data, dataSize);
}

int HalI2C::ReadImplement(int slaveAddress, uint8_t* data, int dataSize)
{
	_I2C->read(slaveAddress << 1, (char*)data, dataSize);
	return dataSize;
}

#endif // __MBED__
