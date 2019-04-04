#pragma once

#if defined ARDUINO_ARCH_STM32

#include "Arduino/stm32/HalGpioImpl.h"

#else

#error "This platform is not supported."

#endif
