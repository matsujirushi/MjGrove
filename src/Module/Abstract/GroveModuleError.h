#pragma once

#if defined ARDUINO_STM32F4_WIO_GPS
#define GROVE_MODULE_ERROR(message)	return
#elif defined ARDUINO_WIO_3G || defined ARDUINO_WIO_LTE_M1NB1_BG96
#define GROVE_MODULE_ERROR(message)	abort()
#else
#error "This board is not supported."
#endif
