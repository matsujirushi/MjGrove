#include "GroveUART.h"

void GroveUART::Enable()
{
}

void GroveUART::SetMode(int baudRate, int dataBit, GroveUART::ParityType parity, int stopBit)
{
	if (dataBit == 8 && parity == PARITY_NONE && stopBit == 1)
	{
		_Serial->begin(baudRate);
	}
#if !defined ARDUINO_STM32F4_WIO_GPS
	else if (dataBit == 8 && parity == PARITY_ODD && stopBit == 1)
	{
		_Serial->begin(baudRate, SERIAL_8O1);
	}
	else if (dataBit == 8 && parity == PARITY_EVEN && stopBit == 1)
	{
		_Serial->begin(baudRate, SERIAL_8E1);
	}
#endif
}
