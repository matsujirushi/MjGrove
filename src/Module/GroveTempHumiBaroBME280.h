//GROVE_NAME        "Grove - Temp&Humi&Barometer Sensor (BME280)"
//SKU               101020193
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Barometer_Sensor-BME280/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorI2C.h"

class GroveTempHumiBaroBME280 : public GroveModule
{
private:
	HalI2CDevice * _Device;

	uint16_t dig_T1;
	int16_t dig_T2;
	int16_t dig_T3;

	uint16_t dig_P1;
	int16_t dig_P2;
	int16_t dig_P3;
	int16_t dig_P4;
	int16_t dig_P5;
	int16_t dig_P6;
	int16_t dig_P7;
	int16_t dig_P8;
	int16_t dig_P9;

	uint8_t dig_H1;
	int16_t dig_H2;
	uint8_t dig_H3;
	int16_t dig_H4;
	int16_t dig_H5;
	int8_t  dig_H6;

	uint8_t ReadReg8(uint8_t reg);
	uint16_t ReadReg16(uint8_t reg);
	uint16_t ReadReg16LE(uint8_t reg);
	int16_t ReadRegS16(uint8_t reg);
	int16_t ReadRegS16LE(uint8_t reg);
	uint32_t ReadReg24(uint8_t reg);

public:
	float Temperature;
	float Humidity;
	float Pressure;

public:
	GroveTempHumiBaroBME280(GroveConnectorI2C* connector)
	{
		_Device = connector->NewDevice(0x76);	// I2C_ADDRESS
	}

	void Init();
	void Read();

};
