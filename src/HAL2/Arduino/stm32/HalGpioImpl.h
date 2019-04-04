#pragma once

#include "../../HalGpioBase.h"
#include <Arduino.h>

class HalGpio : public HalGpioBase
{
private:
	int _Pin;

public:
	HalGpio(int pin)
	{
		_Pin = pin;
	}

	virtual void SetModeImplement(ModeType mode)
	{
		switch (mode)
		{
		case MODE_INPUT:
			pinMode(_Pin, INPUT);
			break;
		case MODE_OUTPUT:
			pinMode(_Pin, OUTPUT);
			break;
		case MODE_OUTPUT_OPEN_DRAIN:
			pinMode(_Pin, OUTPUT_OPEN_DRAIN);
			break;
		default:
			abort();
		}
	}

	virtual void WriteImplement(bool high)
	{
		digitalWrite(_Pin, high ? HIGH : LOW);
	}

	virtual bool ReadImplement() const
	{
		return digitalRead(_Pin) == HIGH;
	}

};
