#pragma once

#include <stdint.h>

class HalUARTBase
{
public:
	enum ParityType
	{
		PARITY_NONE,
		PARITY_EVEN,
		PARITY_ODD,
	};

public:
	void Enable(int baudRate, int dataBit, ParityType parity, int stopBit)
	{
		EnableImplement(baudRate, dataBit, parity, stopBit);
	}

	void Write(uint8_t data)
	{
		WriteImplement(data);
	}

	int ReadAvailable()
	{
		return ReadAvailableImplement();
	}

	uint8_t Read()
	{
		return ReadImplement();
	}

protected:
	virtual void EnableImplement(int baudRate, int dataBit, ParityType parity, int stopBit) = 0;
	virtual void WriteImplement(uint8_t data) = 0;
	virtual int ReadAvailableImplement() = 0;
	virtual uint8_t ReadImplement() = 0;

};
