#include "GroveHighTemp.h"
#include <math.h>

static const float Var_VtoT_K[3][10] =
{
	{ 0          , 2.5173462e1, -1.1662878    , -1.0833638     , -8.9773540 / 1e1, -3.7342377 / 1e1, -8.6632643 / 1e2, -1.0450598 / 1e2, -5.1920577 / 1e4 },
	{ 0          , 2.508355e1 , 7.860106 / 1e2, -2.503131 / 1e1, 8.315270 / 1e2  , -1.228034 / 1e2 , 9.804036 / 1e4  , -4.413030 / 1e5 , 1.057734 / 1e6  , -1.052755 / 1e8 },
	{ -1.318058e2, 4.830222e1 , -1.646031     , 5.464731 / 1e2 , -9.650715 / 1e4 , 8.802193 / 1e6  , -3.110810 / 1e8 }
};

float GroveHighTemp::ReadReferenceJunctionTemperature() const
{
	int v = _Pin2->Read();

	float resistance = (float)(_Pin2->MAX_VALUE - v) * 10000 / v;
	float temperature = 1 / (log(resistance / 10000) / 3975 + 1 / 298.15) - 273.15;	// TTC3A103*39H

	return temperature;
}

float GroveHighTemp::ReadThermocoupleTemperature() const
{
	float vout = (float)_Pin1->Read() * 3.3 / _Pin1->MAX_VALUE;
	float vin = (vout - 0.35) / 54.16;
	float mv = vin * 1000;

	float value;
	if (mv < -6.478)
	{
		return NAN;
	}
	else if (mv < 0)
	{
		value = Var_VtoT_K[0][8];

		for (int i = 8; i > 0; i--)
		{
			value = mv * value + Var_VtoT_K[0][i - 1];
		}
	}
	else if (mv < 20.644)
	{
		value = Var_VtoT_K[1][9];

		for (int i = 9; i > 0; i--)
		{
			value = mv * value + Var_VtoT_K[1][i - 1];
		}
	}
	else if (mv <= 54.900)
	{
		value = Var_VtoT_K[2][6];

		for (int i = 6; i > 0; i--)
		{
			value = mv * value + Var_VtoT_K[2][i - 1];
		}
	}
	else
	{
		return NAN;
	}

	return value;
}

void GroveHighTemp::Init()
{
}

void GroveHighTemp::Read()
{
	float tc = ReadThermocoupleTemperature();
	float rj = ReadReferenceJunctionTemperature();

	Temperature = tc == NAN ? NAN : tc + rj;
	if (tc == NAN)
	{
		Temperature = NAN;
	}
}
