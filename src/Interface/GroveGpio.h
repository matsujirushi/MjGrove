#pragma once

#if defined ARDUINO_STM32F4_WIO_GPS

#include <Arduino.h>

class GroveGpio
{
private:
	uint8_t _GpioPin;
	bool _GpioOutput;

public:
	enum ModeType
	{
		MODE_INPUT,
		MODE_OUTPUT,
	};

public:
	GroveGpio(int pin)
	{
		_GpioPin = pin;
	}

	void Enable()
	{
	}

	void SetMode(ModeType mode)
	{
		switch (mode)
		{
		case MODE_INPUT:
			pinMode(_GpioPin, INPUT);
			break;
		case MODE_OUTPUT:
			pinMode(_GpioPin, OUTPUT);
			break;
		}
	}

	void Write(bool on)
	{
		digitalWrite(_GpioPin, on ? HIGH : LOW);
		_GpioOutput = on;
	}

	bool Read() const
	{
		return digitalRead(_GpioPin) == HIGH;
	}

	bool ReadOutput() const
	{
		return _GpioOutput ? HIGH : LOW;
	}

};

#elif defined ARDUINO_WIO_3G

#include "../HAL/HalGpio.h"

class GroveGpio : private HalGpio
{
public:
	enum ModeType
	{
		MODE_INPUT,
		MODE_OUTPUT,
	};

public:
	GroveGpio(int pin) : HalGpio(pin)
	{
	}

	void Enable()
	{
		HalGpio::Enable();
	}

	void SetMode(ModeType mode)
	{
		switch (mode)
		{
		case MODE_INPUT:
			SetPullUpDown(HalGpio::PUPD_NO);
			HalGpio::SetMode(HalGpio::MODE_INPUT);
			break;
		case MODE_OUTPUT:
			SetPullUpDown(HalGpio::PUPD_NO);
			SetOutType(HalGpio::OUT_TYPE_PUSH_PULL);
			SetOutSpeed(HalGpio::OUT_SPEED_VERY_HIGH);
			HalGpio::SetMode(HalGpio::MODE_OUTPUT);
			break;
		}
	}

	void Write(bool on)
	{
		HalGpio::Write(on);
	}

	bool Read() const
	{
		return HalGpio::Read();
	}

	bool ReadOutput() const
	{
		return HalGpio::ReadOutput();
	}

};

#else
#error "This board is not supported."
#endif
