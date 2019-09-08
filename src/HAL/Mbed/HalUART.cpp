#if defined __MBED__

#include "HalUART.h"

void HalUART::EnableImplement(int baudRate, int dataBit, ParityType parity, int stopBit)
{
	RawSerial::Parity p;
	switch (parity)
	{
	case PARITY_NONE:
		p = RawSerial::None;
		break;
	case PARITY_EVEN:
		p = RawSerial::Even;
		break;
	case PARITY_ODD:
		p = RawSerial::Odd;
		break;
	default:
		abort();
	}

	_Serial->baud(baudRate);
	_Serial->format(dataBit, p, stopBit);
}

void HalUART::WriteImplement(uint8_t data)
{
	_Serial->putc(data);
}

int HalUART::ReadAvailableImplement()
{
	return _Serial->readable();
}

uint8_t HalUART::ReadImplement()
{
	return _Serial->getc();
}

#endif // __MBED__
