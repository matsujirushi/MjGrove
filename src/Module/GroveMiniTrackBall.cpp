#include "GroveMiniTrackBall.h"
#include "../HAL/HalSystem.h"
#include <MjGrove.h>

#define READ_MODE	(0)
#define WRITE_MODE	(1)


enum MOTION_REG_ADDR
{
	MOTION_REG_UP = 0x00,
	MOTION_REG_DOWN,
	MOTION_REG_LEFT,
	MOTION_REG_RIGHT,
	MOTION_REG_CONFIRM,
	MOTION_REG_NUM
};

enum CONFIG_REG_ADDR
{
	CONFIG_REG_VALID = MOTION_REG_NUM,
	CONFIG_REG_I2C_ADDR = CONFIG_REG_VALID + 4,
	CONFIG_REG_I2C_SPEED,
	CONFIG_REG_LED_MODE = CONFIG_REG_I2C_SPEED + 2,
	CONFIG_REG_LED_FLASH_TIME,
	CONFIG_REG_DATA_CLEAR_TIME = CONFIG_REG_LED_FLASH_TIME + 2,  //CONFIG_REG_LED_FLASH_TIME has 2bytes
	CONFIG_REG_DATA_READ_TIME = CONFIG_REG_DATA_CLEAR_TIME + 2,
	CONFIG_REG_NUM = CONFIG_REG_DATA_READ_TIME + 2
};

enum LED_MODE
{
	LED_FLASH_1 = 0x00,
	LED_FLASH_2,
	LED_FLASH_TOGGLE,
	LED_FLASH_ALL,
	LED_ALWAYS_ON_1,
	LED_ALWAYS_ON_2,
	LED_ALWAYS_ON_ALL,
	LED_ALWAYS_OFF,
	LED_BREATHING_1,
	LED_BREATHING_2,
	LED_BREATHING_ALL,
	LED_MOVE_FLASH,
	LED_MODE_NUM
};

void GroveMiniTrackBall::WriteByte(uint8_t reg, uint8_t value)
{
	uint8_t data[3];
	data[0] = WRITE_MODE;
	data[1] = reg;
	data[2] = value;
	_Device->Write(data, sizeof(data));
}

uint8_t GroveMiniTrackBall::ReadByte(uint8_t reg)
{
	uint8_t data[3];
	data[0] = READ_MODE;
	data[1] = reg;
	data[2] = 1;
	_Device->Write(data, sizeof(data));

	_Device->Read(data, 1);
	
	return data[0];
}

void GroveMiniTrackBall::SetLedMode(uint8_t ledMode)
{
	WriteByte(CONFIG_REG_LED_MODE, ledMode);
}

void GroveMiniTrackBall::Init()
{
}

void GroveMiniTrackBall::Read()
{
	UpCount = ReadByte(MOTION_REG_UP);
	DownCount = ReadByte(MOTION_REG_DOWN);
	LeftCount = ReadByte(MOTION_REG_LEFT);
	RightCount = ReadByte(MOTION_REG_RIGHT);
	ConfirmCount = ReadByte(MOTION_REG_CONFIRM);

	PositionX += RightCount;
	PositionX -= LeftCount;
	PositionY += UpCount;
	PositionY -= DownCount;
}
