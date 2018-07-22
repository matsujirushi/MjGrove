// BOARD Seeed Wio 3G
// GROVE I2C <-> Grove - 3-Axis Digital Accelerometer(±16g) (SKU#101020054)

#include <Grove.h>

#define INTERVAL    (100)

GroveBoard Board;
GroveUltrasonicRanger Ranger(&Board.D38);

void setup() {
  delay(200);
#if defined ARDUINO_WIO_3G
  SerialUSB.begin(115200);
#endif

  Board.D38.Enable();
  Ranger.Init();
}

void loop() {
  Ranger.Read();

  SerialUSB.println(Ranger.Distance);

  delay(INTERVAL);
}
