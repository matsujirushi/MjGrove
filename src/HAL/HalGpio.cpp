#include "HalGpio.h"
#include <stm32f4xx_hal.h>
#include "HalRcc.h"

HalGpio::HalGpio(int pin)
{
	_GpioPort = pin / 16;
	_GpioPos = pin % 16;
	_GpioReg = (GPIO_TypeDef*)(AHB1PERIPH_BASE + 0x0400u * _GpioPort);
}

void HalGpio::Enable()
{
	HalRcc::AHB1_GPIOx_Enable(_GpioPort);
}
