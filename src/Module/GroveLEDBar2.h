//GROVE_NAME        "Grove LED Bar v2.0"
//SKU               104020006
//WIKI_URL          http://wiki.seeedstudio.com/Grove-LED_Bar/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorDIO.h"

class GroveLEDBar2 : public GroveModule
{
private:
	GroveGpio* _PinDI;
	GroveGpio* _PinDCKI;
	float _BrightnessList[10];

	void SendData(uint16_t data);
	void LatchData();

public:
	GroveLEDBar2(GroveConnectorDIO* connector)
	{
		_PinDI = &connector->P1;
		_PinDCKI = &connector->P2;
	}

	void Init();
	void Clear();
	void SetBrightness(int index, float brightness);
	void Show();

};
