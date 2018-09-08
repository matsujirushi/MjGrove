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

	void WriteByte(uint8_t reg, uint8_t value);
	uint8_t ReadByte(uint8_t reg);

	void SetLedMode(uint8_t ledMode);

public:
	int UpCount;
	int DownCount;
	int LeftCount;
	int RightCount;
	int ConfirmCount;

	int PositionX;
	int PositionY;

public:
	GroveMiniTrackBall(GroveConnectorI2C* connector)
	{
		_Device = connector->NewDevice(0x4A);	// I2C_ADDRESS

		UpCount = 0;
		DownCount = 0;
		LeftCount = 0;
		RightCount = 0;
		ConfirmCount = 0;

		PositionX = 0;
		PositionY = 0;
	}

	void Init();
	void Read();

};
