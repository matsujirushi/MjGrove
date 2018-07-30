//GROVE_NAME        "Grove - OLED Display 0.96""
//SKU               104030008
//WIKI_URL          http://wiki.seeedstudio.com/Grove-OLED_Display_0.96inch/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorI2C.h"
#include <Arduino.h>

class GroveOLEDDisplay096 : public GroveModule, public Print
{
private:
	GroveI2CDevice* _Device;

	void SendCommand(uint8_t cmd);
	void SendData(uint8_t data);

	void SetHorizontalMode();
	void SetPageMode();

public:
	GroveOLEDDisplay096(GroveConnectorI2C* connector)
	{
		_Device = connector->NewGroveI2CDevice(0x3c);	// I2C_ADDRESS
	}

	void Init();
	void Clear();
	void SetTextPosition(int row, int column);
	void PrintBitmap(const uint8_t* bitmap, int bitmapSize);

	virtual size_t write(uint8_t val);

};
