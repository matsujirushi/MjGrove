#pragma once

#include "GroveConnector.h"
#include "../HAL/HalGpio.h"

class GroveConnectorDIO : public GroveConnector
{
private:
	HalGpio _Pin1;
	HalGpio _Pin2;

public:
	GroveConnectorDIO(int pin1, int pin2) : _Pin1(pin1), _Pin2(pin2)
	{
	}

	~GroveConnectorDIO()
	{
	}

	HalGpio& P1()
	{
		return _Pin1;
	}

	HalGpio& P2()
	{
		return _Pin2;
	}

};
