//PRODUCT_NAME      "Wio Extension - RTC"
//SKU               103100082
//WIKI_URL          https://www.seeedstudio.com/Wio-Extension-RTC-p-4002.html

#pragma once

#include "../Connector/GroveConnectorI2C.h"

class WioExtRTC
{
public:
	class EEPROM
	{
	private:
		HalI2CDevice* _Device;

	public:
		EEPROM(GroveConnectorI2C* connector)
		{
			_Device = connector->NewDevice(0xa0 >> 1);	// 24C32
		}

		void Write(uint16_t address, const void* data, int dataSize);
		bool Read(uint16_t address, void* data, int dataSize);

	};

private:
	HalI2CDevice* _Device;

public:
	EEPROM Eeprom;

public:
	WioExtRTC(GroveConnectorI2C* connector) : Eeprom(connector)
	{
		_Device = connector->NewDevice(0xd0 >> 1);		// PCF8523
	}

	bool Init();
	bool SetWakeupPeriod(int sec);
	bool Shutdown();

};
