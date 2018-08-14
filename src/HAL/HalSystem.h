#pragma once

#include <Arduino.h>

class HalSystem
{
public:
	HalSystem() = delete;

	static void DelayMs(int milliSeconds)
	{
		delay(milliSeconds);
	}

	static void DelayUs(int microSeconds)
	{
		delayMicroseconds(microSeconds);
	}

};