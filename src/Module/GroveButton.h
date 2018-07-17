//GROVE_NAME        "Grove - Button"
//SKU               101020003
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Button/

#pragma once

#include "../Connector/GroveConnectorDIO.h"

class GroveButton
{
private:
	GroveGpio* _Pin;

public:
	GroveButton(GroveConnectorDIO* connector)
	{
		_Pin = &connector->P1;
		_Pin->Enable();
		_Pin->SetMode(GroveGpio::MODE_INPUT);
	}

	bool IsOn() const
	{
		return _Pin->Read();
	}

};
