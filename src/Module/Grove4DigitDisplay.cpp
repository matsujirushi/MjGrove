#include "Grove4DigitDisplay.h"
#include "../HAL/HalSystem.h"

#define ADDR_FIXED		(0x44)

static const uint8_t TubeTab[] =
{
	0x3f, 0x06, 0x5b, 0x4f,	// '0', '1', '2', '3',
	0x66, 0x6d, 0x7d, 0x07,	// '4', '5', '6', '7',
	0x7f, 0x6f, 0x77, 0x7c,	// '8', '9', 'A', 'b',
	0x39, 0x5e, 0x79, 0x71,	// 'C', 'd', 'E', 'F',
};

void Grove4DigitDisplay::TM1637Start()
{
	_PinClk->Write(true);
	_PinDio->Write(false);
	HalSystem::DelayUs(10);
}

void Grove4DigitDisplay::TM1637End()
{
	_PinClk->Write(false);
	HalSystem::DelayUs(10);
	_PinClk->Write(true);
	HalSystem::DelayUs(10);
	_PinDio->Write(true);
	HalSystem::DelayUs(100);
}

void Grove4DigitDisplay::TM1637Write(uint8_t data)
{
	for (int i = 0; i < 8; i++)
	{
		_PinClk->Write(false);
		_PinDio->Write(data & 1 ? true : false);
		data >>= 1;
		HalSystem::DelayUs(10);

		_PinClk->Write(true);
		HalSystem::DelayUs(10);
	}

	_PinDio->Write(true);
	_PinClk->Write(false);
	HalSystem::DelayUs(10);

	//bool ack = _PinDio->Read();
	_PinDio->Write(false);
	_PinClk->Write(true);
	HalSystem::DelayUs(10);
}

void Grove4DigitDisplay::Init()
{
	_PinClk->SetMode(HalGpio::MODE_OUTPUT);
	_PinClk->Write(true);
	_PinDio->SetMode(HalGpio::MODE_OUTPUT_OPEN_DRAIN);
	_PinDio->Write(true);
}

void Grove4DigitDisplay::print(int position, int value)
{
	uint8_t segData;
	switch (value)
	{
	case -1:	// Blank
		segData = 0x00;
		break;
	default:
		if (0 <= value && value <= 15)
		{
			segData = TubeTab[value];
		}
		else
		{
			segData = 0x00;
		}
	}

	TM1637Start();
	TM1637Write(ADDR_FIXED);
	TM1637End();

	TM1637Start();
	TM1637Write((uint8_t)(position | 0xc0));
	TM1637Write(segData);
	TM1637End();

	TM1637Start();
	TM1637Write((uint8_t)(0x88 + Brightness * 7));
	TM1637End();
}

void Grove4DigitDisplay::print(int value)
{
	print(3, value % 10);
	value /= 10;
	print(2, value % 10);
	value /= 10;
	print(1, value % 10);
	value /= 10;
	print(0, value % 10);
}
