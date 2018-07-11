#pragma once

#include "../HAL/HalGpio.h"

class GroveGpio : private HalGpio
{
public:
	enum ModeType
	{
		MODE_INPUT,
		MODE_OUTPUT,
	};

public:
	GroveGpio(int pin) : HalGpio(pin)
	{
	}

	void SetMode(ModeType mode);

	void Write(bool on)
	{
		HalGpio::Write(on);
	}

};
