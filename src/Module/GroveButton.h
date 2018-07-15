//GROVE_NAME        "Grove - Button"
//SKU               101020003
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Button/

#pragma once

#include "../Connector/GroveConnectorDIO.h"

class GroveButton
{
private:
	GroveConnectorDIO* _Connector;

public:
	GroveButton(GroveConnectorDIO* connector) : _Connector(connector)
	{
		_Connector->P1().SetMode(GroveGpio::MODE_INPUT);
		_Connector->P2().SetMode(GroveGpio::MODE_INPUT);
	}

	bool IsOn() const
	{
		return _Connector->P1().Read();
	}

};
