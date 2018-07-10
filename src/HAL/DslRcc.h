#pragma once

#include <stm32f4xx_hal.h>

class DslRcc
{
public:
	DslRcc() = delete;

	static void AHB1_GPIOA_Enable()
	{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	}

	static void AHB1_GPIOB_Enable()
	{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	}

	static void AHB1_GPIOC_Enable()
	{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	}

	static void AHB1_GPIOD_Enable()
	{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	}

	static void AHB1_GPIOE_Enable()
	{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	}

	static void AHB1_GPIOF_Enable()
	{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
	}

	static void AHB1_GPIOG_Enable()
	{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	}

	static void AHB1_GPIOH_Enable()
	{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
	}

	static void AHB1_GPIOI_Enable()
	{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;
	}

	static void AHB1_GPIOJ_Enable()
	{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN;
	}

	static void AHB1_GPIOK_Enable()
	{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOKEN;
	}

	static void AHB1_GPIOA_Disable()
	{
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN;
	}

	static void AHB1_GPIOB_Disable()
	{
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN;
	}

	static void AHB1_GPIOC_Disable()
	{
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN;
	}

	static void AHB1_GPIOD_Disable()
	{
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIODEN;
	}

	static void AHB1_GPIOE_Disable()
	{
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOEEN;
	}

	static void AHB1_GPIOF_Disable()
	{
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOFEN;
	}

	static void AHB1_GPIOG_Disable()
	{
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOGEN;
	}

	static void AHB1_GPIOH_Disable()
	{
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOHEN;
	}

	static void AHB1_GPIOI_Disable()
	{
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOIEN;
	}

	static void AHB1_GPIOJ_Disable()
	{
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOJEN;
	}

	static void AHB1_GPIOK_Disable()
	{
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOKEN;
	}

};
