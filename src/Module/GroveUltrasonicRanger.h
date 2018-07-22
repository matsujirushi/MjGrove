//GROVE_NAME        "Grove - Ultrasonic Ranger"
//SKU               101020010
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Ultrasonic_Ranger/

#pragma once

#include "GroveModule.h"
#include "../Connector/GroveConnectorDIO.h"

class GroveUltrasonicRanger : public GroveModule
{
private:
	GroveGpio* _Pin;

	unsigned long MicrosDiff(unsigned long begin, unsigned long end);
	unsigned long PulseIn(bool state, unsigned long timeout = 1000000);

public:
	float Distance;

public:
	GroveUltrasonicRanger(GroveConnectorDIO* connector)
	{
		_Pin = &connector->P1;
	}

	void Init();
	void Read();

};
