#pragma once

#if defined ARDUINO_ARCH_STM32F4 || defined ARDUINO_ARCH_STM32

#include "HAL/Arduino/HalGpio.h"
#include "HAL/Arduino/HalAnalogIn.h"
#include "HAL/Arduino/HalI2C.h"
#include "HAL/Arduino/HalSystem.h"
#include "HAL/Arduino/HalUART.h"

#elif defined ARDUINO_ARCH_SEEEDJP_REBUTTON

#include "HAL/Arduino/HalGpio.h"
#include "HAL/Arduino/HalAnalogIn.h"
#include "HAL/Arduino/HalI2C.h"
#include "HAL/Arduino/HalSystem.h"
#include "HAL/Arduino/HalUART.h"

#else

#error "This platform is not supported."

#endif

#include "HAL/HalI2CDevice.h"
