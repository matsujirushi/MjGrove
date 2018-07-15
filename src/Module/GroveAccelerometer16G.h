//GROVE_NAME        "Grove - 3-Axis Digital Accelerometer(Å}16g)"
//SKU               101020054
//WIKI_URL          http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Accelerometer-16g/

#pragma once

#include "../Connector/GroveConnectorI2C.h"

class GroveAccelerometer16G
{
private:
	GroveI2CDevice* _Device;

public:
	GroveAccelerometer16G(GroveConnectorI2C* connector);

	void Initialize();
	void ReadXYZ(float* x, float* y, float* z);

};
