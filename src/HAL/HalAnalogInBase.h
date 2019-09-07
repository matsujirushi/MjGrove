#pragma once

class HalAnalogInBase
{
public:
	void Enable()
	{
		EnableImplement();
	}

	float Read()
	{
		return ReadImplement();
	}

protected:
	virtual void EnableImplement() = 0;
	virtual float ReadImplement() = 0;

public:
	virtual ~HalAnalogInBase() {}

};
