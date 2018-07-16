// BOARD Seeed Wio 3G
// GROVE I2C <-> Grove - 3-Axis Digital Accelerometer(±16g) (SKU#101020054)

#if defined ARDUINO_WIO_3G
#include <Wio3GforArduino.h>  // https://github.com/SeeedJP/Wio_3G_for_Arduino
#else
#error "This board is not supported."
#endif
#include <Grove.h>

#define INTERVAL    (100)

Wio3G Wio;
GroveBoard Board;
GroveAccelerometer16G Accel(&Board.I2C);

void setup() {
  delay(200);
  
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  WireI2C.begin();
  Accel.Initialize();
}

void loop() {
  float x;
  float y;
  float z;
  Accel.ReadXYZ(&x, &y, &z);

  SerialUSB.print(x);
  SerialUSB.print(' ');
  SerialUSB.print(y);
  SerialUSB.print(' ');
  SerialUSB.println(z);

  delay(INTERVAL);
}
