#include "GroveLEDBar2.h"

void GroveLEDBar2::SendData(uint16_t data)
{
	for (int i = 0; i < 16;)
	{
		_PinDI->Write(data & 0x8000 ? true : false);
		delayMicroseconds(1);
		_PinDCKI->Write(true);
		delayMicroseconds(1);
		data <<= 1;
		i++;

		_PinDI->Write(data & 0x8000 ? true : false);
		delayMicroseconds(1);
		_PinDCKI->Write(false);
		delayMicroseconds(1);
		data <<= 1;
		i++;
	}
}

void GroveLEDBar2::LatchData()
{
	delayMicroseconds(220);
	for (int i = 0; i < 4; i++)
	{
		_PinDI->Write(true);
		delayMicroseconds(1);
		_PinDI->Write(false);
		delayMicroseconds(1);
	}
}

void GroveLEDBar2::Init()
{
	_PinDI->SetMode(HalGpio::MODE_OUTPUT);
	_PinDI->Write(false);
	_PinDCKI->SetMode(HalGpio::MODE_OUTPUT);
	_PinDCKI->Write(false);

	Clear();
}

void GroveLEDBar2::Clear()
{
	for (int i = 0; i < 10; i++)
	{
		_BrightnessList[i] = 0;
	}
}

void GroveLEDBar2::SetBrightness(int index, float brightness)
{
	if (index < 0 || 10 <= index) return;

	_BrightnessList[index] = brightness;
}

void GroveLEDBar2::Show()
{
	SendData(0x0000);

	for (int i = 0; i < 10; i++)
	{
		SendData(_BrightnessList[i] * 255);
	}
	SendData(0);
	SendData(0);

	LatchData();
}
