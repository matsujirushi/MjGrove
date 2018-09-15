#include "GroveI2CColorSensor2.h"

#define TCS34725_COMMAND_BIT      (0x80)

#define TCS34725_ID               (0x12)    /* 0x44 = TCS34721/TCS34725, 0x4D = TCS34723/TCS34727 */

void GroveI2CColorSensor2::write8(uint8_t reg, uint8_t value)
{
	uint8_t writeData[2];
	writeData[0] = TCS34725_COMMAND_BIT | reg;
	writeData[1] = value;
	_Device->Write(writeData, sizeof(writeData));
}

uint8_t GroveI2CColorSensor2::read8(uint8_t reg)
{
	uint8_t writeData[1];
	writeData[0] = TCS34725_COMMAND_BIT | reg;
	_Device->Write(writeData, sizeof(writeData));

	uint8_t readData[1];
	_Device->Read(readData, sizeof(readData));

	return readData[0];
}

void GroveI2CColorSensor2::Init()
{
	read8(TCS34725_ID);
}

void GroveI2CColorSensor2::Read()
{
}
