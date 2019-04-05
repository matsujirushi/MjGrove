#include "GroveSpeechRecognizer.h"

void GroveSpeechRecognizer::Init()
{
}

void GroveSpeechRecognizer::AttachCommandReceived(void(*callback)(COMMAND_TYPE command))
{
	_CommandReceivedCallback = callback;
}

void GroveSpeechRecognizer::DoWork()
{
	if (_UART->ReadAvailable() >= 1)
	{
		uint8_t cmd = _UART->Read();
		if (cmd < 1 || 22 < cmd) cmd = 0;
		_CommandReceivedCallback((COMMAND_TYPE)cmd);
	}
}
