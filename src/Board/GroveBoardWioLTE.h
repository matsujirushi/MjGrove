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
	GroveConnectorDIO D20;
	GroveConnectorDIO D6;
	GroveConnectorDIO D4;
	GroveConnectorI2C I2C;

public:
	GroveBoard() :
		D38(WIO_D38, WIO_D39),
		D20(WIO_D20, WIO_D19),
		D6(WIO_A6, WIO_A7),
		D4(WIO_A4, WIO_A5),
		I2C(&Wire)
	{
	}

};

#endif // ARDUINO_STM32F4_WIO_GPS
