#pragma once

#include <stm32f4xx_hal.h>

class HalRcc
{
public:
	HalRcc() = delete;

	static void AHB1_GPIOx_Enable(int port)
	{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN << port;
	}

	static void AHB1_GPIOA_Disable(int port)
	{
		RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOAEN << port);
	}

};
