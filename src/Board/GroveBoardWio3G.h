#pragma once

#if defined ARDUINO_WIO_3G

#include "../Connector/GroveConnectorDIO.h"

class GroveBoard
{
public:
	GroveConnectorDIO D38;

public:
	GroveBoard() : D38(38, 39)
	{
	}

};

#endif // ARDUINO_WIO_3G
