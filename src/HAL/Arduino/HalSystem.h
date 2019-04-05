#pragma once

#include <Arduino.h>

class HalSystem
{
public:
	HalSystem() = delete;

	static void DelayMs(uint32_t milliSeconds)
	{
		delay(milliSeconds);
	}

	static void DelayUs(uint32_t microSeconds)
	{
		delayMicroseconds(microSeconds);
	}

	static uint32_t ClockMs()	// TODO
	{
		return millis();
	}

	static uint32_t ClockUs()	// TODO
	{
		return micros();
	}

	static void Abort()
	{
		abort();
	}

};
