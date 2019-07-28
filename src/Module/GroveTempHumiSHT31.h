//GROVE_NAME        "Grove - Temperature&Humidity Sensor (SHT31)"
//SKU               101020212
//WIKI_URL          http://wiki.seeedstudio.com/Grove-TempAndHumi_Sensor-SHT31/

#pragma once

#include "Abstract/GroveTempHumiSHT3x.h"

class GroveTempHumiSHT31 : public GroveTempHumiSHT3x
{
public:
	GroveTempHumiSHT31(GroveConnectorI2C* connector) : GroveTempHumiSHT3x(connector, 0x44)
	{
	}

};
