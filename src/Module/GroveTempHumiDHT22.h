//GROVE_NAME        "Grove - Temperature & Humidity Sensor Pro (AM2302/DHT22)"
//SKU               101020019
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Temperature_and_Humidity_Sensor_Pro/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorDIO.h"

class GroveTempHumiDHT22 : public GroveModule
{
private:
	HalGpio* _Pin;

	static void DHT22Init(HalGpio* gpio);
	static void DHT22Start(HalGpio* gpio);
	static uint8_t DHT22ReadByte(HalGpio* gpio);
	static void DHT22Finish(HalGpio* gpio);
	static bool DHT22Check(const uint8_t* data, int dataSize);

public:
	float Temperature;
	float Humidity;

public:
	GroveTempHumiDHT22(GroveConnectorDIO* connector)
	{
		_Pin = &connector->P1;
	}

	GroveTempHumiDHT22(HalGpio* pin)
	{
		_Pin = pin;
	}

	void Init();
	void Read();

};
