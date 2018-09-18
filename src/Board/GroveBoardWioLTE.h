#pragma once

#if defined ARDUINO_STM32F4_WIO_GPS

#include <WioLTEforArduino.h>	// https://github.com/SeeedJP/WioLTEforArduino
#include <Wire.h>

#include "../Connector/GroveConnectorDIO.h"
#include "../Connector/GroveConnectorUART.h"
#include "../Connector/GroveConnectorI2C.h"
#include "../Connector/GroveConnectorAnalogIn.h"

class GroveBoard
{
public:
	GroveConnectorDIO D38;
	GroveConnectorDIO D20;
	GroveConnectorAnalogIn A6;
	GroveConnectorDIO D6;
	GroveConnectorAnalogIn A4;
	GroveConnectorDIO D4;
	GroveConnectorUART UART;
	GroveConnectorI2C I2C;

public:
	GroveBoard() :
		D38(WIO_D38, WIO_D39),
		D20(WIO_D20, WIO_D19),
		A6(WIO_A6, WIO_A7),
		D6(WIO_A6, WIO_A7),
		A4(WIO_A4, WIO_A5),
		D4(WIO_A4, WIO_A5),
		UART(&Serial),
		I2C(&Wire)
	{
	}

};

#endif // ARDUINO_STM32F4_WIO_GPS
