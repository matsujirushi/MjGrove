#pragma once

#include "../HalUARTBase.h"
#include <mbed.h>

class HalUART : public HalUARTBase
{
private:
	RawSerial* _Serial;

public:
	HalUART(RawSerial* serial) : _Serial(serial)
	{
	}

protected:
	virtual void EnableImplement(int baudRate, int dataBit, ParityType parity, int stopBit);
	virtual void WriteImplement(uint8_t data);
	virtual int ReadAvailableImplement();
	virtual uint8_t ReadImplement();

};
