#pragma once

class HalGpioBase
{
public:
	enum ModeType
	{
		MODE_UNKOWN,
		MODE_INPUT,
		MODE_OUTPUT,
		MODE_OUTPUT_OPEN_DRAIN,
	};

private:
	bool _Positive;
	ModeType _Mode;
	bool _Output;

public:
	HalGpioBase()
	{
		_Positive = true;
		_Mode = MODE_UNKOWN;
		_Output = false;
	}

	void SetInvert(bool on)
	{
		_Positive = !on;
	}

	bool GetInvert() const
	{
		return !_Positive;
	}

	void SetMode(ModeType mode)
	{
		SetModeImplement(mode);
		_Mode = mode;
	}

	ModeType GetMode() const
	{
		return _Mode;
	}

	virtual void Write(bool on)
	{
		WriteImplement(on == _Positive);
		_Output = on;
	}

	bool ReadOutput() const
	{
		return _Output;
	}

	virtual bool Read()
	{
		return ReadImplement() == _Positive;
	}

	virtual void SetModeImplement(ModeType mode) = 0;
	virtual void WriteImplement(bool high) = 0;
	virtual bool ReadImplement() const = 0;

};
