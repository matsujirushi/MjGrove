//GROVE_NAME        "Grove - 16x2 LCD"
//SKU               104020111
//WIKI_URL          http://wiki.seeedstudio.com/Grove-16x2_LCD_Series/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorI2C.h"

class GroveLCD1602 : public GroveModule, public Print
{
private:
	HalI2CDevice* _LcdDevice;

	uint8_t _DisplayControl;
	uint8_t _DisplayMode;

	void LcdSendCommand(uint8_t command);

public:
	GroveLCD1602(GroveConnectorI2C* connector)
	{
		_LcdDevice = connector->NewDevice(0x7c >> 1);
	}

	void Init();
	void Clear();
	void Display(bool on);
	void SetCursor(uint8_t col, uint8_t row);

	virtual size_t write(uint8_t val);

};
