#include "GroveLEDBar2.h"
#include "../HAL2/Hal.h"

void GroveLEDBar2::SendData(uint16_t data)
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

void GroveLEDBar2::LatchData()
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

void GroveLEDBar2::Init()
{
	_PinDI->Enable(HalGpio::MODE_OUTPUT);
	_PinDI->Write(false);
	_PinDCKI->Enable(HalGpio::MODE_OUTPUT);
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
