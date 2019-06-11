#include "GroveAccelerometer015G.h"
#include <math.h>

void GroveAccelerometer015G::Init()
{
	_initAccelTable();
    setMode(MMA7660_STAND_BY);
    setSampleRate(AUTO_SLEEP_32);
    setMode(MMA7660_ACTIVE);
}

void GroveAccelerometer015G::Init(uint8_t interrupts)
{
	_initAccelTable();
    setMode(MMA7660_STAND_BY);
    setSampleRate(AUTO_SLEEP_32);
    _Device->WriteReg8(MMA7660_INTSU, interrupts);
    setMode(MMA7660_ACTIVE);
}

void GroveAccelerometer015G::Read()
{
	uint8_t val[11] = {0};
	if (_Device->ReadRegN(MMA7660_X, val, sizeof(val)) != 11) HalSystem::Abort();

    RAW_X = val[0];
    RAW_Y = val[1];
    RAW_Z = val[2];
    TILT  = val[3];
    SRST  = val[4];
    SPCNT = val[5];
    INTSU = val[6];
    MODE  = val[7];
    SR    = val[8];
    PDET  = val[9];
    PD    = val[10];

    int8_t _x = ((int8_t)(RAW_X<<2))/4;
    int8_t _y = ((int8_t)(RAW_Y<<2))/4;
    int8_t _z = ((int8_t)(RAW_Z<<2))/4;
	X = _x / 21.00;
	Y = _y / 21.00;
	Z = _z / 21.00;

	LOOKUP_X = accLookup[RAW_X];
	LOOKUP_Y = accLookup[RAW_Y];
	LOOKUP_Z = accLookup[RAW_Z];
}

void GroveAccelerometer015G::_initAccelTable() {
    int i;
    float val, valZ;

    for (i = 0, val = 0; i < 32; i++) {
        accLookup[i].g = val;
        val += 0.047;
    }

    for (i = 63, val = -0.047; i > 31; i--) {
        accLookup[i].g = val;
        val -= 0.047;
    }

    for (i = 0, val = 0, valZ = 90; i < 22; i++) {
        accLookup[i].xyAngle = val;
        accLookup[i].zAngle = valZ;

        val += 2.69;
        valZ -= 2.69;
    }

    for (i = 63, val = -2.69, valZ = -87.31; i > 42; i--) {
        accLookup[i].xyAngle = val;
        accLookup[i].zAngle = valZ;

        val -= 2.69;
        valZ += 2.69;
    }

    for (i = 22; i < 43; i++) {
        accLookup[i].xyAngle = 255;
        accLookup[i].zAngle = 255;
    }
}

void GroveAccelerometer015G::setMode(uint8_t mode) {
	_Device->WriteReg8(MMA7660_MODE, mode);
}

void GroveAccelerometer015G::setSampleRate(uint8_t rate) {
    _Device->WriteReg8(MMA7660_SR, rate);
}