#if defined ARDUINO_ARCH_STM32F4 || defined ARDUINO_ARCH_STM32

#include "HalUART.h"

void HalUART::EnableImplement(int baudRate, int dataBit, ParityType parity, int stopBit)
{
	if (dataBit == 8 && parity == PARITY_NONE && stopBit == 1)
	{
		_Serial->begin(baudRate);
	}
	else if (dataBit == 8 && parity == PARITY_ODD && stopBit == 1)
	{
		_Serial->begin(baudRate, SERIAL_8O1);
	}
	else if (dataBit == 8 && parity == PARITY_EVEN && stopBit == 1)
	{
		_Serial->begin(baudRate, SERIAL_8E1);
	}
	else
	{
		abort();
	}
}

void HalUART::WriteImplement(uint8_t data)
{
	_Serial->write(data);
}

int HalUART::ReadAvailableImplement()
{
	return _Serial->available();
}

uint8_t HalUART::ReadImplement()
{
	return _Serial->read();
}

#endif // ARDUINO_ARCH_STM32F4 || ARDUINO_ARCH_STM32
