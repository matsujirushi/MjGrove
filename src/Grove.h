#pragma once

#if defined ARDUINO_STM32F4_WIO_GPS
#include "Board/GroveBoardWioLTE.h"
#elif defined ARDUINO_WIO_3G
#include "Board/GroveBoardWio3G.h"
#else
#error "This board is not supported."
#endif

#include "Module/GroveBuzzer.h"
#include "Module/GroveButton.h"
#include "Module/GroveAccelerometer16G.h"
#include "Module/GroveTempHumiDHT11.h"
#include "Module/GroveMagneticSwitch.h"
#include "Module/GroveUltrasonicRanger.h"
