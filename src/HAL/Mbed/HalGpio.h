#pragma once

#include "../HalGpioBase.h"
#include <mbed.h>

class HalGpio : public HalGpioBase
{
private:
	PinName _Pin;
	DigitalInOut* _InOut;

public:
	HalGpio(PinName pin)
	{
		_Pin = pin;
		_InOut = NULL;
	}

	~HalGpio()
	{
		if (_InOut != NULL) delete _InOut;
	}

protected:

	virtual void EnableImplement(ModeType mode)
	{
		if (_InOut != NULL) delete _InOut;

		switch (mode)
		{
		case MODE_INPUT:
			_InOut = new DigitalInOut(_Pin, PIN_INPUT, PullNone, 0);
			break;
		case MODE_OUTPUT:
			_InOut = new DigitalInOut(_Pin, PIN_OUTPUT, PullNone, 0);
			break;
		case MODE_OUTPUT_OPEN_DRAIN:
			_InOut = new DigitalInOut(_Pin, PIN_INPUT, OpenDrainNoPull, 0);
			break;
		default:
			abort();
		}
	}

	virtual void WriteImplement(bool high)
	{
		_InOut->write(high ? 1 : 0);
	}

	virtual bool ReadImplement() const
	{
		return _InOut->read() != 0 ? true : false;
	}

};
