#include "GroveGpio.h"

void GroveGpio::SetMode(GroveGpio::ModeType mode)
{
	switch (mode)
	{
	case MODE_INPUT:
		SetPullUpDown(HalGpio::PUPD_NO);
		HalGpio::SetMode(HalGpio::MODE_INPUT);
		break;
	case MODE_OUTPUT:
		SetPullUpDown(HalGpio::PUPD_NO);
		SetOutType(HalGpio::OUT_TYPE_PUSH_PULL);
		SetOutSpeed(HalGpio::OUT_SPEED_VERY_HIGH);
		HalGpio::SetMode(HalGpio::MODE_OUTPUT);
		break;
	}
}
