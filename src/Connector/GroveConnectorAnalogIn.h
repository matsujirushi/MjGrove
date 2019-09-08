#pragma once

#include "GroveConnector.h"
#include "../HAL/Hal.h"

class GroveConnectorAnalogIn : public GroveConnector
{
public:
	HalAnalogIn P1;
	HalAnalogIn P2;

public:
	GroveConnectorAnalogIn(HalPlatformPinType pin1, HalPlatformPinType pin2) : P1(pin1), P2(pin2)
	{
	}

	void Enable()
	{
		P1.Enable();
		P2.Enable();
	}

};
