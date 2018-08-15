#include "GroveTempHumiDHT11.h"
#include "Abstract/GroveModuleError.h"
#include "../HAL/HalSystem.h"

void GroveTempHumiDHT11::DHT11Init(HalGpio* gpio)
{
	gpio->SetMode(HalGpio::MODE_OUTPUT);
	gpio->Write(true);
}

void GroveTempHumiDHT11::DHT11Start(HalGpio* gpio)
{
	// Host the start of signal
	gpio->Write(false);
	HalSystem::DelayMs(18);

	// Pulled up to wait for
	gpio->SetMode(HalGpio::MODE_INPUT);
	while (!gpio->Read());

	// Response signal
	while (gpio->Read());

	// Pulled ready to output
	while (!gpio->Read());
}

uint8_t GroveTempHumiDHT11::DHT11ReadByte(HalGpio* gpio)
{
	uint8_t data = 0;

	for (int i = 0; i < 8; i++)
	{
		while (gpio->Read());

		while (!gpio->Read());
		unsigned long start = HalSystem::ElapsedUs();

		while (gpio->Read());
		unsigned long finish = HalSystem::ElapsedUs();

		if ((unsigned long)(finish - start) > 50) data |= 1 << (7 - i);
	}

	return data;
}

void GroveTempHumiDHT11::DHT11Finish(HalGpio* gpio)
{
	// Releases the bus
	while (!gpio->Read());
	gpio->Write(true);
	gpio->SetMode(HalGpio::MODE_OUTPUT);
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

	if (!DHT11Check(data, sizeof(data)) || data[1] >= 10 || data[3] >= 10) GROVE_MODULE_ERROR("exception");

	Humidity = (float)data[0] + (float)data[1] / 10.0f;
	Temperature = (float)data[2] + (float)data[3] / 10.0f;
}
