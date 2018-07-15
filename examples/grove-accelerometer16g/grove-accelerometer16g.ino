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

Wio3G Wio;
GroveBoard Board;
GroveI2CDevice* dev;

void setup() {
  delay(200);
  
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  WireI2C.begin();
  
  dev = Board.I2C.NewGroveI2CDevice(I2C_ADDRESS);
  
  uint8_t data[2];
  data[0] = REG_POWER_CTL;
  data[1] = 0x08;
  dev->Write(data, sizeof(data));
}

void loop() {
  uint8_t writeData[1];
  writeData[0] = REG_DATAX0;
  dev->Write(writeData, sizeof(writeData));

  uint8_t readData[6];
  if (dev->Read(readData, sizeof(readData)) == 6)
  {
    float x = (*(int16_t*)&readData[0]) * 2.0 / 512;
    float y = (*(int16_t*)&readData[2]) * 2.0 / 512;
    float z = (*(int16_t*)&readData[4]) * 2.0 / 512;
    SerialUSB.print(x);
    SerialUSB.print(' ');
    SerialUSB.print(y);
    SerialUSB.print(' ');
    SerialUSB.println(z);
  }

  delay(INTERVAL);
}
