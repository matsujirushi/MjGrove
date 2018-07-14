#pragma once

#if defined ARDUINO_WIO_3G
#else
#error "This board is not supported."
#endif

#include "Connector/GroveConnectorDIO.h"

#include "Module/GroveBuzzer.h"
