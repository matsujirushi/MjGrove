//GROVE_NAME        "Grove - 3-Axis Digital Accelerometer(±1.5g)"
//SKU               101020039
//WIKI_URL          http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Accelerometer-1.5g/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorI2C.h"

#define MMA7660_ADDR  0x4c

#define MMA7660_X     0x00
#define MMA7660_Y     0x01
#define MMA7660_Z     0x02
#define MMA7660_TILT  0x03
#define MMA7660_SRST  0x04
#define MMA7660_SPCNT 0x05
#define MMA7660_INTSU 0x06

#define MMA7660_SHINTX 0x80
#define MMA7660_SHINTY 0x40
#define MMA7660_SHINTZ 0x20
#define MMA7660_GINT   0x10
#define MMA7660_ASINT  0x08
#define MMA7660_PDINT  0x04
#define MMA7660_PLINT  0x02
#define MMA7660_FBINT  0x01

#define MMA7660_MODE     0x07
#define MMA7660_STAND_BY 0x00
#define MMA7660_ACTIVE   0x01

#define MMA7660_SR 0x08 // sample rate register

#define AUTO_SLEEP_120  0x00 // 120 sample per second
#define AUTO_SLEEP_64   0x01
#define AUTO_SLEEP_32   0x02
#define AUTO_SLEEP_16   0x03
#define AUTO_SLEEP_8    0x04
#define AUTO_SLEEP_4    0x05
#define AUTO_SLEEP_2    0x06
#define AUTO_SLEEP_1    0x07

#define MMA7660_PDET  0x09
#define MMA7660_PD    0x0A

struct MMA7660_LOOKUP {
  float g;
  float xyAngle;
  float zAngle;
};

class GroveAccelerometer015G : public GroveModule
{
private:
	HalI2CDevice* _Device;
	void _initAccelTable();
	MMA7660_LOOKUP accLookup[64];

public:
	float X;
	float Y;
	float Z;
	MMA7660_LOOKUP LOOKUP_X;
	MMA7660_LOOKUP LOOKUP_Y;
	MMA7660_LOOKUP LOOKUP_Z;
	uint8_t RAW_X;
  	uint8_t RAW_Y;
  	uint8_t RAW_Z;
  	uint8_t TILT;
  	uint8_t SRST;
  	uint8_t SPCNT;
  	uint8_t INTSU;
  	uint8_t MODE;
  	uint8_t SR;
  	uint8_t PDET;
  	uint8_t PD;

public:
	GroveAccelerometer015G(GroveConnectorI2C* connector)
	{
		_Device = connector->NewDevice(MMA7660_ADDR);	// I2C_ADDRESS
	}

	void Init();
	void Init(uint8_t interrupts);
	void Read();
	void setMode(uint8_t mode);
	void setSampleRate(uint8_t rate);
	//bool getAcceleration(MMA7660_ACC_DATA *data); // lookup the acceleration from the lookup table from this chip's datasheet
};
