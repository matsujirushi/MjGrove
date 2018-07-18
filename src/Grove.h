#pragma once

#if defined ARDUINO_WIO_3G
#else
#error "This board is not supported."
#endif

#include "Board/GroveBoardWio3G.h"

#include "Module/GroveBuzzer.h"
#include "Module/GroveButton.h"
#include "Module/GroveAccelerometer16G.h"
#include "Module/GroveTempHumiDHT11.h"
