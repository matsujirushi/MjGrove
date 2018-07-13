#include "HalGpio.h"
#include <stm32f4xx_hal.h>
#include "HalRcc.h"

uint16_t HalGpio::_GpioInstance[] =
{
	0,	// GPIOA
	0,	// GPIOB
	0,	// GPIOC
	0,	// GPIOD
	0,	// GPIOE
	0,	// GPIOF
	0,	// GPIOG
	0,	// GPIOH
	0,	// GPIOI
	0,	// GPIOJ
	0,	// GPIOK
};

HalGpio::HalGpio(int pin)
{
	int port = pin / 16;
	int pos = pin % 16;
	if (port >= (int)(sizeof(_GpioInstance) / sizeof(_GpioInstance[0])))
	{
		throw "exception";
	}

	if ((_GpioInstance[port] & (1 << pos)) != 0)
	{
		throw "exception";
	}
	_GpioInstance[port] |= 1 << pos;

	HalRcc::AHB1_GPIOx_Enable(port);

	_GpioReg = (GPIO_TypeDef*)(AHB1PERIPH_BASE + 0x0400u * port);
	_GpioPos = pos;
}
