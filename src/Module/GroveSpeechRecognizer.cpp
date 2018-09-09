#include "GroveSpeechRecognizer.h"

void GroveSpeechRecognizer::Init()
{
	_UART->SetMode(9600, 8, HalUART::PARITY_NONE, 1);
}

void GroveSpeechRecognizer::AttachMessageReceived(void(*callback)(const char* message))
{
	_MessageReceivedCallback = callback;
}

void GroveSpeechRecognizer::DoWork()
{
	if (_UART->Available() >= 1)
	{
		uint8_t cmd = _UART->Read();
		char str[3 + 1];
		sprintf(str, "%d", cmd);
		_MessageReceivedCallback(str);
	}
}
