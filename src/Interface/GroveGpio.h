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

	void Enable()
	{
		HalGpio::Enable();
	}

	void SetMode(ModeType mode);

	void Write(bool on)
	{
		HalGpio::Write(on);
	}

	bool Read() const
	{
		return HalGpio::Read();
	}

	bool ReadOutput() const
	{
		return HalGpio::ReadOutput();
	}

};
