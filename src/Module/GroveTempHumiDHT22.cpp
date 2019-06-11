#include "GroveTempHumiDHT22.h"
#include "../HAL/Hal.h"

void GroveTempHumiDHT22::DHT22Init(HalGpio* gpio)
{
	gpio->Enable(HalGpio::MODE_OUTPUT);
	gpio->Write(true);
}

void GroveTempHumiDHT22::DHT22Start(HalGpio* gpio)
{
	// Host the start of signal
	gpio->Write(false);
	HalSystem::DelayMs(18);

	// Pulled up to wait for
	gpio->Enable(HalGpio::MODE_INPUT);
	while (!gpio->Read());

	// Response signal
	while (gpio->Read());

	// Pulled ready to output
	while (!gpio->Read());
}

uint8_t GroveTempHumiDHT22::DHT22ReadByte(HalGpio* gpio)
{
	uint8_t data = 0;

	for (int i = 0; i < 8; i++)
	{
		while (gpio->Read());

		while (!gpio->Read());
		unsigned long start = HalSystem::ClockUs();

		while (gpio->Read());
		unsigned long finish = HalSystem::ClockUs();

		if ((unsigned long)(finish - start) > 50) data |= 1 << (7 - i);
	}

	return data;
}

void GroveTempHumiDHT22::DHT22Finish(HalGpio* gpio)
{
	// Releases the bus
	while (!gpio->Read());
	gpio->Write(true);
	gpio->Enable(HalGpio::MODE_OUTPUT);
}

bool GroveTempHumiDHT22::DHT22Check(const uint8_t* data, int dataSize)
{
	if (dataSize != 5) return false;

	uint8_t sum = 0;
	for (int i = 0; i < dataSize - 1; i++)
	{
		sum += data[i];
	}

	return data[dataSize - 1] == sum;
}

void GroveTempHumiDHT22::Init()
{
	DHT22Init(_Pin);
}

void GroveTempHumiDHT22::Read()
{
	uint8_t data[5];

	DHT22Start(_Pin);
	for (int i = 0; i < 5; i++) data[i] = DHT22ReadByte(_Pin);
	DHT22Finish(_Pin);

	if (!DHT22Check(data, sizeof(data))) HalSystem::Abort();

	Humidity = (float)(data[0] * 256 + data[1]) / 10.0f;
	Temperature = (float)((data[2] & 0x7f) * 256 + data[3]) / 10.0f;
	if (data[2] & 0x80) Temperature *= -1;
}
