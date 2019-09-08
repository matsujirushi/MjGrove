#pragma once

#if defined ARDUINO_ARCH_STM32F4 || defined ARDUINO_ARCH_STM32

#define HalPlatformPinType	int
#define HalPlatformUartType	HardwareSerial
#define HalPlatformI2CType	TwoWire

#include "HAL/Arduino/HalGpio.h"
#include "HAL/Arduino/HalAnalogIn.h"
#include "HAL/Arduino/HalI2C.h"
#include "HAL/Arduino/HalUART.h"
#include "HAL/Arduino/HalSystem.h"

#elif defined __MBED__

#define HalPlatformPinType	PinName
#define HalPlatformUartType	RawSerial
#define HalPlatformI2CType	I2C

#include "HAL/Mbed/HalGpio.h"
#include "HAL/Mbed/HalAnalogIn.h"
#include "HAL/Mbed/HalI2C.h"
#include "HAL/Mbed/HalUART.h"
#include "HAL/Mbed/HalSystem.h"

#else

#error "This platform is not supported."

#endif

#include "HAL/HalI2CDevice.h"
