#include "GroveTempHumiDHT11.h"
#include <Arduino.h>

void GroveTempHumiDHT11::DHT11Init(GroveGpio* gpio)
{
	gpio->SetMode(GroveGpio::MODE_OUTPUT);
	gpio->Write(true);
}

void GroveTempHumiDHT11::DHT11Start(GroveGpio* gpio)
{
	// Host the start of signal
	gpio->Write(false);
	delay(18);

	// Pulled up to wait for
	gpio->SetMode(GroveGpio::MODE_INPUT);
	while (!gpio->Read());

	// Response signal
	while (gpio->Read());

	// Pulled ready to output
	while (!gpio->Read());
}

uint8_t GroveTempHumiDHT11::DHT11ReadByte(GroveGpio* gpio)
{
	uint8_t data = 0;

	for (int i = 0; i < 8; i++)
	{
		while (gpio->Read());

		while (!gpio->Read());
		unsigned long start = micros();

		while (gpio->Read());
		unsigned long finish = micros();

		if ((unsigned long)(finish - start) > 50) data |= 1 << (7 - i);
	}

	return data;
}

void GroveTempHumiDHT11::DHT11Finish(GroveGpio* gpio)
{
	// Releases the bus
	while (!gpio->Read());
	gpio->Write(true);
	gpio->SetMode(GroveGpio::MODE_OUTPUT);
}

bool GroveTempHumiDHT11::DHT11Check(const uint8_t* data, int dataSize)
{
	if (dataSize != 5) return false;

	uint8_t sum = 0;
	for (int i = 0; i < dataSize - 1; i++)
	{
		sum += data[i];
	}

	return data[dataSize - 1] == sum;
}

void GroveTempHumiDHT11::Init()
{
	DHT11Init(_Pin);
}

void GroveTempHumiDHT11::Read()
{
	uint8_t data[5];

	DHT11Start(_Pin);
	for (int i = 0; i < 5; i++) data[i] = DHT11ReadByte(_Pin);
	DHT11Finish(_Pin);

	if (!DHT11Check(data, sizeof(data))) throw "exception";
	if (data[1] >= 10) throw "exception";
	if (data[3] >= 10) throw "exception";

	Humidity = (float)data[0] + (float)data[1] / 10.0f;
	Temperature = (float)data[2] + (float)data[3] / 10.0f;
}
