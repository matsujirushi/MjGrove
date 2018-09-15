// BOARD Seeed Wio 3G
// GROVE I2C <-> Grove - I2C Color Sensor V2 (SKU#101020341)

#include <MjGrove.h>

#define INTERVAL    (100)

WioCellular Wio;

GroveBoard Board;
GroveI2CColorSensor2 ColorSensor(&Board.I2C);

void setup() {
  delay(200);
#if !defined ARDUINO_STM32F4_WIO_GPS
  SerialUSB.begin(115200);
#endif

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.I2C.Enable();
  ColorSensor.Init();
}

void loop() {
  delay(INTERVAL);
}
