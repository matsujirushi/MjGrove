#pragma once

#if defined ARDUINO_WIO_3G

#include "../Connector/GroveConnectorDIO.h"
#include "../Connector/GroveConnectorI2C.h"

class GroveBoard
{
public:
	GroveConnectorDIO D38;
	GroveConnectorI2C I2C;

public:
	GroveBoard() : D38(38, 39), I2C(&WireI2C)
	{
	}

};

#endif // ARDUINO_WIO_3G
