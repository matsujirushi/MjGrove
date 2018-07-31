#include "GroveTempHumiSHT31.h"

#define CMD_SOFT_RESET		0x30a2
#define CMD_SINGLE_HIGH		0x2400

void GroveTempHumiSHT31::SendCommand(uint16_t cmd)
{
	uint8_t writeData[2];
	writeData[0] = cmd >> 8;
	writeData[1] = cmd & 0xff;
	_Device->Write(writeData, sizeof(writeData));
}

void GroveTempHumiSHT31::Init()
{
	SendCommand(CMD_SOFT_RESET);
	delay(1);
}

void GroveTempHumiSHT31::Read()
{
	SendCommand(CMD_SINGLE_HIGH);
	delay(15);

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

	uint16_t ST;
	ST = readData[0];
	ST <<= 8;
	ST |= readData[1];
	// TODO crc check

	uint16_t SRH;
	SRH = readData[3];
	SRH <<= 8;
	SRH |= readData[4];
	// TODO crc check

	Temperature = (float)ST * 175 / 0xffff - 45;
	Humidity = (float)SRH * 100 / 0xffff;
}
