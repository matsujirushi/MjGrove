#include "GroveGpio.h"

GroveGpio::GroveGpio(int pin)
{
	_GpioReg = (GPIO_TypeDef*)(AHB1PERIPH_BASE + 0x0400u * (pin / 16));
	_GpioPos = pin % 16;
}

void GroveGpio::SetPullUpDown(GroveGpio::PullUpPullDownType pupd)
{
	uint32_t temp = _GpioReg->PUPDR;
	temp &= ~(0x3u << (_GpioPos * 2));
	temp |=   pupd << (_GpioPos * 2) ;
	_GpioReg->PUPDR = temp;
}

void GroveGpio::SetOutType(GroveGpio::OutTypeType outType)
{
	uint32_t temp = _GpioReg->OTYPER;
	temp &= ~(0x1u    << _GpioPos);
	temp |=   outType << _GpioPos ;
	_GpioReg->OTYPER = temp;
}

void GroveGpio::SetOutSpeed(GroveGpio::OutSpeedType outSpeed)
{
	uint32_t temp = _GpioReg->OSPEEDR;
	temp &= ~(0x3u     << (_GpioPos * 2));
	temp |=   outSpeed << (_GpioPos * 2) ;
	_GpioReg->OSPEEDR = temp;
}

void GroveGpio::SetMode(GroveGpio::ModeType mode)
{
	uint32_t temp = _GpioReg->MODER;
	temp &= ~(0x3u << (_GpioPos * 2));
	temp |=   mode << (_GpioPos * 2) ;
	_GpioReg->MODER = temp;
}
