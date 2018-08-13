#pragma once

#include "GroveConnector.h"
#include "../HAL/HalUART.h"

class GroveConnectorUART : public GroveConnector
{
public:
	HalUART UART;

public:
	GroveConnectorUART(HardwareSerial* serial) : UART(serial)
	{
	}

	void Enable()
	{
		UART.Enable();
	}

};
