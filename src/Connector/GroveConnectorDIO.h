#pragma once

#include "GroveConnector.h"
#include "../Interface/GroveGpio.h"

class GroveConnectorDIO : public GroveConnector
{
public:
	GroveGpio P1;
	GroveGpio P2;

public:
	GroveConnectorDIO(int pin1, int pin2) : P1(pin1), P2(pin2)
	{
	}

	~GroveConnectorDIO()
	{
	}

};
