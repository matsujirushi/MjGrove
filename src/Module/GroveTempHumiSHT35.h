//GROVE_NAME        "Grove - I2C High Accuracy Temp&Humi Sensor (SHT35)"
//SKU               101020592
//WIKI_URL          http://wiki.seeedstudio.com/Grove-I2C_High_Accuracy_Temp%26Humi_Sensor-SHT35/

#pragma once

#include "Abstract/GroveTempHumiSHT3x.h"

class GroveTempHumiSHT35 : public GroveTempHumiSHT3x
{
public:
	GroveTempHumiSHT35(GroveConnectorI2C* connector) : GroveTempHumiSHT3x(connector, 0x45)
	{
	}

};
