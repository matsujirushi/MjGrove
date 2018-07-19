#pragma once

#if defined ARDUINO_STM32F4_WIO_GPS

#include <WioLTEforArduino.h>	// https://github.com/SeeedJP/WioLTEforArduino
#include <Wire.h>

typedef WioLTE WioCellular;

#include "../Connector/GroveConnectorDIO.h"
#include "../Connector/GroveConnectorI2C.h"

class GroveBoard
{
public:
	GroveConnectorDIO D38;
	GroveConnectorI2C I2C;

public:
	GroveBoard() : D38(38, 39), I2C(&Wire)
	{
	}

};

#endif // ARDUINO_STM32F4_WIO_GPS
