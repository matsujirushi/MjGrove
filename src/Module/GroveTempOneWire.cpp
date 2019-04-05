#include "GroveTempOneWire.h"
#include "../HAL/Hal.h"

void GroveTempOneWire::PinWrite(int value)
{
	if (value)
	{
		_Pin->Enable(HalGpio::MODE_INPUT);
	}
	else
	{
		_Pin->Enable(HalGpio::MODE_OUTPUT);
		_Pin->Write(false);
	}
}

int GroveTempOneWire::PinRead() const
{
	return _Pin->Read() ? 1 : 0;
}

bool GroveTempOneWire::WriteByte(uint8_t data)
{
	for (int i = 0; i < 8; i++)
	{
		// Start of slot.
		PinWrite(0);
		HalSystem::DelayUs(1);

		if (data & 1 << i)
		{
			// Write 1.
			PinWrite(1);
			HalSystem::DelayUs(59);
		}
		else
		{
			// Write 0.
			HalSystem::DelayUs(59);
		}

		// End of slot.
		PinWrite(1);
		HalSystem::DelayUs(1);

		// Check bus.
		if (!PinRead()) return false;
	}

	return true;
}

bool GroveTempOneWire::ReadByte(uint8_t* data)
{
	*data = 0;

	for (int i = 0; i < 8; i++)
	{
		// Start of slot.
		PinWrite(0);
		HalSystem::DelayUs(1);

		// free bus.
		PinWrite(1);
		HalSystem::DelayUs(9);

		// Read.
		*data |= PinRead() << i;

		// End of slot.
		HalSystem::DelayUs(50);

		// Check bus.
		if (!PinRead()) return false;
	}

	return true;
}

bool GroveTempOneWire::OneWireReset()
{
	PinWrite(0);
	HalSystem::DelayUs(480);
	PinWrite(1);
	HalSystem::DelayUs(480);

	// Check bus.
	if (!PinRead()) return false;

	return true;
}

bool GroveTempOneWire::OneWireSkipRom()
{
	if (!WriteByte(0xcc)) return false;	// Skip Rom

	return true;
}

bool GroveTempOneWire::OneWireWriteScratchpad(uint8_t th, uint8_t tl, uint8_t config)
{
	if (!WriteByte(0x4e)) return false;		// Write Scratchpad
	if (!WriteByte(th)) return false;		// TH register
	if (!WriteByte(tl)) return false;		// TL register
	if (!WriteByte(config)) return false;	// Configuration register

	return true;
}

int GroveTempOneWire::OneWireReadScratchpad(uint8_t* data, int dataSize)
{
	if (dataSize < 9) return -1;

	WriteByte(0xbe);	// Write Scratchpad
	for (int i = 0; i < 9; i++)
	{
		if (!ReadByte(&data[i])) return -1;
	}

	return 9;
}

bool GroveTempOneWire::OneWireConvertT()
{
	if (!WriteByte(0x44)) return false;	// Convert T

	int done;
	do
	{
		// Start of slot.
		PinWrite(0);
		HalSystem::DelayUs(1);

		// free bus.
		PinWrite(1);
		HalSystem::DelayUs(9);

		// Read.
		done = PinRead();

		// End of slot.
		HalSystem::DelayUs(50);

		// Check bus.
		if (!PinRead()) return false;
	}
	while (!done);

	return true;
}

void GroveTempOneWire::Init()
{
	PinWrite(1);
}

void GroveTempOneWire::Read()
{
	if (!OneWireReset()) HalSystem::Abort();
	if (!OneWireSkipRom()) HalSystem::Abort();
	if (!OneWireWriteScratchpad(0x7f, 0x80, 0x7f)) HalSystem::Abort();	// 750ms (12bits)

	if (!OneWireReset()) HalSystem::Abort();
	if (!OneWireSkipRom()) HalSystem::Abort();
	if (!OneWireConvertT()) HalSystem::Abort();

	if (!OneWireReset()) HalSystem::Abort();
	if (!OneWireSkipRom()) HalSystem::Abort();
	uint8_t data[9];
	if (OneWireReadScratchpad(data, sizeof(data)) != 9) HalSystem::Abort();

	int16_t value;
	((uint8_t*)&value)[0] = data[0];
	((uint8_t*)&value)[1] = data[1];
	Temperature = (float)value * 125.f / 2000.f;
}
