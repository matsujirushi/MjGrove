#include "OmronBaro2SMPB02E.h"

#define REG_TEMP_TXD0		(0xfc)
#define REG_TEMP_TXD1		(0xfb)
#define REG_TEMP_TXD2		(0xfa)
#define REG_PRESS_TXD0		(0xf9)
#define REG_PRESS_TXD1		(0xf8)
#define REG_PRESS_TXD2		(0xf7)
#define REG_IO_SETUP		(0xf5)
#define REG_CTRL_MEAS		(0xf4)
#define REG_DEVICE_STAT		(0xf3)
#define REG_I2C_SET			(0xf2)
#define REG_IIR_CNT			(0xf1)
#define REG_RESET			(0xe0)
#define REG_CHIP_ID			(0xd1)
#define REG_COE_b00_a0_ex	(0xb8)
#define REG_COE_a2_0		(0xb7)
#define REG_COE_a2_1		(0xb6)
#define REG_COE_a1_0		(0xb5)
#define REG_COE_a1_1		(0xb4)
#define REG_COE_a0_0		(0xb3)
#define REG_COE_a0_1		(0xb2)
#define REG_COE_bp3_0		(0xb1)
#define REG_COE_bp3_1		(0xb0)
#define REG_COE_b21_0		(0xaf)
#define REG_COE_b21_1		(0xae)
#define REG_COE_b12_0		(0xad)
#define REG_COE_b12_1		(0xac)
#define REG_COE_bp2_0		(0xab)
#define REG_COE_bp2_1		(0xaa)
#define REG_COE_b11_0		(0xa9)
#define REG_COE_b11_1		(0xa8)
#define REG_COE_bp1_0		(0xa7)
#define REG_COE_bp1_1		(0xa6)
#define REG_COE_bt2_0		(0xa5)
#define REG_COE_bt2_1		(0xa4)
#define REG_COE_bt1_0		(0xa3)
#define REG_COE_bt1_1		(0xa2)
#define REG_COE_b00_0		(0xa1)
#define REG_COE_b00_1		(0xa0)

static int32_t TwosComplementValue(uint32_t data, int bits)
{
	uint32_t signBitMask = 1 << (bits - 1);
	return (data & (signBitMask - 1)) - (data & signBitMask);
}

static float CompensationCoefficientA(float a, float s, int otp)
{
	return a + s * otp / 32767;
}

static float CompensationCoefficientB(int otp)
{
	return otp / 16;
}

void OmronBaro2SMPB02E::Init()
{
	_Device->WriteReg8(REG_IO_SETUP, 0x00);
	HalSystem::DelayMs(500);

	uint8_t coe_a2[2];
	uint8_t coe_a1[2];
	uint8_t coe_a0[2];
	uint8_t coe_b00_a0_ex[1];
	if (_Device->ReadRegN(REG_COE_a2_1, coe_a2, sizeof(coe_a2)) != sizeof(coe_a2)) HalSystem::Abort();
	if (_Device->ReadRegN(REG_COE_a1_1, coe_a1, sizeof(coe_a1)) != sizeof(coe_a1)) HalSystem::Abort();
	if (_Device->ReadRegN(REG_COE_a0_1, coe_a0, sizeof(coe_a0)) != sizeof(coe_a0)) HalSystem::Abort();
	if (_Device->ReadRegN(REG_COE_b00_a0_ex, coe_b00_a0_ex, sizeof(coe_b00_a0_ex)) != sizeof(coe_b00_a0_ex)) HalSystem::Abort();
	_a2 = CompensationCoefficientA(-1.9E-11, 1.2E-10, TwosComplementValue((coe_a2[0] << 8) + coe_a2[1], 16));
	_a1 = CompensationCoefficientA(-6.3E-03, 4.3E-04, TwosComplementValue((coe_a1[0] << 8) + coe_a1[1], 16));
	_a0 = CompensationCoefficientB(TwosComplementValue((coe_a0[0] << 12) + (coe_a0[1] << 4) + (coe_b00_a0_ex[0] & 0x0f), 20));

	uint8_t coe_bp3[2];
	uint8_t coe_b21[2];
	uint8_t coe_b12[2];
	uint8_t coe_bp2[2];
	uint8_t coe_b11[2];
	uint8_t coe_bp1[2];
	uint8_t coe_bt2[2];
	uint8_t coe_bt1[2];
	uint8_t coe_b00[2];
	//uint8_t coe_b00_a0_ex[1];
	if (_Device->ReadRegN(REG_COE_bp3_1, coe_bp3, sizeof(coe_bp3)) != sizeof(coe_bp3)) HalSystem::Abort();
	if (_Device->ReadRegN(REG_COE_b21_1, coe_b21, sizeof(coe_b21)) != sizeof(coe_b21)) HalSystem::Abort();
	if (_Device->ReadRegN(REG_COE_b12_1, coe_b12, sizeof(coe_b12)) != sizeof(coe_b12)) HalSystem::Abort();
	if (_Device->ReadRegN(REG_COE_bp2_1, coe_bp2, sizeof(coe_bp2)) != sizeof(coe_bp2)) HalSystem::Abort();
	if (_Device->ReadRegN(REG_COE_b11_1, coe_b11, sizeof(coe_b11)) != sizeof(coe_b11)) HalSystem::Abort();
	if (_Device->ReadRegN(REG_COE_bp1_1, coe_bp1, sizeof(coe_bp1)) != sizeof(coe_bp1)) HalSystem::Abort();
	if (_Device->ReadRegN(REG_COE_bt2_1, coe_bt2, sizeof(coe_bt2)) != sizeof(coe_bt2)) HalSystem::Abort();
	if (_Device->ReadRegN(REG_COE_bt1_1, coe_bt1, sizeof(coe_bt1)) != sizeof(coe_bt1)) HalSystem::Abort();
	if (_Device->ReadRegN(REG_COE_b00_1, coe_b00, sizeof(coe_b00)) != sizeof(coe_b00)) HalSystem::Abort();
	//if (_Device->ReadRegN(REG_COE_b00_a0_ex, coe_b00_a0_ex, sizeof(coe_b00_a0_ex)) != sizeof(coe_b00_a0_ex)) HalSystem::Abort();
	_bp3 = CompensationCoefficientA(1.3E-16, 7.9E-17, TwosComplementValue((coe_bp3[0] << 8) + coe_bp3[1], 16));
	_b21 = CompensationCoefficientA(2.1E-15, 1.2E-14, TwosComplementValue((coe_b21[0] << 8) + coe_b21[1], 16));
	_b12 = CompensationCoefficientA(2.9E-13, 7.6E-13, TwosComplementValue((coe_b12[0] << 8) + coe_b12[1], 16));
	_bp2 = CompensationCoefficientA(-6.3E-10, 3.5E-10, TwosComplementValue((coe_bp2[0] << 8) + coe_bp2[1], 16));
	_b11 = CompensationCoefficientA(2.1E-07, 1.4E-07, TwosComplementValue((coe_b11[0] << 8) + coe_b11[1], 16));
	_bp1 = CompensationCoefficientA(3.3E-02, 1.9E-02, TwosComplementValue((coe_bp1[0] << 8) + coe_bp1[1], 16));
	_bt2 = CompensationCoefficientA(1.2E-08, 1.2E-06, TwosComplementValue((coe_bt2[0] << 8) + coe_bt2[1], 16));
	_bt1 = CompensationCoefficientA(1.0E-01, 9.1E-02, TwosComplementValue((coe_bt1[0] << 8) + coe_bt1[1], 16));
	_b00 = CompensationCoefficientB(TwosComplementValue((coe_b00[0] << 12) + (coe_b00[1] << 4) + ((coe_b00_a0_ex[0] >> 4) & 0x0f), 20));

	_Device->WriteReg8(REG_CTRL_MEAS, 0x27);
}

void OmronBaro2SMPB02E::Read()
{
	uint8_t press_and_temp[6];
	if (_Device->ReadRegN(REG_PRESS_TXD2, press_and_temp, sizeof(press_and_temp)) != sizeof(press_and_temp)) HalSystem::Abort();
	int dp = ((press_and_temp[0] << 16) + (press_and_temp[1] << 8) + press_and_temp[2]) - (1 << 23);
	int dt = ((press_and_temp[3] << 16) + (press_and_temp[4] << 8) + press_and_temp[5]) - (1 << 23);

	float tr = _a0 + _a1 * dt + _a2 * dt * dt;
	float pr = _b00 + _bt1 * tr + _bp1 * dp + _b11 * dp * tr + _bt2 * tr * tr + _bp2 * dp * dp
		+ _b12 * dp * tr * tr + _b21 * dp * dp * tr + _bp3 * dp * dp * dp;

	Temperature = tr / 256;
	Pressure = pr;
}
