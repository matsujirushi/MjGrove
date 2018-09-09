//GROVE_NAME        "Grove - Speech Recognizer"
//SKU               101020232
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Speech_Recognizer/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorUART.h"
#include <string>

class GroveSpeechRecognizer : public GroveModule
{
private:
	HalUART* _UART;
	void(*_MessageReceivedCallback)(const char* message);
	std::string _Message;

public:
	GroveSpeechRecognizer(GroveConnectorUART* connector)
	{
		_UART = &connector->UART;
		_MessageReceivedCallback = NULL;
		_Message.clear();
	}

	void Init();
	void AttachMessageReceived(void(*callback)(const char* message));
	void DoWork();

};
