//GROVE_NAME        "Grove - EMG Detector"
//SKU               101020058
//WIKI_URL          http://wiki.seeedstudio.com/Grove-EMG_Detector/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorAnalogIn.h"

class GroveEMGDetector : public GroveModule
{
private:
	HalAnalogIn* _Pin;

public:
	GroveEMGDetector(GroveConnectorAnalogIn* connector)
	{
		_Pin = &connector->P1;
	}

	GroveEMGDetector(HalAnalogIn* pin)
	{
		_Pin = pin;
	}

	void Init();
	void Read();

};
