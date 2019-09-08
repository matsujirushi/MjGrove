#if defined ARDUINO_ARCH_STM32F4 || defined ARDUINO_ARCH_STM32

#include "GroveLCD1602.h"
#include "../HAL/Hal.h"

// Lcd commands
#define LCD_CLEARDISPLAY	0x01
#define LCD_ENTRYMODESET	0x04
#define LCD_DISPLAYCONTROL	0x08
#define LCD_FUNCTIONSET		0x20

// Lcd flags for display on/off control
#define LCD_DISPLAYON		0x04
#define LCD_DISPLAYOFF		0x00
#define LCD_CURSORON		0x02
#define LCD_CURSOROFF		0x00
#define LCD_BLINKON			0x01
#define LCD_BLINKOFF		0x00

// flags for display entry mode
#define LCD_ENTRYRIGHT			0x00
#define LCD_ENTRYLEFT			0x02
#define LCD_ENTRYSHIFTINCREMENT	0x01
#define LCD_ENTRYSHIFTDECREMENT	0x00

// Lcd flags for function set
#define LCD_2LINE			0x08

void GroveLCD1602::LcdSendCommand(uint8_t command)
{
	_LcdDevice->WriteReg8(0x80, command);
}

void GroveLCD1602::Init()
{
	uint8_t displayfunction = 0;

	displayfunction |= LCD_2LINE;
	_DisplayControl = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
	_DisplayMode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;

	delayMicroseconds(50000);
	LcdSendCommand(LCD_FUNCTIONSET | displayfunction);
	delayMicroseconds(4500);
	LcdSendCommand(LCD_FUNCTIONSET | displayfunction);
	delayMicroseconds(150);
	LcdSendCommand(LCD_FUNCTIONSET | displayfunction);
	LcdSendCommand(LCD_FUNCTIONSET | displayfunction);

	Display(true);
	Clear();
	LcdSendCommand(LCD_ENTRYMODESET | _DisplayMode);
}

void GroveLCD1602::Clear()
{
	LcdSendCommand(LCD_CLEARDISPLAY);
	delayMicroseconds(2000);
}

void GroveLCD1602::Display(bool on)
{
	if (on)
	{
		_DisplayControl |= LCD_DISPLAYON;
	}
	else
	{
		_DisplayControl &= ~LCD_DISPLAYON;
	}

	LcdSendCommand(LCD_DISPLAYCONTROL | _DisplayControl);
}

void GroveLCD1602::SetCursor(uint8_t col, uint8_t row)
{
	LcdSendCommand(row == 0 ? col | 0x80 : col | 0xc0);
}

size_t GroveLCD1602::write(uint8_t val)
{
	_LcdDevice->WriteReg8(0x40, val);
	return 1;
}

#endif // ARDUINO_ARCH_STM32F4 || ARDUINO_ARCH_STM32
