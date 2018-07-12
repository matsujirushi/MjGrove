//GROVE_NAME        "Grove - Buzzer"
//SKU               107020000
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Buzzer/

#pragma once

#include "../Connector/GroveConnectorDIO.h"

class GroveBuzzer
{
private:
	GroveConnectorDIO* _Connector;

public:
	GroveBuzzer(GroveConnectorDIO* connector) : _Connector(connector)
	{
		_Connector->P1().SetMode(GroveGpio::MODE_OUTPUT);
		_Connector->P1().Write(false);

		_Connector->P2().SetMode(GroveGpio::MODE_INPUT);
	}

	void On()
	{
		_Connector->P1().Write(true);
	}

	void Off()
	{
		_Connector->P1().Write(false);
	}

	bool IsOn() const
	{
		return _Connector->P1().ReadOutput();
	}

};
