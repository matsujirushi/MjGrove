#pragma once

#if defined ARDUINO_WIO_LTE_M1NB1_BG96

#include <Wio3GforArduino.h>  // https://github.com/SeeedJP/Wio_3G_for_Arduino

typedef Wio3G WioCellular;

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
	GroveConnectorDIO D23;
	GroveConnectorI2C I2C;
	GroveConnectorDIO D24;

public:
	GroveBoard() :
		D38(WIO_D38, WIO_D39),
		D20(WIO_D20, WIO_D19),
		A6(WIO_A6, WIO_A7),
		D6(WIO_A6, WIO_A7),
		A4(WIO_A4, WIO_A5),
		D4(WIO_A4, WIO_A5),
		UART(&SerialUART),
		D23(WIO_UART_D23, WIO_UART_D22),
		I2C(&WireI2C), D24(WIO_I2C_D24, WIO_I2C_D25)
	{
	}

};

#endif // ARDUINO_WIO_LTE_M1NB1_BG96
