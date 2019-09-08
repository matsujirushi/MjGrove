#pragma once

#include <mbed.h>

class HalSystem
{
public:
	HalSystem() = delete;

	static void DelayMs(uint32_t milliSeconds)
	{
		wait_ms(milliSeconds);
	}

	static void DelayUs(uint32_t microSeconds)
	{
		wait_us(microSeconds);
	}

	static uint32_t ClockUs()
	{
		abort();	// TODO
	}

	static void Abort()
	{
		abort();
	}

};
