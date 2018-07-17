//GROVE_NAME        "Grove - Temperature & Humidity Sensor (DHT11)"
//SKU               101020011
//WIKI_URL          http://wiki.seeedstudio.com/Grove-TemperatureAndHumidity_Sensor/

#pragma once

#include "../Connector/GroveConnectorDIO.h"

class GroveTempHumiDHT11
{
private:
	GroveGpio* _Pin;

	static void DHT11Init(GroveGpio* gpio);
	static void DHT11Start(GroveGpio* gpio);
	static uint8_t DHT11ReadByte(GroveGpio* gpio);
	static void DHT11Finish(GroveGpio* gpio);
	static bool DHT11Check(const uint8_t* data, int dataSize);

public:
	float Temperature;
	float Humidity;

public:
	GroveTempHumiDHT11(GroveConnectorDIO* connector);

	void Read();

};
