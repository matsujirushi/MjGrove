#pragma once

#include "GroveConnector.h"
#include "../HAL/HalGpio.h"

class GroveConnectorDIO : public GroveConnector
{
public:
	HalGpio P1;
	HalGpio P2;

public:
	GroveConnectorDIO(int pin1, int pin2) : P1(pin1), P2(pin2)
	{
	}

	void Enable()
	{
		P1.Enable();
		P2.Enable();
	}

};
