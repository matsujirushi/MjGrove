// BOARD Seeed Wio 3G
// GROVE I2C <-> Grove - Ultrasonic Ranger (SKU#101020010)

#include <MjGrove.h>

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
