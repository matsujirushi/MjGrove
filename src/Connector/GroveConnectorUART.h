#pragma once

#include "GroveConnector.h"
#include "../Interface/GroveUART.h"

class GroveConnectorUART : public GroveConnector
{
public:
	GroveUART UART;

public:
	GroveConnectorUART(HardwareSerial* serial) : UART(serial)
	{
	}

	void Enable()
	{
		UART.Enable();
	}

};
