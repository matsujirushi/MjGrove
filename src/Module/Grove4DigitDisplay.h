//GROVE_NAME        "Grove - 4-Digit Display"
//SKU               104030003
//WIKI_URL          http://wiki.seeedstudio.com/Grove-4-Digit_Display/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorDIO.h"

class Grove4DigitDisplay : public GroveModule
{
private:
	HalGpio* _PinClk;
	HalGpio* _PinDio;

	void TM1637Start();
	void TM1637End();
	void TM1637Write(uint8_t data);

public:
	float Brightness;

public:
	Grove4DigitDisplay(GroveConnectorDIO* connector)
	{
		Brightness = 0.5f;
		_PinClk = &connector->P1;
		_PinDio = &connector->P2;
	}

	void Init();
	void print(int position, int value);
	void print(int value);

};
