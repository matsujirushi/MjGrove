#include "GroveI2CColorSensor2.h"

#define TCS34725_COMMAND_BIT      (0x80)

#define TCS34725_ENABLE           (0x00)
#define TCS34725_ENABLE_AEN       (0x02)    /* RGBC Enable - Writing 1 actives the ADC, 0 disables it */
#define TCS34725_ENABLE_PON       (0x01)    /* Power on - Writing 1 activates the internal oscillator, 0 disables it */

#define TCS34725_ID               (0x12)    /* 0x44 = TCS34721/TCS34725, 0x4D = TCS34723/TCS34727 */
#define TCS34725_ATIME            (0x01)    /* Integration time */
#define TCS34725_CONTROL          (0x0F)    /* Set the gain level for the sensor */
#define TCS34725_CDATAL           (0x14)    /* Clear channel data */
#define TCS34725_CDATAH           (0x15)
#define TCS34725_RDATAL           (0x16)    /* Red channel data */
#define TCS34725_RDATAH           (0x17)
#define TCS34725_GDATAL           (0x18)    /* Green channel data */
#define TCS34725_GDATAH           (0x19)
#define TCS34725_BDATAL           (0x1A)    /* Blue channel data */
#define TCS34725_BDATAH           (0x1B)

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

uint16_t GroveI2CColorSensor2::read16(uint8_t reg)
{
	uint8_t writeData[1];
	writeData[0] = TCS34725_COMMAND_BIT | reg;
	_Device->Write(writeData, sizeof(writeData));

	uint8_t readData[2];
	_Device->Read(readData, sizeof(readData));

	return readData[1] << 8 | readData[0];
}
void GroveI2CColorSensor2::enable()
{
	write8(TCS34725_ENABLE, TCS34725_ENABLE_PON);
	delay(3);
	write8(TCS34725_ENABLE, TCS34725_ENABLE_PON | TCS34725_ENABLE_AEN);
}

void GroveI2CColorSensor2::getRawData(uint16_t* r, uint16_t* g, uint16_t* b, uint16_t* c)
{
	*c = read16(TCS34725_CDATAL);
	*r = read16(TCS34725_RDATAL);
	*g = read16(TCS34725_GDATAL);
	*b = read16(TCS34725_BDATAL);
}

void GroveI2CColorSensor2::Init()
{
	uint8_t x = read8(TCS34725_ID);
	if (x != 0x44 && x != 0x10) HalSystem::Abort();

	enable();

	SetIntegrationTime(2.4);
	SetGain(1);
}

void GroveI2CColorSensor2::SetIntegrationTime(float time)
{
	if (time < 2.4f) time = 2.4f;
	if (time > 614.0f) time = 614.0f;

	uint8_t atime = (uint8_t)(256.0f - time / 2.4f);

	write8(TCS34725_ATIME, atime);
}

void GroveI2CColorSensor2::SetGain(int gain)
{
	uint8_t gainValue;

	switch (gain)
	{
	case 1:
		gainValue = 0x00;
		break;
	case 4:
		gainValue = 0x01;
		break;
	case 16:
		gainValue = 0x02;
		break;
	case 60:
		gainValue = 0x03;
		break;
	default:
		HalSystem::Abort();
	}

	write8(TCS34725_CONTROL, gainValue);
}

void GroveI2CColorSensor2::Read()
{
	getRawData(&R, &G, &B, &C);
}
