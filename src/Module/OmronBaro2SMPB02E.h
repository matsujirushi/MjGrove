#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorI2C.h"

class OmronBaro2SMPB02E : public GroveModule
{
public:
	enum STANDBY_TIME
	{
		STANDBY_1MS,
		STANDBY_5MS,
		STANDBY_50MS,
		STANDBY_250MS,
		STANDBY_500MS,
		STANDBY_1S,
		STANDBY_2S,
		STANDBY_4S,
	};

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

	uint8_t _TemperatureAverageNumber;
	uint8_t _PressureAverageNumber;
	STANDBY_TIME _StandbyTime;

public:
	float Temperature;
	float Pressure;

public:
	OmronBaro2SMPB02E(GroveConnectorI2C* connector)
	{
		_TemperatureAverageNumber = 1;
		_PressureAverageNumber = 1;
		_StandbyTime = STANDBY_1MS;

		_Device = connector->NewDevice(0x56);	// I2C_ADDRESS
	}

	void SetTemperatureAverageNumber(int temperatureAverageNumber);
	void SetPressureAverageNumber(int pressureAverageNumber);
	void SetStandbyTime(STANDBY_TIME standbyTime);
	void Init();
	void Read();

};
