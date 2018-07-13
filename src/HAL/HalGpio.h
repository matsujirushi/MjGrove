#pragma once

#include <stm32f4xx_hal.h>

class HalGpio
{
private:
	static uint16_t _GpioInstance[];
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
	HalGpio(int pin);

	void SetPullUpDown(PullUpPullDownType pupd)
	{
		uint32_t temp = _GpioReg->PUPDR;
		temp &= ~(0x3u << (_GpioPos * 2));
		temp |= pupd << (_GpioPos * 2);
		_GpioReg->PUPDR = temp;
	}

	void SetOutType(OutTypeType outType)
	{
		uint32_t temp = _GpioReg->OTYPER;
		temp &= ~(0x1u << _GpioPos);
		temp |= outType << _GpioPos;
		_GpioReg->OTYPER = temp;
	}

	void SetOutSpeed(OutSpeedType outSpeed)
	{
		uint32_t temp = _GpioReg->OSPEEDR;
		temp &= ~(0x3u << (_GpioPos * 2));
		temp |= outSpeed << (_GpioPos * 2);
		_GpioReg->OSPEEDR = temp;
	}

	void SetMode(ModeType mode)
	{
		uint32_t temp = _GpioReg->MODER;
		temp &= ~(0x3u << (_GpioPos * 2));
		temp |= mode << (_GpioPos * 2);
		_GpioReg->MODER = temp;
	}

	void Write(bool on)
	{
		_GpioReg->BSRR = 1u << (on ? _GpioPos : _GpioPos + 16);
	}

	bool Read() const
	{
		return (_GpioReg->IDR & 1u << _GpioPos) != 0 ? true : false;
	}

	bool ReadOutput() const
	{
		return (_GpioReg->ODR & 1u << _GpioPos) != 0 ? true : false;
	}

};
