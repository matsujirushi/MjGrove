#pragma once

#include "../HalAnalogInBase.h"
#include <mbed.h>

class HalAnalogIn : public HalAnalogInBase
{
private:
	PinName _Pin;
	AnalogIn* _In;

public:
	HalAnalogIn(PinName pin)
	{
		_Pin = pin;
		_In = NULL;
	}

	~HalAnalogIn()
	{
		if (_In != NULL) delete _In;
	}

protected:
	virtual void EnableImplement()
	{
		if (_In != NULL) delete _In;

		_In = new AnalogIn(_Pin);
	}

	virtual float ReadImplement()
	{
		return _In->read();
	}

};
