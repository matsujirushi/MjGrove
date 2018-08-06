#include "GroveAccelerometer16G.h"
#include "Abstract/GroveModuleError.h"
#include <math.h>

#define I2C_ADDRESS   (0x53)
#define REG_POWER_CTL (0x2d)
#define REG_DATAX0    (0x32)

void GroveAccelerometer16G::Init()
{
	_Device->WriteRegByte(REG_POWER_CTL, 0x08);
}

void GroveAccelerometer16G::Read()
{
	uint8_t readData[6];
	if (_Device->ReadRegBytes(REG_DATAX0, readData, sizeof(readData)) != 6) GROVE_MODULE_ERROR("exception");

	int16_t val;

	((uint8_t*)&val)[0] = readData[0];
	((uint8_t*)&val)[1] = readData[1];
	X = val * 2.0 / 512;

	((uint8_t*)&val)[0] = readData[2];
	((uint8_t*)&val)[1] = readData[3];
	Y = val * 2.0 / 512;

	((uint8_t*)&val)[0] = readData[4];
	((uint8_t*)&val)[1] = readData[5];
	Z = val * 2.0 / 512;
}
