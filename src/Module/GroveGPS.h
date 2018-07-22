//GROVE_NAME        "Grove - GPS"
//SKU               113020003
//WIKI_URL          http://wiki.seeedstudio.com/Grove-GPS/

#pragma once

#include "GroveModule.h"
#include "../Connector/GroveConnectorUART.h"

class GroveGPS : public GroveModule
{
private:
	GroveUART* _UART;

public:
	GroveGPS(GroveConnectorUART* connector)
	{
		_UART = &connector->UART;
	}

	void Init();
	void DoWork();

};
