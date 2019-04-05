#pragma once

#include "GroveConnector.h"
#include "../HAL/Hal.h"

class GroveConnectorUART : public GroveConnector
{
public:
	HalUART UART;

public:
	GroveConnectorUART(HardwareSerial* serial) : UART(serial)
	{
	}

	void Enable()	// TODO
	{
		UART.Enable(9600, 8, HalUART::PARITY_NONE, 1);
	}

	void Enable(int baudRate, int dataBit, HalUART::ParityType parity, int stopBit)
	{
		UART.Enable(baudRate, dataBit, parity, stopBit);
	}

};
