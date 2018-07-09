#pragma once

#include <stm32f4xx_hal.h>

class GroveGpio
{
private:
	GPIO_TypeDef* _GpioReg;
	uint16_t _GpioPos;

public:
	enum PullUpPullDownType
	{
		PUPD_NO   = 0x0u,
		PUPD_UP   = 0x1u,
		PUPD_DOWN = 0x2u,
	};
	enum OutTypeType
	{
		OUT_TYPE_PUSH_PULL  = 0x0u,
		OUT_TYPE_OPEN_DRAIN = 0x1u,
	};
	enum OutSpeedType
	{
		OUT_SPEED_LOW       = 0x0u,
		OUT_SPEED_MEDIUM    = 0x1u,
		OUT_SPEED_HIGH      = 0x2u,
		OUT_SPEED_VERY_HIGH = 0x3u,
	};
	enum ModeType
	{
		MODE_INPUT        = 0x0u,
		MODE_OUTPUT       = 0x1u,
		MODE_ALT_FUNCTION = 0x2u,
		MODE_ANALOG       = 0x3u,
	};

public:
	GroveGpio(int pin);

	void SetPullUpDown(PullUpPullDownType pupd);
	void SetOutType(OutTypeType outType);
	void SetOutSpeed(OutSpeedType outSpeed);
	void SetMode(ModeType mode);

	void Write(bool on)
	{
		_GpioReg->BSRR = 1u << (on ? _GpioPos : _GpioPos + 16);
	}

};
