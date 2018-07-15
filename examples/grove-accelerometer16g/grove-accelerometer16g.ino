// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove - 3-Axis Digital Accelerometer(±16g) (SKU#101020054)

#if defined ARDUINO_WIO_3G
#include <Wio3GforArduino.h>  // https://github.com/SeeedJP/Wio_3G_for_Arduino
#else
#error "This board is not supported."
#endif
#include <Grove.h>

#define INTERVAL    (100)

#define I2C_ADDRESS   (0x53)
#define REG_POWER_CTL (0x2d)
#define REG_DATAX0    (0x32)

GroveBoard Board;

void setup() {
  SerialUSB.begin(115200);

  WireI2C.begin();
  
  GroveI2CDevice* dev = Board.I2C.NewGroveI2CDevice(I2C_ADDRESS);
  
  uint8_t data[2];
  data[0] = REG_POWER_CTL;
  data[1] = 0x08;
  dev->Write(data, sizeof(data));
}

void loop() {
  delay(INTERVAL);
}

