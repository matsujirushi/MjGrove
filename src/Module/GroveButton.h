//GROVE_NAME        "Grove - Button"
//SKU               101020003
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Button/

#pragma once

#include "GroveModule.h"
#include "../Connector/GroveConnectorDIO.h"

class GroveButton : public GroveModule
{
private:
	GroveGpio* _Pin;

public:
	GroveButton(GroveConnectorDIO* connector)
	{
		_Pin = &connector->P1;
	}

	void Init()
	{
		_Pin->SetMode(GroveGpio::MODE_INPUT);
	}

	bool IsOn() const
	{
		return _Pin->Read();
	}

};
