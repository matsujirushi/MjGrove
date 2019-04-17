#pragma once

#if defined ARDUINO_WIO_LTE

#include <WioLTEforArduino.h>	// https://github.com/SeeedJP/WioLTEforArduino
#include <Wire.h>

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

#endif // ARDUINO_WIO_LTE
