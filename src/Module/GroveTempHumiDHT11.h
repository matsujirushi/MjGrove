//GROVE_NAME        "Grove - Temperature & Humidity Sensor (DHT11)"
//SKU               101020011
//WIKI_URL          http://wiki.seeedstudio.com/Grove-TemperatureAndHumidity_Sensor/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorDIO.h"

class GroveTempHumiDHT11 : public GroveModule
{
private:
	HalGpio* _Pin;

	static void DHT11Init(HalGpio* gpio);
	static void DHT11Start(HalGpio* gpio);
	static uint8_t DHT11ReadByte(HalGpio* gpio);
	static void DHT11Finish(HalGpio* gpio);
	static bool DHT11Check(const uint8_t* data, int dataSize);

public:
	float Temperature;
	float Humidity;

public:
	GroveTempHumiDHT11(GroveConnectorDIO* connector)
	{
		_Pin = &connector->P1;
	}

	GroveTempHumiDHT11(HalGpio* pin)
	{
		_Pin = pin;
	}

	void Init();
	void Read();

};
