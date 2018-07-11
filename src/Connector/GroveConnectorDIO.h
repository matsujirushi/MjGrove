#pragma once

#include "GroveConnector.h"
#include "../Interface/GroveGpio.h"

class GroveConnectorDIO : public GroveConnector
{
private:
	GroveGpio _Pin1;
	GroveGpio _Pin2;

public:
	GroveConnectorDIO(int pin1, int pin2) : _Pin1(pin1), _Pin2(pin2)
	{
	}

	~GroveConnectorDIO()
	{
	}

	GroveGpio& P1()
	{
		return _Pin1;
	}

	GroveGpio& P2()
	{
		return _Pin2;
	}

};
