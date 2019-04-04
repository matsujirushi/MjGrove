#pragma once

#include "../../HalAnalogInBase.h"
#include <Arduino.h>

class HalAnalogIn : public HalAnalogInBase
{
private:
	int _Pin;

public:
	HalAnalogIn(int pin)
	{
		_Pin = pin;
	}

protected:
	virtual void EnableImplement()
	{
		pinMode(_Pin, INPUT_ANALOG);
	}

	virtual float ReadImplement()
	{
		return (float)analogRead(_Pin) / 1023;
	}

};
