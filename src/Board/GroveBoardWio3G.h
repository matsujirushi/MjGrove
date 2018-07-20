#pragma once

#if defined ARDUINO_WIO_3G

#include <Wio3GforArduino.h>  // https://github.com/SeeedJP/Wio_3G_for_Arduino

typedef Wio3G WioCellular;

#include "../Connector/GroveConnectorDIO.h"
#include "../Connector/GroveConnectorI2C.h"

class GroveBoard
{
public:
	GroveConnectorDIO D38;
	GroveConnectorDIO D20;
	GroveConnectorDIO D6;
	GroveConnectorDIO D4;
	GroveConnectorDIO D23;
	GroveConnectorI2C I2C;
	GroveConnectorDIO D24;

public:
	GroveBoard() :
		D38(WIO_D38, WIO_D39),
		D20(WIO_D20, WIO_D19),
		D6(WIO_A6, WIO_A7),
		D4(WIO_A4, WIO_A5),
		D23(WIO_UART_D23, WIO_UART_D22),
		I2C(&WireI2C), D24(WIO_I2C_D24, WIO_I2C_D25)
	{
	}

};

#endif // ARDUINO_WIO_3G
