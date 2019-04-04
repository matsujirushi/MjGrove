#pragma once

#if defined ARDUINO_ARCH_STM32

#include "Arduino/stm32/HalGpioImpl.h"
#include "Arduino/stm32/HalI2CImpl.h"
#include "Arduino/stm32/HalAnalogInImpl.h"

#else

#error "This platform is not supported."

#endif

#include "HalI2CDevice.h"
