//GROVE_NAME        "One Wire Temperature Sensor"
//SKU               101990019
//WIKI_URL          

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorDIO.h"

class GroveTempOneWire : public GroveModule
{
private:
	GroveGpio * _Pin;

	void PinWrite(int value);
	int PinRead() const;

	bool WriteByte(uint8_t data);
	bool ReadByte(uint8_t* data);

	bool OneWireReset();
	bool OneWireSkipRom();
	bool OneWireWriteScratchpad(uint8_t th, uint8_t tl, uint8_t config);
	int OneWireReadScratchpad(uint8_t* data, int dataSize);
	bool OneWireConvertT();

public:
	float Temperature;

public:
	GroveTempOneWire(GroveConnectorDIO* connector)
	{
		_Pin = &connector->P1;
	}

	GroveTempOneWire(GroveGpio* pin)
	{
		_Pin = pin;
	}

	void Init();
	void Read();

};
