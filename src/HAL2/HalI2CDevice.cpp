#include "HalI2CDevice.h"
#include <string.h>

void HalI2CDevice::WriteReg8(uint8_t reg, uint8_t data)
{
	uint8_t writeData[2];
	writeData[0] = reg;
	writeData[1] = data;

	_I2C->Write(_SlaveAddress, writeData, sizeof(writeData));
}

void HalI2CDevice::WriteRegN(uint8_t reg, const uint8_t* data, int dataSize)
{
	uint8_t writeData[1 + dataSize];
	writeData[0] = reg;
	memcpy(&writeData[1], data, dataSize);

	_I2C->Write(_SlaveAddress, writeData, sizeof(writeData));
}

int HalI2CDevice::ReadReg8(uint8_t reg, uint8_t* data)
{
	_I2C->Write(_SlaveAddress, &reg, 1);

	return _I2C->Read(_SlaveAddress, data, 1);
}

int HalI2CDevice::ReadRegN(uint8_t reg, uint8_t* data, int dataSize)
{
	_I2C->Write(_SlaveAddress, &reg, 1);

	return _I2C->Read(_SlaveAddress, data, dataSize);
}
