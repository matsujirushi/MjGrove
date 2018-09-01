#include "GroveDigitalLight.h"

#define TSL2561_CONTROL		0x80
#define TSL2561_TIMING		0x81
#define TSL2561_INTERRUPT	0x86

void GroveDigitalLight::Init()
{
	_Device->WriteRegByte(TSL2561_CONTROL, 0x03);	// POWER UP
	_Device->WriteRegByte(TSL2561_TIMING, 0x00);	// No High Gain (1x), integration time of 13ms
	_Device->WriteRegByte(TSL2561_INTERRUPT, 0x00);
	_Device->WriteRegByte(TSL2561_CONTROL, 0x00);	// POWER Down
}

void GroveDigitalLight::Read()
{
}
