//GROVE_NAME        "Grove - Speech Recognizer"
//SKU               101020232
//WIKI_URL          http://wiki.seeedstudio.com/Grove-Speech_Recognizer/

#pragma once

#include "Abstract/GroveModule.h"
#include "../Connector/GroveConnectorUART.h"
//#include <string>	// TODO

class GroveSpeechRecognizer : public GroveModule
{
public:
	enum COMMAND_TYPE
	{
		UNKNOWN = 0,
		TURN_ON_THE_LIGHT = 1,
		TURN_OFF_THE_LIGHT,
		PLAY_MUSIC,
		PAUSE,
		NEXT,
		PREVIOUS,
		UP,
		DOWN,
		TURN_ON_THE_TV,
		TURN_OFF_THE_TV,
		INCREASE_TEMPERATURE,
		DECREASE_TEMPERATURE,
		WHATS_THE_TIME,
		OPEN_THE_DOOR,
		CLOSE_THE_DOOR,
		LEFT,
		RIGHT,
		STOP,
		START,
		MODE_1,
		MODE_2,
		GO,
	};

private:
	HalUART* _UART;
	void(*_CommandReceivedCallback)(COMMAND_TYPE command);

public:
	GroveSpeechRecognizer(GroveConnectorUART* connector)
	{
		_UART = &connector->UART;
		_CommandReceivedCallback = NULL;
	}

	void Init();
	void AttachCommandReceived(void(*callback)(COMMAND_TYPE command));
	void DoWork();

};
