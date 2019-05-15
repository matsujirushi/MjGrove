#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorI2C.h"

class OmronBaro2SMPB02E : public GroveModule
{
private:
	HalI2CDevice * _Device;
	float _a2;
	float _a1;
	float _a0;
	float _bp3;
	float _b21;
	float _b12;
	float _bp2;
	float _b11;
	float _bp1;
	float _bt2;
	float _bt1;
	float _b00;

public:
	float Temperature;
	float Pressure;

public:
	OmronBaro2SMPB02E(GroveConnectorI2C* connector)
	{
		_Device = connector->NewDevice(0x56);	// I2C_ADDRESS
	}

	void Init();
	void Read();

};
