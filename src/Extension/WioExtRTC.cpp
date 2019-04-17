#include "WioExtRTC.h"

#define PCF8523_CONTROL_1			(0x00)
#define PCF8523_CONTROL_2			(0x01)
#define PCF8523_CONTROL_3			(0x02)
#define PCF8523_SECONDS				(0x03)
#define PCF8523_MINUTES				(0x04)
#define PCF8523_HOURS				(0x05)
#define PCF8523_DAYS				(0x06)
#define PCF8523_WEEKDAYS			(0x07)
#define PCF8523_MONTHS				(0x08)
#define PCF8523_YEARS				(0x09)
#define PCF8523_MINUTE_ALARM		(0x0a)
#define PCF8523_HOUR_ALARM			(0x0b)
#define PCF8523_DAY_ALARM			(0x0c)
#define PCF8523_WEEKDAY_ALARM		(0x0d)
#define PCF8523_OFFSET				(0x0e)
#define PCF8523_TMR_CLOCKOUT_CTRL	(0x0f)
#define PCF8523_TMR_A_FREQ_CTRL		(0x10)
#define PCF8523_TMR_A_REG			(0x11)
#define PCF8523_TMR_B_FREQ_CTRL		(0x12)
#define PCF8523_TMR_B_REG			(0x13)

bool WioExtRTC::Init()
{
	if (!_Device->ChangeReg8(PCF8523_TMR_CLOCKOUT_CTRL, 0b11000111, 0b00000000)) return false;	// CLKOUT is 32768Hz
	
	return true;
}

////////////////////////////////////////////////////////////////////////////////
// RTC functions

bool WioExtRTC::SetWakeupPeriod(int sec)
{
	if (sec <= 0 || 255 < sec / 3600) return false;

	if (!_Device->ChangeReg8(PCF8523_TMR_CLOCKOUT_CTRL, 0b11111110, 0b00000000)) return false;	// timer B is disabled

	if (sec <= 255)
	{
		_Device->WriteReg8(PCF8523_TMR_B_FREQ_CTRL, 0b00000010);							// source for timer B is 1Hz
		_Device->WriteReg8(PCF8523_TMR_B_REG, sec);											// timer B value
	}
	else if (sec / 60 <= 255)
	{
		_Device->WriteReg8(PCF8523_TMR_B_FREQ_CTRL, 0b00000011);							// source for timer B is 1/60Hz
		_Device->WriteReg8(PCF8523_TMR_B_REG, sec / 60);									// timer B value

	}
	else
	{
		_Device->WriteReg8(PCF8523_TMR_B_FREQ_CTRL, 0b00000100);							// source for timer B is 1/3600Hz
		_Device->WriteReg8(PCF8523_TMR_B_REG, sec / 3600);									// timer B value
	}

	if (!_Device->ChangeReg8(PCF8523_CONTROL_2, 0b00000000, 0b00000001)) return false;		// countdown timer B interrupt is enabled

	if (!_Device->ChangeReg8(PCF8523_TMR_CLOCKOUT_CTRL, 0b11111111, 0b00000001)) return false;	// timer B is enabled

	return true;
}

bool WioExtRTC::Shutdown()
{
	if (!_Device->ChangeReg8(PCF8523_TMR_CLOCKOUT_CTRL, 0b11111111, 0b00111000)) return false;	// CLKOUT disabled

	return true;
}

////////////////////////////////////////////////////////////////////////////////
// EEPROM functions

void WioExtRTC::EEPROM::Write(uint16_t address, const void* data, int dataSize)
{
	uint8_t writeBuffer[2 + dataSize];
	writeBuffer[0] = address >> 8;
	writeBuffer[1] = address;
	memcpy(&writeBuffer[2], data, dataSize);
	_Device->Write(writeBuffer, 2 + dataSize);
}

bool WioExtRTC::EEPROM::Read(uint16_t address, void* data, int dataSize)
{
	uint8_t writeBuffer[2];
	writeBuffer[0] = address >> 8;
	writeBuffer[1] = address;
	_Device->Write(writeBuffer, 2);

	auto readSize = _Device->Read((uint8_t*)data, dataSize);

	return readSize == dataSize;
}

////////////////////////////////////////////////////////////////////////////////
