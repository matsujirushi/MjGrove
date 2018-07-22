#pragma once

#include <Arduino.h>

class GroveUART
{
private:
	HardwareSerial* _Serial;

public:
	enum ParityType
	{
		PARITY_NONE,
		PARITY_EVEN,
		PARITY_ODD,
	};

public:
	GroveUART(HardwareSerial* serial) : _Serial(serial)
	{
	}

	void Enable();

	void SetMode(int baudRate, int dataBit, ParityType parity, int stopBit);

	void Write(uint8_t data)
	{
		_Serial->write(data);
	}

	int Available()
	{
		return _Serial->available();
	}

	uint8_t Read()
	{
		return _Serial->read();
	}

};
