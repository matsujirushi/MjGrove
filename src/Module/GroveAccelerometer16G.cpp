#include "GroveAccelerometer16G.h"
#include <math.h>

#define I2C_ADDRESS   (0x53)
#define REG_POWER_CTL (0x2d)
#define REG_DATAX0    (0x32)

void GroveAccelerometer16G::Init()
{
	uint8_t writeData[2];
	writeData[0] = REG_POWER_CTL;
	writeData[1] = 0x08;
	_Device->Write(writeData, sizeof(writeData));
}

void GroveAccelerometer16G::Read()
{
	uint8_t writeData[1];
	writeData[0] = REG_DATAX0;
	_Device->Write(writeData, sizeof(writeData));

	uint8_t readData[6];
	if (_Device->Read(readData, sizeof(readData)) != 6)
	{
#if defined ARDUINO_STM32F4_WIO_GPS
		return;

#elif defined ARDUINO_WIO_3G
		throw "exception";
#else
#error "This board is not supported."
#endif
	}

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
