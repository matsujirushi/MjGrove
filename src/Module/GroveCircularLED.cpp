#include "GroveCircularLED.h"
#include "../HAL2/Hal.h"

void GroveCircularLED::SendData(uint16_t data)
{
	for (int i = 0; i < 16;)
	{
		_PinDI->Write(data & 0x8000 ? true : false);
		HalSystem::DelayUs(1);
		_PinDCKI->Write(true);
		HalSystem::DelayUs(1);
		data <<= 1;
		i++;

		_PinDI->Write(data & 0x8000 ? true : false);
		HalSystem::DelayUs(1);
		_PinDCKI->Write(false);
		HalSystem::DelayUs(1);
		data <<= 1;
		i++;
	}
}

void GroveCircularLED::LatchData()
{
	HalSystem::DelayUs(220);
	for (int i = 0; i < 4; i++)
	{
		_PinDI->Write(true);
		HalSystem::DelayUs(1);
		_PinDI->Write(false);
		HalSystem::DelayUs(1);
	}
}

void GroveCircularLED::Init()
{
	_PinDI->Enable(HalGpio::MODE_OUTPUT);
	_PinDI->Write(false);
	_PinDCKI->Enable(HalGpio::MODE_OUTPUT);
	_PinDCKI->Write(false);

	Clear();
}

void GroveCircularLED::Clear()
{
	for (int i = 0; i < 24; i++)
	{
		_BrightnessList[i] = 0;
	}
}

void GroveCircularLED::SetBrightness(int index, float brightness)
{
	if (index < 0 || 24 <= index) return;

	_BrightnessList[index] = brightness;
}

void GroveCircularLED::Show()
{
	SendData(0x0000);
	for (int i = 0; i < 12; i++)
	{
		SendData(_BrightnessList[i] * 255);
	}

	SendData(0x0000);
	for (int i = 12; i < 24; i++)
	{
		SendData(_BrightnessList[i] * 255);
	}

	LatchData();
}
