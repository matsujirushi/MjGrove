#pragma once

#include <Arduino.h>

class GroveGpio
{
private:
	uint8_t _GpioPin;
	bool _GpioOutput;

public:
	enum ModeType
	{
		MODE_INPUT,
		MODE_OUTPUT,
	};

public:
	GroveGpio(int pin)
	{
		_GpioPin = pin;
	}

	void Enable()
	{
	}

	void SetMode(ModeType mode)
	{
		switch (mode)
		{
		case MODE_INPUT:
			pinMode(_GpioPin, INPUT);
			break;
		case MODE_OUTPUT:
			pinMode(_GpioPin, OUTPUT);
			break;
		}
	}

	void Write(bool on)
	{
		digitalWrite(_GpioPin, on ? HIGH : LOW);
		_GpioOutput = on;
	}

	bool Read() const
	{
		return digitalRead(_GpioPin) == HIGH;
	}

	bool ReadOutput() const
	{
		return _GpioOutput ? HIGH : LOW;
	}

};
