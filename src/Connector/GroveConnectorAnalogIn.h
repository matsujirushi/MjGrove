#pragma once

#include "GroveConnector.h"
#include "../Interface/GroveAnalogIn.h"

class GroveConnectorAnalogIn : public GroveConnector
{
public:
	GroveAnalogIn P1;
	GroveAnalogIn P2;

public:
	GroveConnectorAnalogIn(int pin1, int pin2) : P1(pin1), P2(pin2)
	{
	}

	void Enable()
	{
		P1.Enable();
		P2.Enable();
	}

};
