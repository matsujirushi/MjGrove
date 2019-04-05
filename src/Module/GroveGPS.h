//GROVE_NAME        "Grove - GPS"
//SKU               113020003
//WIKI_URL          http://wiki.seeedstudio.com/Grove-GPS/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorUART.h"
//#include <string>	// TODO

class GroveGPS : public GroveModule
{
private:
	HalUART* _UART;
	void (*_MessageReceivedCallback)(const char* message);
	std::string _Message;

public:
	GroveGPS(GroveConnectorUART* connector)
	{
		_UART = &connector->UART;
		_MessageReceivedCallback = NULL;
		_Message.clear();
	}

	void Init();
	void AttachMessageReceived( void(*callback)(const char* message));
	void DoWork();

};
