#include "GroveGPS.h"

void GroveGPS::Init()
{
	_UART->SetMode(9600, 8, HalUART::PARITY_NONE, 1);
}

void GroveGPS::AttachMessageReceived(void (*callback)(const char* message))
{
	_MessageReceivedCallback = callback;
}

void GroveGPS::DoWork()
{
	if (_UART->Available() >= 1)
	{
		char c = _UART->Read();
		switch (c)
		{
		case 13:
			break;
		case 10:
			if (_MessageReceivedCallback != NULL) _MessageReceivedCallback(_Message.c_str());
			_Message.clear();
			break;
		default:
			_Message.push_back(c);
			break;
		}
	}
}
