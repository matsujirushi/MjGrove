//GROVE_NAME        "Grove - I2C Color Sensor V2"
//SKU               101020341
//WIKI_URL          https://www.seeedstudio.com/Grove-I2C-Color-Sensor-V2-p-2890.html

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorI2C.h"

class GroveI2CColorSensor2 : public GroveModule
{
private:
	HalI2CDevice* _Device;

	void write8(uint8_t reg, uint8_t value);
	uint8_t read8(uint8_t reg);
	uint16_t read16(uint8_t reg);

	enum tcs34725IntegrationTime_t
	{
		TCS34725_INTEGRATIONTIME_2_4MS = 0xFF,	/**<  2.4ms - 1 cycle    - Max Count: 1024  */
		TCS34725_INTEGRATIONTIME_24MS  = 0xF6,  /**<  24ms  - 10 cycles  - Max Count: 10240 */
		TCS34725_INTEGRATIONTIME_50MS  = 0xEB,  /**<  50ms  - 20 cycles  - Max Count: 20480 */
		TCS34725_INTEGRATIONTIME_101MS = 0xD5,  /**<  101ms - 42 cycles  - Max Count: 43008 */
		TCS34725_INTEGRATIONTIME_154MS = 0xC0,  /**<  154ms - 64 cycles  - Max Count: 65535 */
		TCS34725_INTEGRATIONTIME_700MS = 0x00   /**<  700ms - 256 cycles - Max Count: 65535 */
	};

	enum tcs34725Gain_t
	{
		TCS34725_GAIN_1X  = 0x00,	/**<  No gain  */
		TCS34725_GAIN_4X  = 0x01,   /**<  4x gain  */
		TCS34725_GAIN_16X = 0x02,   /**<  16x gain */
		TCS34725_GAIN_60X = 0x03    /**<  60x gain */
	};

	void enable();
	void setIntegrationTime(tcs34725IntegrationTime_t it);
	void setGain(tcs34725Gain_t gain);
	void getRawData(uint16_t* r, uint16_t* g, uint16_t* b, uint16_t* c);

public:
	uint16_t R;
	uint16_t G;
	uint16_t B;
	uint16_t C;

public:
	GroveI2CColorSensor2(GroveConnectorI2C* connector)
	{
		_Device = connector->NewDevice(0x29);	// I2C_ADDRESS
	}

	void Init();
	void Read();

};
