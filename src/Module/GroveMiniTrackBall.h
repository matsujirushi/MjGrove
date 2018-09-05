//GROVE_NAME        "Grove - Mini Track Ball"
//SKU               101020091
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Mini_Track_Ball/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorI2C.h"

class GroveMiniTrackBall : public GroveModule
{
private:
	HalI2CDevice* _Device;

	void SetLedMode(uint8_t ledMode);


public:
	GroveMiniTrackBall(GroveConnectorI2C* connector)
	{
		_Device = connector->NewDevice(0x4A);	// I2C_ADDRESS
	}

	void Init();
	void Read();

};
