#pragma once

#if defined ARDUINO_STM32F4_WIO_GPS
#include "Board/GroveBoardWioLTE.h"
#elif defined ARDUINO_WIO_3G
#include "Board/GroveBoardWio3G.h"
#elif defined ARDUINO_WIO_LTE_M1NB1_BG96
#include "Board/GroveBoardWioLTEM1NB1BG96.h"
#else
#error "This board is not supported."
#endif

#include "Module/GroveBuzzer.h"
#include "Module/GroveButton.h"
#include "Module/GroveAccelerometer16G.h"
#include "Module/GroveTempHumiDHT11.h"
#include "Module/GroveMagneticSwitch.h"
#include "Module/GroveUltrasonicRanger.h"
#include "Module/GroveGPS.h"
#include "Module/GroveRotaryAngle.h"
#include "Module/GroveOLEDDisplay096.h"
#include "Module/GroveTempHumiSHT31.h"
#include "Module/GroveHighTemp.h"
#include "Module/GroveTempOneWire.h"
#include "Module/GroveLEDBar2.h"
#include "Module/GroveTempHumiBaroBME280.h"
#include "Module/GroveCircularLED.h"
#include "Module/GroveEMGDetector.h"
#include "Module/GroveRelay.h"
#include "Module/Grove4DigitDisplay.h"
#include "Module/GroveDigitalLight.h"
#include "Module/GroveGasO2.h"
#include "Module/GroveTouch.h"
#include "Module/GroveMiniTrackBall.h"
