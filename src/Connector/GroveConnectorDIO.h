#pragma once

#include "GroveConnector.h"
#include "../HAL2/Hal.h"

class GroveConnectorDIO : public GroveConnector
{
public:
	HalGpio P1;
	HalGpio P2;

public:
	GroveConnectorDIO(int pin1, int pin2) : P1(pin1), P2(pin2)
	{
	}

	void Enable()	// TODO
	{
	}

};
