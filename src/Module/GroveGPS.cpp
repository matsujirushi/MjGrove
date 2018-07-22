#include "GroveGPS.h"

#if defined ARDUINO_STM32F4_WIO_GPS
#include "Board/GroveBoardWioLTE.h"
#elif defined ARDUINO_WIO_3G
#include "Board/GroveBoardWio3G.h"
#else
#error "This board is not supported."
#endif

void GroveGPS::Init()
{
	_UART->SetMode(9600, 8, GroveUART::PARITY_NONE, 1);
}

void GroveGPS::DoWork()
{
	if (_UART->Available() >= 1)
	{
		SerialUSB.write(_UART->Read());
	}
}
