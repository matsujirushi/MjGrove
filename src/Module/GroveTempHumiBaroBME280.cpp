#include "GroveTempHumiBaroBME280.h"
#include "Abstract/GroveModuleError.h"

#define BME280_REG_CHIPID		(0xD0)
#define BME280_REG_CONTROLHUMID	(0xF2)
#define BME280_REG_CONTROL      (0xF4)
#define BME280_REG_PRESSUREDATA (0xF7)
#define BME280_REG_TEMPDATA     (0xFA)
#define BME280_REG_HUMIDITYDATA (0xFD)

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
	// Temperature

	int32_t t_fine;

	{
		int32_t adc_T = ReadReg24(BME280_REG_TEMPDATA);

		adc_T >>= 4;
		int32_t var1 = (((adc_T >> 3) - ((int32_t)(dig_T1 << 1))) * ((int32_t)dig_T2)) >> 11;
		int32_t var2 = (((((adc_T >> 4) - ((int32_t)dig_T1)) * ((adc_T >> 4) - ((int32_t)dig_T1))) >> 12) * ((int32_t)dig_T3)) >> 14;
		t_fine = var1 + var2;
		float T = (t_fine * 5 + 128) >> 8;
		Temperature = T / 100;
	}

	// Humidity

	{
		int32_t adc_H = ReadReg16(BME280_REG_HUMIDITYDATA);

		int32_t v_x1_u32r = (t_fine - ((int32_t)76800));
		v_x1_u32r = (((((adc_H << 14) - (((int32_t)dig_H4) << 20) - (((int32_t)dig_H5) * v_x1_u32r)) + ((int32_t)16384)) >> 15) * (((((((v_x1_u32r * ((int32_t)dig_H6)) >> 10) * (((v_x1_u32r * ((int32_t)dig_H3)) >> 11) + ((int32_t)32768))) >> 10) + ((int32_t)2097152)) * ((int32_t)dig_H2) + 8192) >> 14));
		v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) * ((int32_t)dig_H1)) >> 4));
		v_x1_u32r = (v_x1_u32r < 0 ? 0 : v_x1_u32r);
		v_x1_u32r = (v_x1_u32r > 419430400 ? 419430400 : v_x1_u32r);
		Humidity = (uint32_t)(v_x1_u32r >> 12) / 1024.0;
	}

	// Pressure

	{
		int32_t adc_P = ReadReg24(BME280_REG_PRESSUREDATA);

		adc_P >>= 4;
		int64_t var1 = ((int64_t)t_fine) - 128000;
		int64_t var2 = var1 * var1 * (int64_t)dig_P6;
		var2 = var2 + ((var1 * (int64_t)dig_P5) << 17);
		var2 = var2 + (((int64_t)dig_P4) << 35);
		var1 = ((var1 * var1 * (int64_t)dig_P3) >> 8) + ((var1 * (int64_t)dig_P2) << 12);
		var1 = (((((int64_t)1) << 47) + var1)) * ((int64_t)dig_P1) >> 33;
		if (var1 == 0)
		{
			Pressure = 0;	// avoid exception caused by division by zero
		}
		else
		{
			int64_t p = 1048576 - adc_P;
			p = (((p << 31) - var2) * 3125) / var1;
			var1 = (((int64_t)dig_P9) * (p >> 13) * (p >> 13)) >> 25;
			var2 = (((int64_t)dig_P8) * p) >> 19;
			p = ((p + var1 + var2) >> 8) + (((int64_t)dig_P7) << 4);
			Pressure = (uint32_t)p / 256;
		}
	}
}
