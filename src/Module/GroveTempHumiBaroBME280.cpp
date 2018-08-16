#include "GroveTempHumiBaroBME280.h"
#include "Abstract/GroveModuleError.h"

#define BME280_REG_CHIPID		(0xD0)
#define BME280_REG_CONTROLHUMID	(0xF2)
#define BME280_REG_CONTROL      (0xF4)

#define BME280_REG_DIG_T1		(0x88)
#define BME280_REG_DIG_T2		(0x8A)
#define BME280_REG_DIG_T3		(0x8C)

#define BME280_REG_DIG_P1		(0x8E)
#define BME280_REG_DIG_P2		(0x90)
#define BME280_REG_DIG_P3		(0x92)
#define BME280_REG_DIG_P4		(0x94)
#define BME280_REG_DIG_P5		(0x96)
#define BME280_REG_DIG_P6		(0x98)
#define BME280_REG_DIG_P7		(0x9A)
#define BME280_REG_DIG_P8		(0x9C)
#define BME280_REG_DIG_P9		(0x9E)

#define BME280_REG_DIG_H1		(0xA1)
#define BME280_REG_DIG_H2		(0xE1)
#define BME280_REG_DIG_H3		(0xE3)
#define BME280_REG_DIG_H4		(0xE4)
#define BME280_REG_DIG_H5		(0xE5)
#define BME280_REG_DIG_H6		(0xE7)

uint8_t GroveTempHumiBaroBME280::ReadReg8(uint8_t reg)
{
	uint8_t data;

	_Device->ReadRegByte(reg, &data);

	return data;
}

uint16_t GroveTempHumiBaroBME280::ReadReg16(uint8_t reg)
{
	uint8_t data[2];

	_Device->ReadRegBytes(reg, data, sizeof(data));

	return (uint16_t)data[0] << 8 | data[1];
}

uint16_t GroveTempHumiBaroBME280::ReadReg16LE(uint8_t reg)
{
	uint8_t data[2];

	_Device->ReadRegBytes(reg, data, sizeof(data));

	return (uint16_t)data[1] << 8 | data[0];
}

int16_t GroveTempHumiBaroBME280::ReadRegS16(uint8_t reg)
{
	return (int16_t)ReadReg16(reg);
}

int16_t GroveTempHumiBaroBME280::ReadRegS16LE(uint8_t reg)
{
	return (int16_t)ReadReg16LE(reg);
}

uint32_t GroveTempHumiBaroBME280::ReadReg24(uint8_t reg)
{
	uint8_t data[3];

	_Device->ReadRegBytes(reg, data, sizeof(data));

	return (uint32_t)data[0] << 16 | (uint32_t)data[1] << 8 | data[2];
}

void GroveTempHumiBaroBME280::Init()
{
	if (ReadReg8(BME280_REG_CHIPID) != 0x60) GROVE_MODULE_ERROR("exception");

	dig_T1 = ReadReg16LE(BME280_REG_DIG_T1);
	dig_T2 = ReadRegS16LE(BME280_REG_DIG_T2);
	dig_T3 = ReadRegS16LE(BME280_REG_DIG_T3);

	dig_P1 = ReadReg16LE(BME280_REG_DIG_P1);
	dig_P2 = ReadRegS16LE(BME280_REG_DIG_P2);
	dig_P3 = ReadRegS16LE(BME280_REG_DIG_P3);
	dig_P4 = ReadRegS16LE(BME280_REG_DIG_P4);
	dig_P5 = ReadRegS16LE(BME280_REG_DIG_P5);
	dig_P6 = ReadRegS16LE(BME280_REG_DIG_P6);
	dig_P7 = ReadRegS16LE(BME280_REG_DIG_P7);
	dig_P8 = ReadRegS16LE(BME280_REG_DIG_P8);
	dig_P9 = ReadRegS16LE(BME280_REG_DIG_P9);

	dig_H1 = ReadReg8(BME280_REG_DIG_H1);
	dig_H2 = ReadReg16LE(BME280_REG_DIG_H2);
	dig_H3 = ReadReg8(BME280_REG_DIG_H3);
	dig_H4 = (ReadReg8(BME280_REG_DIG_H4) << 4) | (0x0F & ReadReg8(BME280_REG_DIG_H4 + 1));
	dig_H5 = (ReadReg8(BME280_REG_DIG_H5 + 1) << 4) | (0x0F & ReadReg8(BME280_REG_DIG_H5) >> 4);
	dig_H6 = (int8_t)ReadReg8(BME280_REG_DIG_H6);

	_Device->WriteRegByte(BME280_REG_CONTROLHUMID, 0x05);
	_Device->WriteRegByte(BME280_REG_CONTROL, 0xB7);
}

void GroveTempHumiBaroBME280::Read()
{
}
