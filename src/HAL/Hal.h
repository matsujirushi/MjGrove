#pragma once

#if defined ARDUINO_ARCH_STM32

#include "HAL/Arduino/stm32/HalGpio.h"
#include "HAL/Arduino/stm32/HalAnalogIn.h"
#include "HAL/Arduino/stm32/HalI2C.h"
#include "HAL/Arduino/stm32/HalSystem.h"
#include "HAL/Arduino/stm32/HalUART.h"

#else

#error "This platform is not supported."

#endif

#include "HAL/HalI2CDevice.h"
